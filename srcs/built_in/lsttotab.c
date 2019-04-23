/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsttotab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:36:05 by roliveir          #+#    #+#             */
/*   Updated: 2019/04/07 22:30:45 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "libft.h"
#include <stdlib.h>

static int			ft_lstlen(t_lstenv *env)
{
	int				i;

	i = 0;
	while (env && ++i)
		env = env->next;
	return (i);
}

int					ft_lsttotab(t_lstenv *env, char ***arge)
{
	int				i;
	char			*tmp;

	i = ft_lstlen(env);
	ft_del_words_tables(arge);
	if (!(*arge = (char**)malloc(sizeof(char*) * (i + 1))))
		return (ft_error_message(BMALLOC));
	(*arge)[i] = NULL;
	i = -1;
	while (env)
	{
		(*arge)[++i] = ft_strdup(env->name);
		if ((*arge)[i] && (tmp = ft_strjoinf((*arge)[i], "=")))
			(*arge)[i] = tmp;
		if ((*arge)[i] && env->value
				&& (tmp = ft_strjoinf((*arge)[i], env->value)))
			(*arge)[i] = tmp;
		env = env->next;
	}
	return (1);
}
