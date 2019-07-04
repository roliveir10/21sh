/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_jumpwords.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 03:54:03 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/11 17:19:44 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edition.h"

void				line_lbjump(void)
{
	int				i;
	int				count;

	count = g_env.count + 1;
	while (--count)
	{
		i = g_env.cm->pos - 1;
		while (i && (g_env.line[i] == ' ' || g_env.line[i] == '\n'))
			i--;
		while (i && g_env.line[i] != ' ' && g_env.line[i] != '\n')
			i--;
		if (g_env.line[i + 1])
			line_cursor_motion(MLEFT, g_env.cm->pos - i - 1);
	}
}

void				line_ljump(void)
{
	int				i;
	int				count;

	count = g_env.count + 1;
	while (--count)
	{
		i = g_env.cm->pos - 1;
		while (i && ft_strchr(" \n", g_env.line[i]))
			i--;
		if (i && !line_isword(g_env.line[i]))
			while (i && !line_isword(g_env.line[i]))
				i--;
		else
			while (i && line_isword(g_env.line[i]))
				i--;
		if (g_env.line[i + 1])
			line_cursor_motion(MLEFT, g_env.cm->pos - i - 1);
	}
}

void				line_rbjump(void)
{
	int				i;
	int				count;

	count = g_env.count + 1;
	while (--count)
	{
		i = g_env.cm->pos;
		while (g_env.line[i] && !ft_strchr(" \n", g_env.line[i]))
			i++;
		while (g_env.line[i] && ft_strchr(" \n", g_env.line[i]))
			i++;
		line_cursor_motion(MRIGHT, i - g_env.cm->pos);
	}
}

void				line_rjump(void)
{
	int				i;
	int				count;

	count = g_env.count + 1;
	while (--count)
	{
		i = g_env.cm->pos;
		if (g_env.line[i] && !line_isword(g_env.line[i]))
			while (g_env.line[i] && !line_isword(g_env.line[i]))
				i++;
		else
			while (g_env.line[i] && line_isword(g_env.line[i]))
				i++;
		while (g_env.line[i] && ft_strchr(" \n", g_env.line[i]))
			i++;
		line_cursor_motion(MRIGHT, i - g_env.cm->pos);
	}
}
