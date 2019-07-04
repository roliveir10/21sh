/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_read_notty.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 21:27:30 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/11 13:53:10 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "line_edition.h"
#include <fcntl.h>

int					line_read_isnotatty(void)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	char			*tmp;

	if (g_env.isatty)
		return (0);
	if (!(g_env.line = ft_strnew(1)))
		sh_errorterm(TMALLOC);
	while ((ret = read(STDIN_FILENO, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(tmp = ft_strjoinf(g_env.line, buf)))
			sh_errorterm(TMALLOC);
		g_env.line = tmp;
	}
	return (1);
}
