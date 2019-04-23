/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_edition.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:17:19 by roliveir          #+#    #+#             */
/*   Updated: 2019/04/23 10:59:02 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edition.h"
#include "libft.h"

int				ft_get_count(t_env *env, char *str)
{
	int			tmp;

	tmp = ft_atoi(str);
	if (tmp || (str[0] == '0' && env->mode->v_count))
	{
		env->mode->v_count = env->mode->v_count * 10 + tmp;
		return (1);
	}
	else if (!env->mode->v_count)
		env->mode->v_count = 1;
	return (0);
}

void				ft_reset_count(t_env *env, char *str)
{
	int			tmp;
	int			i;

	i = -1;
	while (++i < 4)
		if (env->mode->v_prior[i])
			return ;
	tmp = ft_atoi(str);
	if (!tmp && str[0] != '0' && env->mode->v_count)
		env->mode->v_count = 0;
	
}

int				ft_get_prior_flag(t_env *env, char *str)
{
	int			i;

	i = -1;
	while (++i < 4)
		if (env->mode->v_prior[i])
			break ;
	if (i == 4)
		return (0);
	else
		ft_jump_occur(env, str[0], i, env->mode->v_count);
	i = -1;
	env->mode->v_lasta = str[0];
	while (++i < 4)
		env->mode->v_prior[i] = 0;
	return (1);
}
