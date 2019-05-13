/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 09:37:40 by oboutrol          #+#    #+#             */
/*   Updated: 2019/05/04 10:31:44 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe.h"
#include <stdlib.h>

void			exec_env(char **args, char **env)
{
	char		*path;

	path = NULL;
	if (ft_path(args[0], &path, env))
		do_fork(path, args, env);
	else
		ft_cmd_nf(args[0]);
	if (path)
		free(path);
}
