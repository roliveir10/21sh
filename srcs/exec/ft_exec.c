/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 08:07:28 by oboutrol          #+#    #+#             */
/*   Updated: 2019/04/16 22:02:56 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe.h"
#include "libft.h"
#include <stdlib.h>

char			**extend(char **argv, char *str)
{
	char		**tabl;
	int			size;

	size = 0;
	if (argv)
		while (argv[size])
			(size)++;
	if (!(tabl = (char**)malloc(sizeof(char*) * (size + 2))))
		return (NULL);
	tabl[size + 1] = 0;
	tabl[size] = str;
	while (--size >= 0)
	{
		tabl[size] = argv[size];
	}
	return (tabl);
}

void			ft_add_argv(char *str, t_launch *cmd)
{
	char		**tabl;

	if (!(tabl = extend(cmd->argv, str)))
		return ;
	if (cmd->argv)
		free(cmd->argv);
	cmd->argv = tabl;
}

t_launch		*ft_last(t_launch *cmd)
{
	t_launch	*last;

	last = cmd;
	while (last->next)
		last = last->next;
	return (last);
}

void			ft_add(t_tree *tree, t_launch **cmd, char ***arge, t_env *env)
{
	t_red		*red;

	if (!tree)
		return ;
	if (ft_add_red(tree, ft_last(*cmd)))
	{
		ft_add(tree->left, cmd, arge, env);
		if (tree->content)
		{
			if (ft_last(*cmd)->will_red == 1)
			{
				red = ft_target_last(ft_last(*cmd));
				red->end_nm = ft_strdup(tree->content);
				ft_last(*cmd)->will_red = 0;
			}
			else
				ft_add_argv(ft_strdup(tree->content), ft_last(*cmd));
		}
		if (tree->type == PIP)
		{
			(*cmd)->nbr_pipe++;
			ft_next_pipe(ft_last(*cmd));
		}
		if (tree->type == SMC)
		{
			ft_launch_cmd(cmd, arge, env);
		}
		ft_add(tree->right, cmd, arge, env);
	}
}

void			ft_exec(t_tree *tree, char ***arge, t_env *env)
{
	t_launch	*cmd;

	if (!(cmd = ft_init_cmd(NULL)))
		return ;
	ft_add(tree, &cmd, arge, env);
	ft_launch_cmd(&cmd, arge, env);
}
