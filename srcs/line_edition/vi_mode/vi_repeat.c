/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_repeat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 11:18:36 by roliveir          #+#    #+#             */
/*   Updated: 2019/04/23 11:30:44 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edition.h"

void		ft_repeat(t_env *env)
{
	if (env->mode->v_lastc == 'f')
		env->mode->v_prior[0] = 1;
	else if (env->mode->v_lastc == 'F')
		env->mode->v_prior[1] = 1;
	else if (env->mode->v_lastc == 't')
		env->mode->v_prior[2] = 1;
	else if (env->mode->v_lastc == 'T')
		env->mode->v_prior[3] = 1;
	ft_get_prior_flag(env, &(env->mode->v_lasta));
}

void		ft_rev_repeat(t_env *env)
{
	if (env->mode->v_lastc == 'f')
		env->mode->v_prior[1] = 1;
	else if (env->mode->v_lastc == 'F')
		env->mode->v_prior[0] = 1;
	else if (env->mode->v_lastc == 't')
		env->mode->v_prior[3] = 1;
	else if (env->mode->v_lastc == 'T')
		env->mode->v_prior[2] = 1;
	ft_get_prior_flag(env, &(env->mode->v_lasta));
}
