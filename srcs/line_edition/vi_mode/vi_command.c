/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:46:23 by roliveir          #+#    #+#             */
/*   Updated: 2019/04/23 12:11:27 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edition.h"
#include "libft.h"

static int			ft_vi_repeat(t_env *env, char *str, int ret)
{
	if (str[0] == ';' && ret == 1)
		ft_repeat(env);
	else if (str[0] == ',' && ret == 1)
		ft_rev_repeat(env);
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

static int		ft_vi_insert(t_env *env, char *str, int ret)
{
	if (str[0] == 'i' && ret == 1)
		return (ft_reset_mode(env, 1, 0) + 1);
	else if (str[0] == 'I' && ret == 1)
	{
		ft_cursor_motion(env, MLEFT, env->cm->pos = env->p_size);
		return (ft_reset_mode(env, 1, 0) + 1);
	}
	else if (str[0] == 'a' && ret == 1)
	{
		ft_cursor_motion(env, MRIGHT, 1);
		return (ft_reset_mode(env, 1, 0) + 1);
	}
	else if (str[0] == 'A' && ret == 1)
	{
		ft_cursor_motion(env, MRIGHT, env->len - env->cm->pos);
		return (ft_reset_mode(env, 1, 0) + 1);
	}
	else if (str[0] == 'R' && ret == 1)
	{
		ft_reset_mode(env, 1, 0);
		env->mode->v_replace = 1;
		return (1);
	}
	return (0);
}

int				ft_vi_command(t_env *env, char *str, int ret)
{
	if (ft_get_count(env, str)
		|| ft_get_prior_flag(env, str))
		return (1);
	else if (ft_vi_insert(env, str, ret))
		return (1);
	else if (str[0] == '#' && ret == 1)
		return (ft_hash_insert(env));
	else if (str[0] == ' ' && ret == 1)
		ft_cursor_motion(env, MRIGHT, env->mode->v_count);
	else
		return (ft_vi_moving(env, str, ret));
	ft_reset_count(env, str);
	return (1);
}
