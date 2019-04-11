/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envtolst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:48:06 by roliveir          #+#    #+#             */
/*   Updated: 2019/04/10 12:10:07 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "libft.h"
#include <stdlib.h>

int					ft_free_lstenv(t_lstenv **env)
{
	if (!*env)
		return (0);
	if (*env && (*env)->next)
		ft_free_lstenv(&((*env)->next));
	if ((*env)->name)
		ft_strdel(&((*env)->name));
	if ((*env)->value)
		ft_strdel(&((*env)->value));
	if (*env)
		free(*env);
	*env = NULL;
	return (0);
}

char				*ft_get_name(char *str)
{
	int				i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '=' && str[i])
		i++;
	if (str[i] == '=')
		return (ft_strsub(str, 0, i));
	return (NULL);
}

char				*ft_get_value(char *str)
{
	char			*value;

	if (!str)
		return (NULL);
	if ((value = ft_strchr(str, '=')))
		return (ft_strdup(value + 1));
	return (NULL);
}

static int			ft_init_env(t_lstenv **env, char **arge, t_lstenv **prev)
{
	if (!arge[0])
		return (0);
	if (!(*env = (t_lstenv*)ft_memalloc(sizeof(t_lstenv))))
		return (ft_error_message(BMALLOC));
	if (!((*env)->name = ft_get_name(arge[0])))
		return (ft_error_message(BMALLOC));
	if (!((*env)->value = ft_get_value(arge[0])))
		return (ft_error_message(BMALLOC));
	(*env)->next = NULL;
	*prev = *env;
	*env = (*env)->next;
	return (1);
}

int					ft_envtolst(t_lstenv **env, char **arge)
{
	int				i;
	t_lstenv		*tmp;
	t_lstenv		*prev;

	i = 0;
	if (!ft_init_env(env, arge, &prev))
		return (1);
	tmp = prev;
	while (arge[0] && arge[++i])
	{
		if (!(*env = (t_lstenv*)ft_memalloc(sizeof(t_lstenv))))
			return (ft_error_message(BMALLOC));
		if (!((*env)->name = ft_get_name(arge[i])))
			return (0);
		if (!((*env)->value = ft_get_value(arge[i])))
			return (0);
		prev->next = *env;
		prev = *env;
		(*env)->next = NULL;
		*env = (*env)->next;
	}
	*env = tmp;
	return (1);
}
