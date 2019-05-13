/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:53:55 by roliveir          #+#    #+#             */
/*   Updated: 2019/05/04 16:38:25 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edition.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>

void				sig_sigint(void)
{
	g_env.sigc = 1;
	line_end();
	ft_putchar('\n');
	ioctl(0, TIOCSTI, "^D");
}

void				sig_sigwinch(void)
{
	line_update_termsize();
	line_clear();
	ft_putstr(g_env.line);
	line_reset_cursor();
}
