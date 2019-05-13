/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 22:56:41 by roliveir          #+#    #+#             */
/*   Updated: 2019/05/03 11:44:09 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "line_edition.h"

void			sig_handler(int val)
{
	while (val < 32)
	{
		if (val == SIGINT || val == SIGWINCH)
			signal(val, sig_manager);
		val++;
	}
}

void			sig_reset(int val)
{
	while (val < 32)
	{
		if (val == SIGWINCH)
			signal(val, SIG_DFL);
		if (val == SIGINT)
			signal(val, SIG_IGN);
		val++;
	}
}

void			sig_setchild(int val)
{
	while (++val < 32)
		signal(val, SIG_DFL);
}

void			sig_manager(int sg)
{
	if (sg == SIGWINCH)
		sig_sigwinch();
	else if (sg == SIGINT)
		sig_sigint();
}
