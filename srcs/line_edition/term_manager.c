/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 02:00:25 by roliveir          #+#    #+#             */
/*   Updated: 2019/04/04 19:58:12 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edition.h"
#include "libft.h"

/*
** term_x - 1 espace, clear la ligne
*/

static void			ft_setprompt(t_env *env, t_prompt prompt)
{
	if (!(env->line = ft_get_prompt(prompt)))
		ft_errorterm(TMALLOC, env);
	env->cm->pos = prompt;
	env->cm->old_pos = prompt;
	env->p_size = prompt;
	env->prompt = prompt;
}

static char			*ft_cutline(t_env *env, t_prompt prompt)
{
	char			*tmp;

	if (!(tmp = ft_strdup(env->line + prompt)))
		ft_errorterm(TMALLOC, env);
	ft_strdel(&env->line);
	env->line = tmp;
	return (tmp);
}

void				ft_term_manager(t_env *env)
{
	t_tc			*tc;
	t_cm			*cm;
	t_cpy			*cpy;

	if (!(tc = (t_tc*)ft_memalloc(sizeof(t_tc))))
		ft_errorterm(TMALLOC, env);
	if (!(cm = (t_cm*)ft_memalloc(sizeof(t_cm))))
		ft_errorterm(TMALLOC, env);
	if (!(cpy = (t_cpy*)ft_memalloc(sizeof(t_cpy))))
		ft_errorterm(TMALLOC, env);
	env->ry = NULL;
	ft_bzero(tc, sizeof(t_tc));
	ft_bzero(cm, sizeof(t_cm));
	ft_bzero(cpy, sizeof(t_cpy));
	env->tc = tc;
	env->cm = cm;
	env->cpy = cpy;
	ft_configterm(env);
}

char				*ft_get_line(t_env *env, t_prompt prompt, char *argv)
{
	int			ret;

	ret = 0;
	if (env->isatty)
		ft_switch_term(env, 0);
	env->ctrld = 0;
	while (!ret)
	{
		if (env->isatty)
			ft_setprompt(env, prompt);
		ret = ft_reader(env, argv);
	}
	if (env->isatty)
	{
		ft_switch_term(env, 1);
		return (ft_cutline(env, prompt));
	}
	return (env->line);
}
