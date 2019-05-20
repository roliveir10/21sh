/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_dup_pile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 11:33:18 by oboutrol          #+#    #+#             */
/*   Updated: 2019/05/20 11:59:25 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe.h"
#include <unistd.h>

static int	bad_fd(int dir)
{
	ft_putstr_fd("21sh: ", 2);
	ft_putnbr_fd(dir, 2);
	ft_putstr_fd(": bad file descriptor\n", 2);
	return (1);
}

int			do_dup_pile(int og, int dir, t_launch *cmd, t_red *red)
{
	if (dir == g_env.t_fd)
		return (bad_fd(dir));
	else
	{
		ft_add_pile(og, dir, cmd);
		if (dup2(dir, og) == -1)
			return (bad_fd(dir));
	}
	if (red->end == -2)
		close(og);
	return (0);
}
