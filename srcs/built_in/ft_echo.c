/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:52:45 by oboutrol          #+#    #+#             */
/*   Updated: 2019/04/04 13:24:14 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_echo(char **args, char ***env)
{
	int	k;

	(void)env;
	if (!args)
		return (0);
	k = 0;
	while (args[k])
	{
		if (k > 1)
			ft_putchar(' ');
		if (k > 0)
			ft_putstr(args[k]);
		k++;
	}
	return (0);
}
