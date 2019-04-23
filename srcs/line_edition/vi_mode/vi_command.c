/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:46:23 by roliveir          #+#    #+#             */
/*   Updated: 2019/04/23 20:27:22 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edition.h"
#include "libft.h"

static int		ft_vi_insert(t_env *env, char *str, int ret)
{
	if (env->mode->v_del)
		return (0);
	if (str[0] == 'i' && ret == 1)
		;
	else if (str[0] == 'I' && ret == 1)
		ft_cursor_motion(env, MLEFT, env->cm->pos = env->p_size);
	else if (str[0] == 'a' && ret == 1)
		ft_cursor_motion(env, MRIGHT, 1);
	else if (str[0] == 'A' && ret == 1)
		ft_cursor_motion(env, MRIGHT, env->len - env->cm->pos);
	else if (str[0] == 'R' && ret == 1)
		env->mode->v_replace = 1;
	else
		return (0);
	ft_reset_mode(env, 1, 0);
	return (1);
}

static int		ft_vi_history(t_env *env, char *str, int ret)
{
	if (env->mode->v_del)
		return (0);
	if (str[0] == 'j' && ret == 1)
		ft_get_dhistory(env, env->mode->v_count);
	else if (str[0] == 'k' && ret == 1)
		ft_get_uhistory(env, env->mode->v_count);
	else
		return (0);
	ft_reset_count(env, str);
	return (1);
}

int				ft_vi_command(t_env *env, char *str, int ret)
{
	if (ft_get_count(env, str)
		|| ft_get_prior_flag(env, str))
		return (1);
	else if (ft_vi_insert(env, str, ret))
		return (1);
	else if (ft_vi_history(env, str, ret))
		return (1);
	else if (str[0] == '#' && ret == 1)
		return (ft_hash_insert(env));
	else if (ft_vi_motion(env, str, ret))
		return (1);
	else if (ft_vi_delete(env, str, ret))
		return (1);
	ft_reset_count(env, str);
	return (1);
}
