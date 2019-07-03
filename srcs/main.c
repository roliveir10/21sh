/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 12:11:17 by oboutrol          #+#    #+#             */
/*   Updated: 2019/05/20 17:41:26 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lex.h"
#include "line_edition.h"
#include <stdlib.h>

int					main(int argc, char **argv, char **arge_sys)
{
	char			*line;
	int				ret;
	char			**arge;

	(void)argc;
	(void)argv;
	arge = ft_tabdup(arge_sys);
	ft_bzero(&g_env, sizeof(t_env));
	sh_term_manager();
	ret = 1;
	while (ret)
	{
		line = line_get_readline(PBASIC);
		ret = !ft_lex(&line, &arge);
		if (ret && line)
		{
			free(line);
			line = NULL;
		}
		if (!g_env.isatty)
			ret = 0;
	}
	ft_del_words_tables(&arge);
	sh_quiterm();
	return (0);
}
