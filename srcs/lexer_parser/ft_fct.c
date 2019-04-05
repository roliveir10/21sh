/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 06:36:11 by oboutrol          #+#    #+#             */
/*   Updated: 2019/04/02 03:02:19 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexpars.h"
#include "libft.h"
#include <stdlib.h>

int				ft_get_home_cmd(char *name)
{
	int			k;
	static char	*tabl[NB_FCT] = {
		"exit", "echo", "cd", "env", "setenv", "unsetenv"};

	if (!name)
		return (-1);
	k = 0;
	while (k < NB_FCT)
	{
		if (!ft_strcmp(name, tabl[k]))
			return (k);
		k++;
	}
	return (-1);
}

int				ft_fct(t_word *word, char **path, char **arge)
{
	int			k;

	if (!word || !word->value)
		return (-1);
	if ((k = ft_get_home_cmd(word->value)) >= 0)
		return (k);
	if (ft_path(word->value, path, arge))
		return (-2);
	return (-1);
}

int				ft_is_fct(char *name, char **arge)
{
	char		*path;

	path = NULL;
	if (!name)
		return (0);
	if (ft_get_home_cmd(name) >= 0)
		return (1);
	if (ft_path(name, &path, arge))
	{
		if (path)
			free(path);
		return (1);
	}
	if (path)
		free(path);
	return (0);
}
