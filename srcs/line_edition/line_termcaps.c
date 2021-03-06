/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_termcaps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 19:20:09 by roliveir          #+#    #+#             */
/*   Updated: 2019/05/30 18:25:21 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edition.h"

int					caps_check_termcaps(t_tc tc)
{
	int				i;

	i = -1;
	if (!tc.cl || !tc.cr || !tc.dl || !tc.dc || !tc.cm || !tc.le || !tc.nd
			|| !tc.sc || !tc.rc || !tc.up || !tc.doo || !tc.mr
			|| !tc.kh || !tc.me || !tc.kd || !tc.cd || !tc.af
			|| !tc.ri || !tc.lem || !tc.dom || !tc.upm)
		return (0);
	while (++i < 5)
		if (!tc.key[i])
			return (0);
	return (1);
}

void				caps_active_termcaps(void)
{
	if (!g_env.tc->tc || !g_env.isatty)
		return ;
	tputs(g_env.tc->key[0], 1, ft_putchar);
}

static void			caps_addtermcaps_next(t_tc *tc)
{
	tc->af = tgetstr("AF", NULL);
	tc->ri = tgetstr("RI", NULL);
	tc->lem = tgetstr("LE", NULL);
	tc->dom = tgetstr("DO", NULL);
	tc->upm = tgetstr("UP", NULL);
}

int					caps_addtermcaps(t_tc *tc)
{
	tc->cl = tgetstr("cl", NULL);
	tc->cr = tgetstr("cr", NULL);
	tc->dl = tgetstr("dl", NULL);
	tc->dc = tgetstr("dc", NULL);
	tc->cm = tgetstr("cm", NULL);
	tc->key[0] = tgetstr("ks", NULL);
	tc->key[1] = tgetstr("ku", NULL);
	tc->key[2] = tgetstr("kd", NULL);
	tc->key[3] = tgetstr("kl", NULL);
	tc->key[4] = tgetstr("kr", NULL);
	tc->le = tgetstr("le", NULL);
	tc->nd = tgetstr("nd", NULL);
	tc->sc = tgetstr("sc", NULL);
	tc->rc = tgetstr("rc", NULL);
	tc->up = tgetstr("up", NULL);
	tc->doo = tgetstr("do", NULL);
	tc->kh = tgetstr("kh", NULL);
	tc->kd = tgetstr("kD", NULL);
	tc->me = tgetstr("me", NULL);
	tc->mr = tgetstr("mr", NULL);
	tc->cd = tgetstr("cd", NULL);
	caps_addtermcaps_next(tc);
	return (caps_check_termcaps(*tc));
}
