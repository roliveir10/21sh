/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:23:56 by oboutrol          #+#    #+#             */
/*   Updated: 2019/04/04 13:23:58 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_cd(char **args, char ***env)
{
	int	k;

	(void)env;
	if (!args)
		return (0);
	k = 0;
	while (args[k])
	{
		if (k == 1)
		{
			ft_putstr("i wanna go: ");
			ft_putstr(args[k]);
			ft_putstr(", yepp\n");
		}
		k++;
	}
	return (0);
}
