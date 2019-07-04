/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 02:00:25 by roliveir          #+#    #+#             */
/*   Updated: 2019/07/03 16:15:05 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edition.h"

static void			line_newline(void)
{
	int				i;

	i = 0;
	if (!g_env.tc->tc)
		return ;
	tputs(g_env.tc->mr, 1, ft_putchar);
	ft_putchar('%');
	tputs(g_env.tc->me, 1, ft_putchar);
	while (++i < g_env.cm->term_x)
		ft_putchar(' ');
	tputs(g_env.tc->cr, 1, ft_putchar);
	tputs(g_env.tc->dl, 1, ft_putchar);
}

static void			line_setprompt(t_prompt prompt)
{
	line_newline();
	if (!(g_env.line = line_get_prompt(prompt)))
		sh_errorterm(TMALLOC);
	g_env.cm->pos = prompt;
	g_env.p_size = prompt;
	g_env.prompt = prompt;
	g_env.len = prompt;
}

static char			*line_cut(t_prompt prompt)
{
	char			*tmp;

	if (!(tmp = ft_strdup(g_env.line + prompt)))
		sh_errorterm(TMALLOC);
	ft_strdel(&g_env.line);
	g_env.line = tmp;
	return (tmp);
}

void				sh_term_manager(void)
{
	t_tc			*tc;
	t_cm			*cm;
	t_mode			*mode;

	tc = (t_tc*)ft_memalloc(sizeof(t_tc));
	cm = (t_cm*)ft_memalloc(sizeof(t_cm));
	mode = (t_mode*)ft_memalloc(sizeof(t_mode));
	if (!tc || !cm || !mode)
		sh_errorterm(TMALLOC);
	g_env.ry = NULL;
	g_env.tc = tc;
	g_env.tc->tc = 1;
	g_env.cm = cm;
	g_env.mode = mode;
	g_env.mode->mode[0] = 1;
	sh_configterm();
}

char				*line_get_readline(t_prompt prompt)
{
	int			ret;

	(void)prompt;
	ret = 0;
	if (g_env.isatty)
		sh_switch_term(0);
	g_env.ctrld = 0;
	g_env.tc->tc = 1;
	if (!caps_check_termcaps(*g_env.tc))
		g_env.tc->tc = 0;
	while (!ret)
	{
		if (g_env.isatty)
			line_setprompt(prompt);
		ret = line_reader();
	}
	if (g_env.isatty)
	{
		sh_switch_term(1);
		return (line_cut(prompt));
	}
	return (g_env.line);
}
