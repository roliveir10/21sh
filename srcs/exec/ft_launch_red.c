/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch_red.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 16:45:02 by oboutrol          #+#    #+#             */
/*   Updated: 2019/05/20 14:06:04 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe.h"
#include "libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

static int	make_rel(t_red *red, int *og, int *dir)
{
	if (red->type == REL && red->end_nm)
	{
		if ((*dir = open(red->end_nm, O_RDONLY)) == -1)
			return (error_open(red->end_nm));
		*og = 0;
	}
	if (red->type == REL + 20 && red->end_nm)
		ft_heredoc_read(og, dir);
	return (0);
}

static int	make_rer(t_red *red, int *og, int *dir)
{
	if (red->type == RER && red->end_nm)
	{
		if (red->end != -1)
		{
			if (red->end == -2)
				*dir = 1;
			else
				*dir = red->end;
		}
		else if ((*dir = open(red->end_nm, O_WRONLY | O_TRUNC | O_CREAT,
					S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR)) == -1)
			return (error_open(red->end_nm));
		*og = 1;
	}
	if (red->type == RER + 20 && red->end_nm)
	{
		if ((*dir = open(red->end_nm, O_WRONLY | O_APPEND | O_CREAT,
					S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR)) == -1)
			return (error_open(red->end_nm));
		*og = 1;
	}
	return (0);
}

static int	make_one_red(t_red *red, t_launch *cmd)
{
	int		dir;
	int		og;
	int		ret;

	dir = -2;
	og = -2;
	if (!red)
		return (0);
	if ((ret = make_rel(red, &og, &dir)))
		return (ret);
	if ((ret = make_rer(red, &og, &dir)))
		return (ret);
	if (red->srt)
		og = red->srt;
	if (dir != -2 && og != -2)
		if (do_dup_pile(og, dir, cmd, red))
			return (1);
	return (0);
}

int			ft_launch_red(t_red *red, t_launch *cmd)
{
	t_red	*tmp;
	int		ret;

	ret = 0;
	tmp = red;
	while (red && !ret)
	{
		ret = make_one_red(red, cmd);
		red = red->next;
	}
	red = tmp;
	return (ret);
}
