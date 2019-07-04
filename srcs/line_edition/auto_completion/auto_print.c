/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 09:53:19 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/15 12:16:28 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edition.h"

static int			auto_printcomp(void)
{
	int				lenroot;

	g_data.status = 0;
	if (!g_data.lenlst)
	{
		auto_free();
		return (1);
	}
	lenroot = auto_lenrootwbs();
	line_paste(&(g_data.lw->name->name[lenroot]), 1);
	if (g_data.lw->type == 9 || g_data.lw->type == 14)
		line_paste("/", 1);
	else
		line_paste(" ", 1);
	auto_free();
	return (1);
}

static void			auto_printprint(void)
{
	int				i;

	i = -1;
	auto_print_select();
	auto_print_color();
	ft_putstr(g_data.lw->name->name);
	if (g_data.lw->name->desc)
		ft_putstr(g_data.lw->name->desc);
	tputs(g_env.tc->me, 1, ft_putchar);
	auto_print_select();
	if (g_data.lw->type != 7)
		ft_putchar(g_data.lw->carac);
	while (++i < g_data.lenmax - g_data.lw->len)
		ft_putchar(' ');
	tputs(g_env.tc->me, 1, ft_putchar);
	while (++i < g_data.lenmax + 3 - g_data.lw->len)
		ft_putchar(' ');
}

int					auto_printaligned(void)
{
	int				tmp_w;
	t_lstword		*tmp;

	if (g_data.y >= g_env.cm->term_y)
	{
		auto_free();
		return (-1);
	}
	tmp = g_data.lw;
	g_data.status = g_data.status ? g_data.status : 1;
	tmp_w = g_data.wordpline;
	ft_putchar('\n');
	while (g_data.lw)
	{
		auto_printprint();
		tmp_w--;
		if (tmp_w < 1 && g_data.lw->next)
		{
			tmp_w = g_data.wordpline;
			ft_putchar('\n');
		}
		g_data.lw = g_data.lw->next;
	}
	g_data.lw = tmp;
	return (1);
}

int					auto_printword(void)
{
	DIR				*dir;
	struct dirent	*dt;
	int				i;

	i = -1;
	while (g_data.type < 2 && g_data.path[++i])
	{
		if (!(dir = opendir(g_data.path[i])))
			break ;
		while ((dt = readdir(dir)))
			auto_lstmanager(dt, i);
		(void)closedir(dir);
	}
	auto_printoption();
	auto_sort();
	auto_calclen();
	return (g_data.lenlst < 2 ? auto_printcomp() : 1);
}
