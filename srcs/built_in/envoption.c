/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envoption.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:28:26 by roliveir          #+#    #+#             */
/*   Updated: 2019/05/12 17:04:23 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "libft.h"

int					ft_free_ft(t_lstarg *ft)
{
	if (!ft)
		return (0);
	if (ft)
		ft_free_ft(ft->next);
	if (ft->name)
		ft_memdel((void**)&(ft->name));
	if (ft->value)
		ft_memdel((void**)&(ft->value));
	if (ft)
		ft_memdel((void**)&ft);
	return (0);
}

static int			ft_stocklst(char *str, t_lstarg *ft)
{
	t_lstarg		*tmp;

	if (!ft)
	{
		if (!(ft = (t_lstarg*)ft_memalloc(sizeof(t_lstarg))))
			return (0);
		if (!(ft->name = ft_get_name(str)))
			return (ft_free_ft(ft));
		ft->value = ft_get_value(str);
		ft->next = NULL;
	}
	else
	{
		tmp = ft;
		while (ft->next)
			ft = ft->next;
		if (!(ft->next = (t_lstarg*)ft_memalloc(sizeof(t_lstarg))))
			return (ft_free_ft(tmp));
		if (!(ft->next->name = ft_get_name(str)))
			return (ft_free_ft(tmp));
		ft->next->value = ft_get_value(str);
		ft->next->next = NULL;
		ft = tmp;
	}
	return (1);
}

int					ft_get_envoption(char **args, t_envflag *flag)
{
	int				i;

	i = 1;
	if (args[i] && !ft_strcmp(args[1], "-i"))
		flag->i = 1;
	else if (!args[i])
		return (1);
	while (args[++i])
	{
		if (args[i][0] == '-')
			return (ft_enverr("env: No such file of directory: ", args[i]));
		if (!ft_stocklst(args[i], flag->ft))
			return (0);
	}
	return (1);
}
