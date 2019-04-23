/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_vi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:59:39 by roliveir          #+#    #+#             */
/*   Updated: 2019/04/23 12:11:25 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "line_edition.h"
#include "libft.h"

int				ft_hash_insert(t_env *env)
{
	char		*fresh;

	if (env->len >= BUFF_SIZE)
		return (0);
	if (!(fresh = ft_strnew(env->len + 1)))
		ft_errorterm(TMALLOC, env);
	ft_strncpy(fresh, env->line, env->p_size);
	fresh[env->p_size] = '#';
	ft_strcpy(&(fresh[env->p_size + 1]), &(env->line[env->p_size]));
	ft_strdel(&(env->line));
	env->line = fresh;
	ft_reset_history(env);
	ft_strdel(&env->oldline);
	if (!(env->oldline = ft_strdup(env->line)))
		ft_errorterm(TMALLOC, env);
	return (0);
}

char			*ft_replace_str(t_env *env, char *str, int len)
{
	char		*fresh;
	int			lenstr;

	lenstr = (int)ft_strlen(str);
	if (!(fresh = ft_strnew(len)))
		ft_errorterm(TMALLOC, env);
	ft_strncpy(fresh, env->line, env->cm->pos);
	ft_strcpy(&(fresh[env->cm->pos]), str);
	ft_strcpy(&(fresh[env->cm->pos + lenstr]),
			&(env->line[env->cm->pos + lenstr]));
	ft_strdel(&(env->line));
	return (fresh);
}
