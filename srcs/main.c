/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 12:11:17 by oboutrol          #+#    #+#             */
/*   Updated: 2019/04/17 01:38:37 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lex.h"
#include "libft.h"
#include "line_edition.h"
#include <stdlib.h>

int					main(int argc, char **argv, char **arge_sys)
{
	char			*line;
	t_env			env;
	int				ret;
	char			**arge;

	(void)argc;
	arge = ft_tab_dup(arge_sys);
	ft_bzero(&env, sizeof(t_env));
	ft_term_manager(&env);
	ret = 1;
	while (ret)
	{
		line = ft_get_line(&env, PBASIC, argv[1]);
		ret = !ft_lex(&line, &env, &arge);
		if (ret && line)
		{
			free(line);
			line = NULL;
		}
		if (!env.isatty)
			ret = 0;
	}
	ft_del_words_tables(&arge);
	ft_quiterm(&env);
	return (0);
}
