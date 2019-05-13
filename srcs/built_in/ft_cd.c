/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:23:56 by oboutrol          #+#    #+#             */
/*   Updated: 2019/05/12 16:58:06 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "built_in.h"
#include <unistd.h>

int					ft_free_cdflag(t_cdflag *flag)
{
	if (flag->path)
		ft_strdel(&flag->path);
	return (0);
}

int					ft_cderr(char *str, char *file)
{
	ft_putstr_fd(str, STDERR_FILENO);
	if (file)
		ft_putendl_fd(file, STDERR_FILENO);
	return (0);
}

static int			ft_new_pwd(t_cdflag flag, char ***env)
{
	if (flag.minus)
		return (ft_cdminus(env));
	else if (flag.path)
		return (ft_cdpath(flag, env));
	else
		return (ft_cdhome(env));
	return (1);
}

int					ft_cd(char **args, char ***env)
{
	t_lstenv		*lstenv;
	t_cdflag		flag;
	int				ret;

	(void)env;
	lstenv = NULL;
	ft_bzero(&flag, sizeof(t_cdflag));
	if (!args || !*args)
		return (0);
	if (!ft_getoption(&args[1], &flag))
		return (ft_free_cdflag(&flag));
	ret = ft_new_pwd(flag, env);
	ft_free_cdflag(&flag);
	return (ret);
}
