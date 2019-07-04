/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_quit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 09:29:41 by roliveir          #+#    #+#             */
/*   Updated: 2019/05/30 23:35:35 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edition.h"

static void		line_newprompt(void)
{
	if (!g_env.search)
		return ;
	g_env.search = 0;
	ft_strdel(&g_env.h_word);
	g_env.h_len = 0;
}

int				line_ctrld(void)
{
	line_newprompt();
	g_env.ctrld = 1;
	g_env.count = 0;
	return (0);
}

int				line_return(void)
{
	line_newprompt();
	if (g_data.status == 2)
		return (auto_return());
	if (g_env.mode->mode[MVI])
	{
		ft_bzero(g_env.s_buffer, sizeof(g_env.s_buffer));
		vi_free_undo(g_env.mode->undo);
		g_env.mode->undo = NULL;
		line_end();
		return (vi_reset_mode(1, 0, 0));
	}
	g_env.count = 0;
	if (g_env.mode->n_select)
		line_escap_cpy(1);
	auto_free();
	g_env.search = 0;
	g_env.h_index = 0;
	return (line_end());
}

int				line_escap(void)
{
	line_newprompt();
	g_env.h_index = 0;
	g_env.search = 0;
	if (g_env.mode->mode[MVI])
		vi_reset_mode(0, 1, 0);
	else if (g_env.mode->n_select)
		line_escap_cpy(1);
	if (g_env.mode->mode[MNORMAL])
	{
		g_env.mode->v_command = 1;
		g_env.count = 0;
	}
	return (1);
}
