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

static int			ft_vi_repeat(t_env *env, char *str, int ret)
{
	if (str[0] == ';' && ret == 1)
		ft_repeat(env, 0);
	else if (str[0] == ',' && ret == 1)
		ft_repeat(env, 1);
	ft_reset_count(env, str);
	return (1);	
}

static int			ft_vi_moving2(t_env *env, char *str, int ret)
{
	if (str[0] == '^' && ret == 1)
		ft_home(env, 0);
	else if (str[0] == '$' && ret == 1)
		ft_end(env);
	else if (str[0] == '0' && ret == 1)
		ft_home(env, 1);
	else if (str[0] == '|' && ret == 1)
		ft_pipejump(env, env->mode->v_count);
	else if (str[0] == 'f' && ret == 1)
		env->mode->v_prior[0] = 1;
	else if (str[0] == 'F' && ret == 1)
		env->mode->v_prior[1] = 1;
	else if (str[0] == 't' && ret == 1)
		env->mode->v_prior[2] = 1;
	else if (str[0] == 'T' && ret == 1)
		env->mode->v_prior[3] = 1;
	else
		return (ft_vi_repeat(env, str, ret));
	env->mode->v_lastc = str[0];
	ft_reset_count(env, str);
	return (1);
}
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
	else if ((str[0] == 'w' || str[0] == 'W') && ret == 1)
		ft_wjump(env, env->mode->v_count);
	else if ((str[0] == 'e' || str[0] == 'E') && ret == 1)
		ft_ejump(env, env->mode->v_count);
	else if ((str[0] == 'b' || str[0] == 'B') && ret == 1)
		ft_bjump(env, env->mode->v_count);
	else
		return (ft_vi_moving2(env, str, ret));
	ft_reset_count(env, str);
	return (1);
}

int				ft_vi_command(t_env *env, char *str, int ret)
{
	if (ft_get_count(env, str)
		|| ft_get_prior_flag(env, str))
		return (1);
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
