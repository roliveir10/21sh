/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdfunc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:03:50 by roliveir          #+#    #+#             */
/*   Updated: 2019/04/10 11:58:03 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

int				ft_cdminus(char ***env)
{
	char		*old;
	char		buf[512];
	
	if (!getcwd(buf, 512))
		return (ft_cderr(buf, NULL));
	if (!(old = ft_getenv(*env, "OLDPWD")))
		return (ft_cderr("cd: OLDPWD not set\n", NULL));
	if (chdir(old) == -1)
	{
		ft_strdel(&old);
		return (ft_cderr("cd: chdir error\n", NULL));
	}
	if (!ft_setpwd("PWD", old, env) || !ft_setpwd("OLDPWD", buf, env))
	{
		ft_strdel(&old);
		return (0);
	}
	ft_strdel(&old);
	return (1);
}

int				ft_cdpath(t_cdflag flag, char ***env)
{
	char			buf[512];

	if (!getcwd(buf, 512))
		return (ft_cderr(buf, NULL));
	if (!ft_setpwd("OLDPWD", buf, env))
		return (0);
	if (chdir(flag.path) == -1)
		return (ft_cderr("cd: chdir error\n", NULL));
	if (!getcwd(buf, 512))
		return (ft_cderr(buf, NULL));
	if (!ft_setpwd("PWD", buf, env))
		return (0);
	return (1);	
}

int				ft_cdhome(char ***env)
{
	char		buf[512];
	char		*home;

	if (!(home = getenv("HOME")))
		return (ft_cderr("cd: HOME not set\n", NULL));
	if (!getcwd(buf, 512))
		return (ft_cderr(buf, NULL));
	if (!ft_setpwd("OLDPWD", buf, env))
		return (0);
	if (!ft_setpwd("PWD", home, env))
		return (0);
	if (chdir(home) == -1)
		return (ft_cderr("cd: chdir error\n", NULL));
	return (1);
}
