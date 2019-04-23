/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 23:07:53 by roliveir          #+#    #+#             */
/*   Updated: 2019/04/06 17:47:11 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "line_edition.h"

static int				ft_is_uhistory(t_env *env, int count)
{
	int				lstlen;
	t_history			*tmp;

	lstlen = 0;
	tmp = env->ry;
	while (env->ry)
	{
		lstlen++;
		env->ry = env->ry->next;
	}
	env->ry = tmp;
	if (count + env->index > lstlen)
		return (0);
	return (1);
}

static int				ft_is_dhistory(t_env *env, int count)
{
	if (count > env->index)
		return (0);
	return (1);
}

void					ft_get_uhistory(t_env *env, int count)
{
	int					i;
	t_history			*tmp;

	i = -1;
	tmp = env->ry;
	if (!ft_is_uhistory(env, count))
		return ;
	while (env->ry && ++i < env->index)
		env->ry = env->ry->next;
	if (!env->ry)
	{
		env->ry = tmp;
		return ;
	}
	env->index += count;
	if (!(env->line = ft_alloc_history(env, 0)))
		ft_errorterm(TMALLOC, env);
	env->ry = tmp;
	ft_cursor_ry(env);
}

void					ft_get_dhistory(t_env *env, int count)
{
	int					i;
	t_history			*tmp;

	i = -1;
	if (!env->index || !ft_is_dhistory(env, count))
		return ;
	env->index -= count;
	if (!env->index)
		env->line = ft_alloc_history(env, 1);
	else
	{
		tmp = env->ry;
		while (env->ry->next && ++i < env->index)
			env->ry = env->ry->next;
		env->ry = env->ry->prev;
		if (!(env->line = ft_alloc_history(env, 0)))
			ft_errorterm(TMALLOC, env);
		env->ry = tmp;
	}
	if (!env->line)
		ft_errorterm(TMALLOC, env);
	ft_cursor_ry(env);
}

void					ft_reset_history(t_env *env)
{
	while (env->ry && env->ry->prev)
		env->ry = env->ry->prev;
	env->index = 0;
}
