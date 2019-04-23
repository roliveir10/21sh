/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_cdel.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:34:42 by roliveir          #+#    #+#             */
/*   Updated: 2019/04/23 20:07:25 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edition.h"

void			ft_cdel(t_env *env)
{
	if (env->mode->v_pos == env->cm->pos)
		return ;
	if (env->mode->v_pos < env->cm->pos)
	{
		env->line = ft_delchar(env, env->cm->pos - env->mode->v_pos);
		ft_cursor_motion(env, MLEFT, env->cm->pos - env->mode->v_pos);
	}
	else
		env->line = ft_delchar_bs(env, env->mode->v_pos - env->cm->pos);
	env->mode->v_del = 0;
	env->mode->v_pos = 0;
	ft_reset_mode(env, 1, 0);
}
