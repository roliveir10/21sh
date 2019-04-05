/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 10:51:10 by oboutrol          #+#    #+#             */
/*   Updated: 2019/04/04 12:03:51 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int			ft_tab_size(char **env)
{
	int		size;

	if (!env)
		return (0);
	size = 0;
	while (env[size])
		size++;
	return (size);
}

char		**ft_tab_dup(char **tabl)
{
	int		k;
	char	**new;

	if (!tabl)
		return (NULL);
	if (!(new = (char**)malloc(sizeof(char*) * (ft_tab_size(tabl) + 2))))
		return (NULL);
	k = 0;
	while (tabl[k])
	{
		if (!(new[k] = ft_strdup(tabl[k])))
			return (NULL);
		k++;
	}
	new[k] = 0;
	return (new);
}
