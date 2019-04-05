/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:52:45 by oboutrol          #+#    #+#             */
/*   Updated: 2019/04/04 13:25:00 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_unsetenv(char **args, char ***env)
{
	(void)env;
	(void)args;
	ft_putstr("will UNset some of it\n");
	return (0);
}
