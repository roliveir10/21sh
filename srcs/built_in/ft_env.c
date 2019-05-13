/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 10:16:51 by oboutrol          #+#    #+#             */
/*   Updated: 2019/05/08 08:57:47 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "built_in.h"
#include <unistd.h>
#include <stdlib.h>

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

char				**ft_tabdup(char **tab)
{
	int				k;
	char			**dup;

	if (!tab)
		return (NULL);
	k = 0;
	while (tab[k])
		k++;
	if (!(dup = (char**)malloc(sizeof(char*) * (k + 1))))
		return (NULL);
	dup[k] = 0;
	while (--k >= 0)
	{
		if (!(dup[k] = ft_strdup(tab[k])))
		{
			ft_del_words_tables(&dup);
			return (NULL);
		}
	}
	return (dup);
}

void				ft_new_env(char **env, char **args, t_envflag *flag)
{
	char			**new_env;
	int				k;

	if (flag->i)
		new_env = NULL;
	else if (!(new_env = ft_tabdup(env)))
		return ;
	k = 0;
	while ((args[k] && (ft_strchr(args[k], '=') || args[k][0] == '-'))
			|| k == 0)
	{
		if (args[k][0] != '-' && k > 0)
			if (!ft_setenv_eq(args[k], &new_env, flag) && new_env)
			{
				ft_del_words_tables(&new_env);
				return ;
			}
		k++;
	}
	args[k] ? exec_env(&args[k], new_env) : ft_print_words_tables(new_env);
	if (new_env)
		ft_del_words_tables(&new_env);
}

int					ft_env(char **args, char ***env)
{
	t_envflag		flag;

	ft_bzero(&flag, sizeof(t_envflag));
	if (!env || !(*env))
		return (0);
	flag.argc = ft_tablen(args);
	if (flag.argc == 1)
		return (ft_printenv(*env));
	else
	{
		if (args[1] && !ft_strcmp(args[1], "-i"))
			flag.i = 1;
		ft_new_env(*env, args, &flag);
	}
	return (1);
}
