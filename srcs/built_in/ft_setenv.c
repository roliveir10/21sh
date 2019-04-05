/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 10:49:08 by oboutrol          #+#    #+#             */
/*   Updated: 2019/04/04 13:57:48 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lexpars.h"
#include <stdlib.h>

int			ft_append_arg(char *arg, char ***env)
{
	int		k;
	char	**env_new;

	k = 0;
	if (!(env_new = (char**)malloc(sizeof(char*) * (ft_tab_size(*env) + 2))))
		return (1);
	while (env && *env && (*env)[k])
	{
		env_new[k] = (*env)[k];
		k++;
	}
	env_new[k] = ft_strdup(arg);
	env_new[k + 1] = 0;
	if (*env)
		free(*env);
	*env = env_new;
	return (0);
}

int			ft_manage_arg(char *arg, char ***env)
{
	return (ft_append_arg(arg, env));
}

int			ft_setenv(char **args, char ***env)
{
	int		k;

	k = 0;
	if (!args)
		return (0);
	while (args[k])
	{
		if (k > 0)
			if (ft_manage_arg(args[k], env))
				return (1);
		k++;
	}
	return (0);
}
