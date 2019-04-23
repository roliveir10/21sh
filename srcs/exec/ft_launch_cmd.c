/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 10:41:25 by oboutrol          #+#    #+#             */
/*   Updated: 2019/04/17 04:27:32 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "exe.h"
#include "libft.h"
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void		ft_next_pipe(t_launch *cmd)
{
	cmd->next = ft_init_cmd(NULL);
}

void		ft_launch_exe(t_launch *cmd, char ***arge, t_env *env)
{
	char	*path;
	int		fct;
	
	fct = ft_get_home_cmd(cmd->argv[0]);
	if (fct == 0)
		exit(0);
	ft_launch_red(cmd->red, cmd, env);
	ft_do_home(fct, cmd->argv, arge);
	if (fct == -1)
		if (ft_path(cmd->argv[0], &path, *arge))
		{
			if (cmd->nbr_pipe)
			{
				execve(path, cmd->argv, *arge);
				exit(1);
			}
			else
				do_fork(path, cmd->argv, *arge, env);
		}
	ft_res_pile(cmd);
}

void		ft_launch_cmd(t_launch **cmd, char ***arge, t_env *env)
{
	int		j;

	j = -2;
	if ((*cmd)->argv)
	{
		if ((*cmd)->nbr_pipe)
			ft_launch_pipe(*cmd, arge, env);
		else
			ft_launch_exe(*cmd, arge, env);
		ft_free_cmd(*cmd);
		if (!(*cmd = ft_init_cmd(NULL)))
			exit(1);
	}
}
