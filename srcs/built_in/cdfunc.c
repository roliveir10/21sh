/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdfunc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:03:50 by roliveir          #+#    #+#             */
/*   Updated: 2019/04/08 15:38:29 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include <stdlib.h>
#include <unistd.h>

int				ft_cdminus(char ***env)
{
	char		*old;
	char		buf[512];

	if (!(old = getenv("OLDPWD")))
		return (ft_cderr("cd: OLDPWD not set\n", NULL));
	if (!getcwd(buf, 512))
		return (ft_cderr(buf, NULL));
	if (chdir(old) == -1)
		return (ft_cderr("cd: chdir error\n", NULL));
	if (!ft_setpwd("PWD", old, env))
		return (0);
	if (!ft_setpwd("OLDPWD", buf, env))
		return (0);
	return (1);
}
