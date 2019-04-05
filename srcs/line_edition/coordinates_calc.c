/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates_calc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 03:23:54 by roliveir          #+#    #+#             */
/*   Updated: 2019/04/05 18:57:37 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edition.h"
#include "libft.h"

static int	ft_getcor(t_env *env, int pos, int k)
{
	int		i;
	int		x;
	int		max;

	i = -1;
	max = 1;
	x = 0;
	while (++i < pos)
	{
		if (pos <= (int)ft_strlen(env->line)
				&& (env->line[i] == '\n' || max == env->cm->term_x))
		{
			max = 1;
			x = k ? 0 : x + 1;
		}
		else
		{
			max++;
			x = k ? x + 1 : x;
		}
	}
	return (x);
}

int			ft_getx(t_env *env, int pos)
{
	return (ft_getcor(env, pos, 1));
}

int			ft_gety(t_env *env, int pos)
{
	return (ft_getcor(env, pos, 0));
}


int			ft_get_termroom(t_env *env)
{
	return (env->cm->term_x * env->cm->term_y);
}

int			ft_get_origin_pos(t_env *env)
{
	int		len;
	int		room;

	len = (int)ft_strlen(env->line);
	room = ft_get_termroom(env) - env->cm->term_x + ft_getx(env, len) + 1;
	return (len - room + 1);
}
