/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 10:52:54 by oboutrol          #+#    #+#             */
/*   Updated: 2019/04/17 05:05:01 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe.h"
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

void		ft_add_pile(int og, t_launch *cmd)
{
	if (og == 0 && cmd->in < 0)
		cmd->in = dup(0);
	if (og == 1 && cmd->out < 0)
		cmd->out = dup(1);
	if (og == 2 && cmd->err < 0)
		cmd->err = dup(2);
}

void		ft_res_pile(t_launch *cmd)
{
	if (cmd)
	{
		if (cmd->in != -2)
		{
			dup2(cmd->in, 0);
			close(cmd->in);
		}
		if (cmd->out != -2)
		{
			dup2(cmd->out, 1);
			close(cmd->out);
		}
		if (cmd->err != -2)
		{
			dup2(cmd->err, 2);
			close(cmd->err);
		}
	}
}
