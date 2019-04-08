/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdpwd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:22:56 by roliveir          #+#    #+#             */
/*   Updated: 2019/04/08 15:28:46 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include <unistd.h>
#include "libft.h"
#include <stdlib.h>

int					ft_setpwd(char *name, char *value, char ***env)
{
	char			**args;
	int				i;
	int				ret;

	i = -1;
	if (!(args = (char**)malloc(sizeof(char*) * 4)))
		return (ft_error_message(BMALLOC));
	args[0] = ft_strdup("setenv");
	args[1] = ft_strdup(name);
	args[2] = ft_strdup(value);
	args[3] = 0;
	while (++i < 3)
		if (!args[i])
		{
			ft_del_words_tables(&args);
			return (ft_error_message(BMALLOC));
		}
	ret = ft_setenv(args, env);
	ft_del_words_tables(&args);
	return (ret);
}

int					ft_pwd_update(t_cdflag flag, char ***env)
{
	char			buf[512];
	char			*pwd;

	(void)flag;
	if ((pwd = getenv("PWD")))
		return (1);
	if (!getcwd(buf, 512))
		return (ft_cderr(buf, NULL));
	if (!ft_setpwd("PWD", buf, env))
		return (0);
	return (1);
}
