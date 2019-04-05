/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_edition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 22:59:54 by roliveir          #+#    #+#             */
/*   Updated: 2019/04/05 18:42:05 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edition.h"
#include <stdlib.h>
#include "libft.h"
#include <unistd.h>
#include <sys/ioctl.h>

void				ft_update_termsize(t_env *env)
{
	struct winsize	w;

	if (ioctl(STDIN_FILENO, TIOCGWINSZ, &w) == -1)
		ft_errorterm(TIOCTL, env);
	env->cm->term_x = w.ws_col;
	env->cm->term_y = w.ws_row;
}

void				ft_clear_line(t_env *env)
{
	int				i;

	i = -1;
	while (++i < ft_gety(env, env->cm->old_pos))
		tputs(env->tc->up, 1, ft_putchar);
	tputs(env->tc->cr, 1, ft_putchar);
	tputs(env->tc->cd, 1, ft_putchar);
}

void				ft_paste(t_env *env, char *str)
{
	if (!str)
		return ;
	env->line = ft_addstr(env, str);
	ft_reset_history(env);
	ft_strdel(&env->oldline);
	if (!(env->oldline = ft_strdup(env->line)))
		ft_errorterm(TMALLOC, env);
	ft_cursor_motion(env, MRIGHT, (int)ft_strlen(str));
}

int					ft_update_line(t_env *env, char *str, int ret)
{
	int				cap;
	int				i;
	int				len;

	i = -1;
	if (!str)
		return (0);
	if (env->select)
		cap = ft_line_cpy(env, str, ret);
	else
		cap = ft_line_manager(env, str, ret);
	len = (int)ft_strlen(env->line);
	ft_clear_line(env);
	ft_print_line(env);
	ft_reset_cursor(env);
	env->cm->old_pos = env->cm->pos;
	return (cap);
}
