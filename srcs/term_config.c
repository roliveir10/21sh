/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 14:12:12 by roliveir          #+#    #+#             */
/*   Updated: 2019/04/07 21:45:53 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edition.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void				ft_switch_term(t_env *env, int reset)
{
	if (!env->tc->tc)
		return ;
	if ((tcgetattr(env->t_fd, &(env->term))) == -1)
		ft_errorterm(TBADFD, env);
	if (reset)
	{
		env->term.c_lflag |= (ECHO | ICANON);
		ft_reset_signal(1);
	}
	else
	{
		ft_signal_handler(1);
		env->term.c_lflag &= ~(ECHO | ICANON);
	}
	if ((tcsetattr(env->t_fd, TCSANOW, &(env->term))) == -1)
		ft_errorterm(TBADFD, env);
}

void				ft_errorterm(t_error error, t_env *env)
{
	ft_putstr_fd("21sh: error ID=", STDERR_FILENO);
	ft_putnbr_fd(error, STDERR_FILENO);
	ft_putstr_fd(" Exiting\n", STDERR_FILENO);
	if (error != TBADFD)
	{
		ft_switch_term(env, 1);
		close(env->t_fd);
	}
	ft_delenv(env);
	exit(error);
}

int					ft_quiterm(t_env *env)
{
	if (env->isatty)
	{
		ft_switch_term(env, 1);
		close(env->t_fd);
	}
	ft_delenv(env);
	exit(0);
}

static void			ft_initerm(t_env *env)
{
	int				ret;
	char			*type;

	type = getenv("TERM");
	if (type && (ret = tgetent(NULL, type)) < 1)
		env->tc->tc = 0;
	if ((env->t_fd = open(ttyname(STDIN_FILENO), O_RDWR)) < 0)
		ft_errorterm(TTTYNAME, env);
	if (tcgetattr(env->t_fd, &(env->term)) == -1)
		ft_errorterm(TBADFD, env);
	ft_update_termsize(env);
}

void				ft_configterm(t_env *env)
{
	if (isatty(STDIN_FILENO))
		env->isatty = 1;
	else
		return ;
	ft_initerm(env);
	if (!ft_addtermcaps(env->tc))
		env->tc->tc = 0;
	if (!env->tc->tc)
		return ;
	env->term.c_cc[VMIN] = 1;
	env->term.c_cc[VTIME] = 0;
	env->term.c_lflag &= ~(ICANON | ECHO);
	if ((tcsetattr(env->t_fd, TCSANOW, &(env->term))) == -1)
		ft_errorterm(TBADFD, env);
	ft_active_termcaps(env);
}
