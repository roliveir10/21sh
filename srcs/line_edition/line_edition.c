/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_edition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 22:59:54 by roliveir          #+#    #+#             */
/*   Updated: 2019/05/04 16:36:26 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edition.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>

void				line_update_termsize(void)
{
	struct winsize	w;

	if (ioctl(STDIN_FILENO, TIOCGWINSZ, &w) == -1)
		sh_errorterm(TIOCTL);
	g_env.cm->term_x = w.ws_col;
	g_env.cm->term_y = w.ws_row;
}

void				line_clear(void)
{
	int				i;

	i = -1;
	while (++i < g_env.cm->tmpy)
		tputs(g_env.tc->up, 1, ft_putchar);
	tputs(g_env.tc->cd, 1, ft_putchar);
	tputs(g_env.tc->cr, 1, ft_putchar);
	tputs(g_env.tc->dl, 1, ft_putchar);
}

void				line_paste(char *str, int count)
{
	int				tmp;

	tmp = count + 1;
	if (!str)
		return ;
	while (--tmp)
		g_env.line = line_addstr(str);
	line_reset_history();
	ft_strdel(&g_env.oldline);
	if (!(g_env.oldline = ft_strdup(g_env.line)))
		sh_errorterm(TMALLOC);
	line_cursor_motion(MRIGHT, (int)ft_strlen(str) * count);
}

static int			line_choose_mode(char *str, int ret)
{
	int				cap;

	if (g_env.mode->n_select)
		cap = line_cpy(str, ret);
	else if (g_env.mode->mode[MVI])
		cap = line_vi(str, ret);
	else
		cap = line_manager(str, ret);
	return (cap);
}

int					line_update(char *str, int ret)
{
	int				cap;

	if (!str)
		return (0);
	vi_init_undo();
	g_env.len = (int)ft_strlen(g_env.line) + 1;
	cap = line_choose_mode(str, ret);
	g_env.len = (int)ft_strlen(g_env.line);
	line_clear();
	line_print();
	line_reset_cursor();
	g_env.cm->tmpy = line_gety(g_env.cm->pos);
	return (cap);
}
