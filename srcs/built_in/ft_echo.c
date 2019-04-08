/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:52:45 by oboutrol          #+#    #+#             */
/*   Updated: 2019/04/07 19:06:40 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_echo(char **args, char ***env)
{
	int			i;
	int			n;

	n = 0;
	(void)env;
	if (!args || !args[0])
		return (0);
	if (!ft_strcmp(args[1], "-n"))
		n = 1;
	i = n + 1;
	while (args[i])
	{
		if (i > n + 1)
			ft_putchar(' ');
		if (i >= n + 1)
			ft_putstr(args[i]);
		i++;
	}
	if (!n)
		ft_putchar('\n');
	return (1);
}
