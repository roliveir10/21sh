/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 04:08:34 by roliveir          #+#    #+#             */
/*   Updated: 2019/04/02 15:23:24 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edition.h"
#include <stdlib.h>
#include "libft.h"

static void			ft_free_history(t_history *ry)
{
	if (ry->next)
		ft_free_history(ry->next);
	if (ry->line)
		ft_strdel(&(ry->line));
	ft_memdel((void**)&(ry));
}

static void			ft_free_cpy(t_env *env)
{
	ft_strdel(&(env->cpy->str));
	ft_memdel((void**)&(env->cpy));
}

void				ft_delenv(t_env *env)
{
	if (!env)
		return ;
	if (env->tc)
		ft_memdel((void**)&(env->tc));
	if (env->cm)
		ft_memdel((void**)&(env->cm));
	if (env->cpy)
		ft_free_cpy(env);
	//if (env->isatty && env->line)
	//	ft_strdel(&(env->line));
	if (env->oldline)
		ft_strdel(&(env->oldline));
	if (env->ry)
		ft_free_history(env->ry);
}
