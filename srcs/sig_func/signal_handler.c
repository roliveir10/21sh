/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 22:56:41 by roliveir          #+#    #+#             */
/*   Updated: 2019/04/01 00:00:38 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "line_edition.h"

void			ft_signal_handler(int val)
{
	while (val < 32)
	{
		if (val == SIGINT || val == SIGWINCH || val == SIGTSTP
				|| val == SIGCONT)
			signal(val, ft_signal);
		val++;
	}
}

void			ft_signal(int sg)
{
	if (sg == SIGWINCH)
		ft_sigwinch();
	else if (sg == SIGINT)
		ft_sigint();
	else if (sg == SIGCONT)
		ft_sigcont();
	else if (sg == SIGTSTP)
		ft_sigsusp();
}
