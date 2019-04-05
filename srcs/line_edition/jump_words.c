/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump_words.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 03:54:03 by roliveir          #+#    #+#             */
/*   Updated: 2019/04/03 11:11:11 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edition.h"
#include "libft.h"

void				ft_home(t_env *env)
{
	ft_cursor_motion(env, MLEFT, env->cm->pos - env->p_size);
}

void				ft_end(t_env *env)
{
	int				len;

	len = (int)ft_strlen(env->line);
	ft_cursor_motion(env, MRIGHT, len - env->cm->pos);
}

void				ft_ljump(t_env *env)
{
	int				i;
	int				len;

	i = env->cm->pos - 1;
	len = env->cm->pos;
	while (i && env->line[i] == ' ')
		i--;
	while (i && env->line[i] != ' ')
		i--;
	if (env->line[i])
		ft_cursor_motion(env, MLEFT, len - i);
}

void				ft_rjump(t_env *env)
{
	int				i;
	int				len;

	i = env->cm->pos;
	len = i;
	while (env->line[i] && env->line[i] != ' ')
		i++;
	while (env->line[i] && env->line[i] == ' ')
		i++;
	if (env->line[i])
		ft_cursor_motion(env, MRIGHT, i - len);
}
