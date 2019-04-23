/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdflag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:20:23 by roliveir          #+#    #+#             */
/*   Updated: 2019/04/08 15:33:40 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "libft.h"
#include <unistd.h>
#include <sys/stat.h>

static int				ft_getcd_flag(char *str, t_cdflag *flag)
{
	int					i;

	i = 0;
	if (str[i] == '-' && !str[i + 1] && !flag->minus)
		flag->minus = 1;
	else if (str[i] == '-' && !str[i + 1] && flag->minus)
		i--;
	while (str[++i])
	{
		if (str[i] == 'P' && !flag->minus)
			flag->p = 1;
		else if (str[i] == 'L' && !flag->minus)
			flag->l = 1;
		else
			return (ft_cderr("cd: string not in pwd: ",
						flag->minus ? "-" : str));
	}
	return (1);
}

static int				ft_getcdpath(char *str, t_cdflag *flag)
{
	if (flag->path)
		return (ft_cderr("cd: string not in pwd: ", flag->path));
	if (!(flag->path = ft_strdup(str)))
		return (ft_error_message(BMALLOC));
	return (1);
}

static int				ft_check_path(char *str)
{
	struct stat			data;

	if (!str)
		return (1);
	if (stat(str, &data) == -1)
		return (ft_cderr("cd: cannot open file: ", str));
	if (!S_ISDIR(data.st_mode))
		return (ft_cderr("cd: not a directory: ", str));
	return (1);
}

int						ft_getoption(char **args, t_cdflag *flag)
{
	int					i;
	int					j;

	i = -1;
	while (args[++i])
	{
		j = -1;
		if (args[i][0] != '-' && !ft_getcdpath(args[i], flag))
			return (0);
		else if (flag->path && args[i][0] == '-')
			return (ft_cderr("cd: string not in pwd: ", flag->path));
		else if (!flag->path && !ft_getcd_flag(args[i], flag))
			return (0);
	}
	return (ft_check_path(flag->path));
}
