/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv_eq.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 12:54:39 by oboutrol          #+#    #+#             */
/*   Updated: 2019/05/06 13:46:30 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include "built_in.h"

int				is_alrdy(char *args, char **env)
{
	int			k;
	int			len;

	if (!args || !env)
		return (-1);
	k = 0;
	len = 0;
	while (args[len] && args[len] != '=')
		len++;
	if (!args[len])
		return (-1);
	while (env[k])
	{
		if (!ft_strncmp(args, env[k], len) && env[k][len] == '=')
			return (k);
		k++;
	}
	return (-1);
}

int				replace(char *args, int pos, char ***env)
{
	free((*env)[pos]);
	if (!((*env)[pos] = ft_strdup(args)))
		return (0);
	return (1);
}

int				ft_add_tab(char *args, char ***env)
{
	int			k;
	char		**expended;

	k = 0;
	while (*env && (*env)[k])
		k++;
	if (!(expended = (char**)malloc(sizeof(char*) * (k + 2))))
		return (0);
	expended[k + 1] = 0;
	if (!(expended[k] = ft_strdup(args)))
	{
		ft_del_words_tables(&expended);
		return (0);
	}
	while (--k >= 0)
		expended[k] = (*env)[k];
	free(*env);
	*env = expended;
	return (1);
}

int				ft_setenv_eq(char *args, char ***env, t_envflag *flag)
{
	int			pos;

	if ((pos = is_alrdy(args, *env)) != -1)
	{
		if (!(replace(args, pos, env)))
			return (0);
	}
	else
	{
		if (!(ft_add_tab(args, env)))
			return (0);
		flag->i++;
	}
	return (1);
}
