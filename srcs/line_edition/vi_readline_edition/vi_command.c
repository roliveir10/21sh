/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:46:23 by roliveir          #+#    #+#             */
/*   Updated: 2019/04/11 19:37:20 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edition.h"
#include "libft.h"

static int			ft_vi_moving(t_env *env, char *str, int ret)
{
	if (str[0] == 'j' && ret == 1)
		ft_get_dhistory(env, env->mode->v_count);
	else if (str[0] == 'k' && ret == 1)
		ft_get_uhistory(env, env->mode->v_count);
	else if (str[0] == 'h' && ret == 1)
		ft_cursor_motion(env, MLEFT, env->mode->v_count);
	else if (str[0] == 'l' && ret == 1)
		ft_cursor_motion(env, MRIGHT, env->mode->v_count);
	else if (str[0] == 'w' && ret == 1)
		ft_wjump(env, env->mode->v_count);
	else if (str[0] == 'W' && ret == 1)
		ft_bigwjump(env, env->mode->v_count);
	else if (str[0] == 'e' && ret == 1)
		ft_ejump(env, env->mode->v_count);
	else if (str[0] == 'E' && ret == 1)
		ft_bigejump(env, env->mode->v_count);
	ft_reset_count(env, str);
	return (1);
}

int				ft_vi_command(t_env *env, char *str, int ret)
{
	ft_get_count(env, str);
	if (str[0] == 'i' && ret == 1)
	{
		env->mode->v_command = 0;
		env->mode->v_insert = 1;
		env->mode->v_count = 0;
		return (1);
	}
	else if (str[0] == '#' && ret == 1)
		return (ft_hash_insert(env));
	else if (str[0] == ' ' && ret == 1)
		ft_cursor_motion(env, MRIGHT, env->mode->v_count);
	else
		return (ft_vi_moving(env, str, ret));
	ft_reset_count(env, str);
	return (1);
}
