/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_com_motion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 13:20:36 by roliveir          #+#    #+#             */
/*   Updated: 2019/04/23 20:27:20 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edition.h"

static int			ft_vi_priorjump(t_env *env, char *str, int ret)
{
	if (str[0] == 'f' && ret == 1)
		env->mode->v_prior[0] = 1;
	else if (str[0] == 'F' && ret == 1)
		env->mode->v_prior[1] = 1;
	else if (str[0] == 't' && ret == 1)
		env->mode->v_prior[2] = 1;
	else if (str[0] == 'T' && ret == 1)
		env->mode->v_prior[3] = 1;
	else
		return (0);
	env->mode->v_lastc = str[0];
	return (1);
}

static int			ft_vi_spec_motion(t_env *env, char *str, int ret)
{
	if (str[0] == '^' && ret == 1)
		ft_home(env, 0);
	else if (str[0] == '$' && ret == 1)
		ft_end(env);
	else if (str[0] == '0' && ret == 1)
		ft_home(env, 1);
	else if (str[0] == '|' && ret == 1)
		ft_pipejump(env, env->mode->v_count);
	else if (str[0] == ';' && ret == 1)
		ft_repeat(env);
	else if (str[0] == ',' && ret == 1)
		ft_rev_repeat(env);
	else
		return (0);
	if (env->mode->v_del)
		ft_cdel(env);
	ft_reset_count(env, str);
	return (1);
}

int					ft_vi_motion(t_env *env, char *str, int ret)
{
	if (ft_vi_priorjump(env, str, ret))
			return (1);
	else if (str[0] == ' ' && ret == 1)
		ft_cursor_motion(env, MRIGHT, env->mode->v_count);
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
		return (ft_vi_spec_motion(env, str, ret));
	if (env->mode->v_del)
		ft_cdel(env);
	ft_reset_count(env, str);
	return (1);
}
