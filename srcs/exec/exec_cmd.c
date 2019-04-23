/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 04:14:48 by oboutrol          #+#    #+#             */
/*   Updated: 2019/04/15 18:12:27 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

int					is_exec(char *path)
{
	struct stat		data;
	int				ret;

	if ((ret = stat(path, &data)) == -1)
		return (0);
	if (ret == 0 && data.st_mode & S_IXUSR && !S_ISDIR(data.st_mode))
		return (1);
	return (0);
}

int					do_fork(char *name, char **arg, char **arge, t_env *env)
{
	int				j;
	int				child;

	(void)env;
	j = -2;
	if (!(child = fork()))
	{
		execve(name, arg, arge);
		exit(1);
	}
	wait(&j);
	return (0);
}

/*
int					do_fork(char *name, char **arg, char **env, t_args *args)
{
	int				j;
	int				child;

	if (!args->cmd->pipe)
	{
		j = -2;
		child = fork();
		if (child == 0)
		{
			if (ft_launch_red(args->cmd->redir, args))
				ft_exit_clean_args(args, 1);
			execve(name, arg, env);
			ft_exit_clean_args(args, 1);
		}
		wait(&j);
	}
	else
	{
		if (ft_launch_red(args->cmd->redir, args))
			ft_exit_clean_args(args, 1);
		execve(name, arg, env);
		ft_exit_clean_args(args, 1);
	}
	return (1);
}*/
