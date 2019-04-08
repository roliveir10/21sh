/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 10:49:08 by oboutrol          #+#    #+#             */
/*   Updated: 2019/04/08 13:12:17 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include "built_in.h"

static int		ft_check_double(char *str, t_lstenv *env)
{
	while (env)
	{
		if (!env->name)
			return (0);
		if (!ft_strcmp(str, env->name))
			return (1);
		env = env->next;
	}
	return (0);
}

static int		ft_replace_env(char **args, t_lstenv **env, int arg)
{
	t_lstenv	*tmp;

	tmp = *env;
	while (*env && ft_strcmp((*env)->name, args[1]))
		*env = (*env)->next;
	if (*env)
	{
		if (arg == 2 && (*env)->value)
			ft_strdel(&((*env)->value));
		else if (arg == 3)
		{
			free((*env)->value);
			if (!((*env)->value = ft_strdup(args[2])))
			{
				*env = tmp;
				return (0);
			}
		}
	}
	*env = tmp;
	return (1);
}

static int		ft_add_env(t_lstenv **env, t_lstenv *fresh, t_lstenv *tmp)
{
	if (!*env)
	{
		*env = fresh;
		return (1);
	}
	while ((*env)->next)
		*env = (*env)->next;
	(*env)->next = fresh;
	*env = tmp;
	return (1);
}

static int		ft_fresh_env(char **args, t_lstenv **env, int arg)
{
	t_lstenv	*tmp;
	t_lstenv	*fresh;

	tmp = *env;
	if (!ft_isalnum_tab(args[1]))
	{
		ft_putstr_fd("setenv: variable name must ", STDERR_FILENO);
		ft_putstr_fd("contain alphanumeric characters\n", STDERR_FILENO);
		return (1);
	}
	if (ft_check_double(args[1], *env))
		return (ft_replace_env(args, env, arg));
	if (!(fresh = (t_lstenv*)ft_memalloc(sizeof(t_lstenv))))
		return (ft_error_message(BMALLOC));
	if (!(fresh->name = ft_strdup(args[1])))
		return (ft_error_message(BMALLOC));
	if (arg == 3 && !(fresh->value = ft_strdup(args[2])))
		return (ft_error_message(BMALLOC));
	fresh->next = NULL;
	return (ft_add_env(env, fresh, tmp));
}

int				ft_setenv(char **args, char ***env)
{
	int			len;
	t_lstenv	*lstenv;
	int			ret;

	lstenv = NULL;
	if (!args || !*args)
		return (0);
	len = ft_tablen(args);
	if (!ft_envtolst(&lstenv, *env))
		return (ft_free_lstenv(&lstenv));
	if (len == 1)
		ft_env(args, env);
	else if (!ft_isalnum(args[1][0]) && args[1][0] != '_')
		ft_putstr_fd("setenv: name must begin with letters or '_'\n", 2);
	else if (len <= 3)
	{
		if (!ft_fresh_env(args, &lstenv, len))
			return (ft_free_lstenv(&lstenv));
	}
	else if (len > 3)
		ft_putstr_fd("setenv: too many arguments\n", STDERR_FILENO);
	ret = ft_lsttotab(lstenv, env);
	ft_free_lstenv(&lstenv);
	return (ret);
}
