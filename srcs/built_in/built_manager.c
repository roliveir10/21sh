/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:58:07 by roliveir          #+#    #+#             */
/*   Updated: 2019/04/07 19:56:04 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "libft.h"
#include <unistd.h>

int				ft_do_home(int k, char **argv, char ***arge)
{
	static int	(*fct_list_home[5])(char**, char***) = {
		ft_echo, ft_cd, ft_env, ft_setenv, ft_unsetenv};

	if (k < 6 && k > 0)
		return (*(fct_list_home[k - 1]))(argv, arge);
	else
		return (0);
}

int				ft_get_home_cmd(char *name)
{
	int			k;
	static char	*tabl[NB_FCT] = {
		"exit", "echo", "cd", "env", "setenv", "unsetenv"};

	if (!name)
		return (-1);
	k = 0;
	while (k < NB_FCT)
	{
		if (!ft_strcmp(name, tabl[k]))
			return (k);
		k++;
	}
	return (-1);
}

int				ft_error_message(t_berror error)
{
	ft_putstr_fd("error ID=", STDERR_FILENO);
	ft_putnbr_fd(error, STDERR_FILENO);
	ft_putchar('\n');
	return (0);
}
