/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump_words.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 03:54:03 by roliveir          #+#    #+#             */
/*   Updated: 2019/04/23 19:51:19 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edition.h"
#include "libft.h"

void				ft_home(t_env *env, int blank)
{
	int				i;

	ft_cursor_motion(env, MLEFT, env->cm->pos - env->p_size);
	i = env->cm->pos;
	if (!blank)
	{
		while (env->line[i] && env->line[i] == ' ')
			i++;
		ft_cursor_motion(env, MRIGHT, i - env->cm->pos);
	}
}

void				ft_end(t_env *env)
{
	ft_cursor_motion(env, MRIGHT, env->len - env->cm->pos);
}

void				ft_ljump(t_env *env)
{
	int				i;

	i = env->cm->pos - 1;
	while (i && (env->line[i] == ' ' || env->line[i] == '\n'))
		i--;
	while (i && env->line[i] != ' ' && env->line[i] != '\n')
		i--;
	if (env->line[i + 1])
		ft_cursor_motion(env, MLEFT, env->cm->pos - i - 1);
}

void				ft_rjump(t_env *env)
{
	int				i;

	i = env->cm->pos;
	while (env->line[i] && env->line[i] != ' ' && env->line[i] != '\n')
		i++;
	while (env->line[i] && (env->line[i] == ' ' || env->line[i] == '\n'))
		i++;
	ft_cursor_motion(env, MRIGHT, i - env->cm->pos);
}
