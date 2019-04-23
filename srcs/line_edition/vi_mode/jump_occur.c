/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump_occur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 10:59:13 by roliveir          #+#    #+#             */
/*   Updated: 2019/04/23 11:33:53 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edition.h"

static void			ft_fjump(t_env *env, char c)
{
	int				i;

	i = env->cm->pos + 1;
	if (i > env->len)
		return ;
	while (env->line[i] && env->line[i] != c)
		i++;
	ft_cursor_motion(env, MRIGHT, i - env->cm->pos);	
}

static void			ft_bigfjump(t_env *env, char c)
{
	int				i;

	i = env->cm->pos - 1;
	while (i && env->line[i] != c)
		i--;
	if (i || env->line[0] == c)
		ft_cursor_motion(env, MLEFT, env->cm->pos - i);
}

static void			ft_tjump(t_env *env, char c)
{
	ft_cursor_motion(env, MRIGHT, 1);
	ft_fjump(env, c);
	ft_cursor_motion(env, MLEFT, 1);
}

static void			ft_bigtjump(t_env *env, char c)
{
	ft_cursor_motion(env, MLEFT, 1);
	ft_bigfjump(env, c);
	ft_cursor_motion(env, MRIGHT, 1);
}
void				ft_jump_occur(t_env *env, char c, int i, int count)
{
	while (--count + 1)
	{
		if (!i)
			ft_fjump(env, c);
		else if (i == 1)
			ft_bigfjump(env, c);
		else if (i == 2)
			ft_tjump(env, c);
		else if (i == 3)
			ft_bigtjump(env, c);
	}
}
