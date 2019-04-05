/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 21:28:08 by roliveir          #+#    #+#             */
/*   Updated: 2019/04/04 14:01:39 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "line_edition.h"
#include <unistd.h>
#include "printf.h"
#include <fcntl.h>

static int			ft_read_isnotatty(t_env *env)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	char			*tmp;

	if (env->isatty)
		return (0);
	if (!(env->line = ft_strnew(1)))
		ft_errorterm(TMALLOC, env);
	while ((ret = read(STDIN_FILENO, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(tmp = ft_strjoinf(env->line, buf)))
			ft_errorterm(TMALLOC, env);
		env->line = tmp;
	}
	return (1);
}

static int			ft_read_isatty(t_env *env)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;

	if ((ret = read(STDIN_FILENO, buf, sizeof(buf))) > 0 && !env->sigc)
	{
		buf[ret] = '\0';
		if (!ft_update_line(env, buf, ret))
			return (0);
	}
	if (env->sigc)
		return (0);
	return (1);
}

static int			ft_read_isarg(t_env *env, char *argv)
{
	int				fd;
	int				ret;
	char			buf[BUFF_SIZE + 1];
	char			*tmp;

	env->isatty = 0;
	if (!(env->line = ft_strnew(1)))
		ft_errorterm(TMALLOC, env);
	if ((fd = open(argv, O_RDONLY)) < 1)
	{
		ft_printf("21sh: cannot open %s\n", argv);
		ft_quiterm(env);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(tmp = ft_strjoinf(env->line, buf)))
			ft_errorterm(TMALLOC, env);
		env->line = tmp;
	}
	return (1);
}

static void			ft_endofread(t_env *env)
{
	ft_reset_history(env);
	ft_strdel(&(env->oldline));
}

int					ft_reader(t_env *env, char *argv)
{
	if (ft_read_isnotatty(env))
		return (1);
	if (argv && ft_read_isarg(env, argv))
		return (1);
	ft_putstr(env->line);
	if (!(env->oldline = ft_strdup(env->line)))
		ft_errorterm(TMALLOC, env);
	while (1)
	{
		if (!ft_read_isatty(env))
			break ;
	}
	if (env->sigc)
	{
		env->sigc = 0;
		return (0);
	}
	ft_putchar('\n');
	ft_endofread(env);
	return (1);
}
