/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_history.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 15:58:40 by roliveir          #+#    #+#             */
/*   Updated: 2019/05/20 13:31:15 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "line_edition.h"

static int			blt_lstlen(t_history *ry)
{
	int				lstlen;

	if (!ry)
		return (0);
	lstlen = 0;
	while (ry->next)
	{
		ry = ry->next;
		lstlen++;
	}
	return (lstlen);
}

static void			blt_print(t_history *ry, int i)
{
	if (ry->next)
		blt_print(ry->next, i - 1);
	if (ry->line)
	{
		ft_putnbr(i);
		ft_putstr("  ");
		ft_putendl(ry->line);
	}
}

int					blt_history(char **args, char ***env)
{
	t_history		*tmp;
	int				i;

	(void)args;
	(void)env;
	tmp = g_env.ry;
	if (!tmp)
		return (0);
	i = blt_lstlen(g_env.ry) + 1;
	blt_print(g_env.ry, i);
	return (1);
}
