/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:30:08 by oboutrol          #+#    #+#             */
/*   Updated: 2019/04/10 22:43:46 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"
#include <stdlib.h>
#include "libft.h"
#include <unistd.h>

t_tree		*ft_pars_pipe(t_tok *token, int start, int end)
{
	t_tok	*tok;
	t_tree	*tree;

	if (!(tree = ft_end_branch()))
		return (NULL);
	tok = ft_go_start(token, start);
	if (tok == NULL || (end != -2 && end < start))
		return (NULL);
	if ((tree = ft_sep(token, start, end, ' ')))
		return (tree);
	else if ((tree = ft_pars_word(token, start, end)))
		return (tree);
	else if ((tree = ft_pars_red(token, start, end)))
		return (tree);
	return (NULL);
}
