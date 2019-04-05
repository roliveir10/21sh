/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:53:55 by roliveir          #+#    #+#             */
/*   Updated: 2019/04/04 13:53:59 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edition.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include <sys/ioctl.h>

t_env				*signal_saved(t_env *env)
{
	static t_env	*save = NULL;

	if (env)
		save = env;
	return (save);
}

void				ft_sigint(void)
{
	t_env			*env;

	env = signal_saved(NULL);
	env->sigc = 1;
	ft_end(env);
	ft_putchar('\n');
	ioctl(0, TIOCSTI, "^D");
}

void				ft_sigwinch(void)
{
	t_env			*env;
	int				len;

	env = signal_saved(NULL);
	len = (int)ft_strlen(env->line);
	ft_update_termsize(env);
	ft_clear_line(env);
	ft_putstr(env->line);
	ft_reset_cursor(env);
}

void				ft_sigsusp(void)
{
	t_env			*env;
	char			cmd[2];
	int				i;

	i = 0;
	env = signal_saved(NULL);
	env->term.c_lflag |= (ICANON | ECHO);
	if (tcsetattr(env->t_fd, TCSANOW, &(env->term)) < 0)
		ft_errorterm(TBADFD, env);
	cmd[0] = env->term.c_cc[VSUSP];
	cmd[1] = '\0';
	while (i < 32)
	{
		if (i == SIGINT || i == SIGWINCH || i == SIGTSTP)
			signal(i, SIG_DFL);
		i++;
	}
	ioctl(STDIN_FILENO, TIOCSTI, cmd);
}

void				ft_sigcont(void)
{
	t_env			*env;

	env = signal_saved(NULL);
	env->term.c_lflag &= ~(ICANON | ECHO);
	env->term.c_cc[VMIN] = 1;
	env->term.c_cc[VTIME] = 0;
	if (tcsetattr(env->t_fd, TCSANOW, &(env->term)) < 0)
		ft_errorterm(TBADFD, env);
	ft_signal_handler(1);
	ft_putstr(env->line);
}
