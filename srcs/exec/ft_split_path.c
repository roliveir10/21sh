/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 00:52:27 by oboutrol          #+#    #+#             */
/*   Updated: 2019/04/13 11:16:43 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strcut_start(char *str, int k)
{
	int		len;
	char	*way;

	len = ft_strlen(str);
	way = ft_strsub(str, k, len - k);
	return (way);
}

int			join_path_slash(char **path)
{
	int		k;

	k = 0;
	if (!(path))
		return (1);
	while (path[k])
	{
		if (!(path[k] = ft_strjoinf(path[k], "/")))
			return (0);
		k++;
	}
	return (1);
}

char		**ft_split_path(char **env)
{
	char	**path;
	char	*way;
	int		k;

	if (!env)
		return (NULL);
	k = 0;
	while (env[k] && ft_strncmp(env[k], "PATH=", 5))
		k++;
	if (!env[k])
		return (NULL);
	way = ft_strcut_start(env[k], 5);
	path = ft_strsplit(way, ':');
	if (way)
		free(way);
	if (!(join_path_slash(path)))
		return (NULL);
	return (path);
}
