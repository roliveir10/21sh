/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 22:56:41 by roliveir          #+#    #+#             */
/*   Updated: 2019/04/07 15:40:21 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "line_edition.h"

void			ft_signal_handler(int val)
{
	while (val < 32)
	{
		if (val == SIGINT || val == SIGWINCH)
			signal(val, ft_signal);
		val++;
	}
}

void			ft_reset_signal(int val)
{
	while (val < 32)
	{
		if (val == SIGWINCH)
			signal(val, SIG_DFL);
		else if (val == SIGINT)
			signal(val, ft_null);
		val++;
	}
}

void			ft_setsig_child(int val)
{
	while (++val < 32)
		signal(val, SIG_DFL);
}

void			ft_null(int sg)
{
	(void)sg;
	return ;
}

void			ft_signal(int sg)
{
	if (sg == SIGWINCH)
		ft_sigwinch();
	else if (sg == SIGINT)
		ft_sigint();
}
