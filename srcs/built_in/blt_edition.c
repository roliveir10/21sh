/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_edition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 20:50:21 by oboutrol          #+#    #+#             */
/*   Updated: 2019/05/04 15:00:28 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edition.h"

int		blt_edition(char **args, __unused char ***env)
{
	if (!args || !args[0] || !args[1])
		return (0);
	if (!ft_strcmp(args[1], "vi"))
		vi_new_mode(MVI);
	else if (!ft_strcmp(args[1], "emacs"))
		vi_new_mode(MNORMAL);
	return (1);
}
