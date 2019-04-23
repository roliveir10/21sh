/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:52:45 by oboutrol          #+#    #+#             */
/*   Updated: 2019/04/10 14:10:55 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "built_in.h"
#include <unistd.h>

static int			ft_printenv(char **env)
{
	ft_print_words_tables(env);
	return (0);
}

int					ft_enverr(char *str, char *file)
{
	ft_putstr_fd(str, STDERR_FILENO);
	if (file)
		ft_putendl_fd(file, STDERR_FILENO);
	return (0);
}

int					ft_env(char **args, char ***env)
{
	t_envflag		flag;
	int				ret;

	ret = 1;
	ft_bzero(&flag, sizeof(t_envflag));
	if (!env || !(*env))
		return (0);
	flag.argc = ft_tablen(args);
	if (flag.argc == 1)
		return (ft_printenv(*env));
	else
		ret = ft_get_envoption(args, &flag);
	return (ret);
}
