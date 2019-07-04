/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_istype.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 09:00:35 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/20 11:47:45 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				auto_ispathcarac(char c)
{
	if (c == '/' || c == '<' || c == '>' || c == '~')
		return (1);
	return (0);
}

int				auto_newtoken(char c, char prev)
{
	if ((c == ' ' && prev != '\\') || c == '|' || c == '&' || c == '(')
		return (1);
	return (0);
}

int				auto_isoption(char c, char prev)
{
	if (c == '-' && prev == ' ')
		return (1);
	return (0);
}

int				auto_ischar(char c, char prev)
{
	if (!auto_newtoken(c, prev)
			&& !auto_ispathcarac(c)
			&& !auto_isoption(c, prev))
		return (1);
	return (0);
}
