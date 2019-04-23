/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch_red.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 00:10:33 by oboutrol          #+#    #+#             */
/*   Updated: 2019/04/17 05:05:02 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe.h"
#include "libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

int			make_rel(t_red *red, int *og, int *dir, t_env *env)
{
	if (red->type == REL && red->end_nm)
	{
		if ((*dir = open(red->end_nm, O_RDONLY)) == -1)
			return (error_open(red->end_nm));
		*og = 0;
	}
	if (red->type == REL + 2 && red->end_nm)
	{
		ft_heredoc(env, red->end_nm);
		*dir = -2;
		*og = -2;
	}
	return (0);
}

int			make_rer(t_red *red, int *og, int *dir)
{
	if (red->type == RER && red->end_nm)
	{
		if (red->end)
			*dir = red->end;
		else if ((*dir = open(red->end_nm, O_WRONLY | O_TRUNC | O_CREAT,
					S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR)) == -1)
			return (error_open(red->end_nm));
		*og = 1;
	}
	if (red->type == RER + 2 && red->end_nm)
	{
		if ((*dir = open(red->end_nm, O_WRONLY | O_APPEND | O_CREAT,
					S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR)) == -1)
			return (error_open(red->end_nm));
		*og = 1;
	}
	return (0);
}

int			make_one_red(t_red *red, t_launch *cmd, t_env *env)
{
	int		dir;
	int		og;
	int		ret;

	dir = -2;
	og = -2;
	if (!red)
		return (0);
	if ((ret = make_rel(red, &og, &dir, env)))
		return (ret);
	if ((ret = make_rer(red, &og, &dir)))
		return (ret);
	if (red->srt)
		og = red->srt;
	if (dir != -2 && og != -2)
	{
		ft_add_pile(og, cmd);
		dup2(dir, og);
	}
	return (0);
}

int			ft_launch_red(t_red *red, t_launch *cmd, t_env *env)
{
	t_red	*tmp;
	int		ret;

	ret = 0;
	tmp = red;
	while (red && !ret)
	{
		ret = make_one_red(red, cmd, env);
		red = red->next;
	}
	red = tmp;
	return (ret);
}
