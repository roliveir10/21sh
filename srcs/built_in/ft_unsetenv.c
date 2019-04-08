/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:52:45 by oboutrol          #+#    #+#             */
/*   Updated: 2019/04/08 13:12:29 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "built_in.h"
#include <stdlib.h>

static void			ft_free_env(t_lstenv **env)
{
	if (!*env)
		return ;
	if ((*env)->name)
		ft_strdel(&(*env)->name);
	if ((*env)->value)
		ft_strdel(&(*env)->value);
	if (*env)
		free(*env);
	*env = NULL;
}

static int			ft_unset_first(char **tab, t_lstenv **env)
{
	t_lstenv		*tmp;
	int				i;

	if (!*env)
		return (0);
	tmp = NULL;
	i = 0;
	while (tab[++i])
	{
		if (!ft_strcmp(tab[i], (*env)->name))
		{
			if ((*env)->next)
				tmp = (*env)->next;
			ft_free_env(env);
			*env = tmp;
			ft_unset_first(tab, env);
			return (1);
		}
	}
	return (0);
}

static void			ft_unset_other(char **tab, t_lstenv **env)
{
	t_lstenv		*tmp;
	t_lstenv		*next;
	int				i;

	i = 0;
	while (tab[++i])
	{
		tmp = *env;
		while ((*env)->next)
		{
			if (!ft_strcmp(tab[i], (*env)->next->name))
			{
				next = (*env)->next->next;
				ft_free_env(&((*env)->next));
				(*env)->next = next;
				*env = tmp;
				ft_unset_other(tab, env);
				return ;
			}
			*env = (*env)->next;
		}
		*env = tmp;
	}
	return ;
}

int					ft_unsetenv(char **args, char ***env)
{
	t_lstenv		*lstenv;
	int				ret;

	lstenv = NULL;
	if (!ft_envtolst(&lstenv, *env))
		return (ft_free_lstenv(&lstenv));
	if (ft_unset_first(args, &lstenv))
	{
		ret = ft_lsttotab(lstenv, env);
		ft_free_lstenv(&lstenv);
		return (ret);
	}
	ft_unset_other(args, &lstenv);
	ret = ft_lsttotab(lstenv, env);
	ft_free_lstenv(&lstenv);
	return (ret);
}
