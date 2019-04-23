/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 19:54:00 by roliveir          #+#    #+#             */
/*   Updated: 2019/04/23 20:27:18 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edition.h"

static void		ft_delall_line(t_env *env)
{
	env->mode->v_pos = env->len;
	ft_home(env, 1);
	ft_cdel(env);
}

static int		ft_vi_delete2(t_env *env, char *str, int ret)
{
	if (str[0] == 'S' && ret == 1)
	{
		env->mode->v_del++;
		ft_delall_line(env);
	}
	else if (str[0] == 'x' && ret == 1)
		env->line = ft_delchar_bs(env, env->mode->v_count);
	else if (str[0] == 'X' && ret == 1)
	{
		env->line = ft_delchar(env, env->mode->v_count);
		ft_cursor_motion(env, MLEFT, env->mode->v_count);
	}
	else
		return (0);
	ft_reset_count(env, str);
	return (1);
}

int				ft_vi_delete(t_env *env, char *str, int ret)
{
	if ((str[0] == 'c' || str[0] == 'd') && ret == 1)
	{
		env->mode->v_del++;
		env->mode->v_pos = env->cm->pos;
		if (env->mode->v_del == 2)
			ft_delall_line(env);
	}
	else if ((str[0] == 'C' || str[0] == 'D') && ret == 1)
	{
		env->mode->v_pos = env->cm->pos;
		ft_end(env);
		ft_cdel(env);
	}
	else if (!env->mode->v_del)
		return (ft_vi_delete2(env, str, ret));
	ft_reset_count(env, str);
	return (1);
}
