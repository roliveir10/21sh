/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 08:59:13 by roliveir          #+#    #+#             */
/*   Updated: 2019/05/28 08:59:14 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edition.h"

int			auto_set(int index, char **name, char **desc)
{
	static char	*flag_tab[1] = {"-o"};
	static char	*desc_tab[1] = {
		"  -- set specified option"};

	*name = ft_strdup(flag_tab[index]);
	*desc = ft_strdup(desc_tab[index]);
	return (1);
}
