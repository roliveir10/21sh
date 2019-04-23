#include "line_edition.h"

static void	ft_endrjump(t_env *env)
{
	int	i;

	i = env->cm->pos + 1;
	if (i >= env->len)
		return ;
	while (env->line[i] && (env->line[i] == ' ' || env->line[i] == '\n'))
		i++;
	while (env->line[i] && env->line[i] != ' ' && env->line[i] != '\n')
		i++;
	if (env->line[i - 1])
		ft_cursor_motion(env, MRIGHT, i - env->cm->pos - 1);
}

void		ft_wjump(t_env *env, int count)
{
	while (--count + 1)
		ft_rjump(env);
}

void		ft_ejump(t_env *env, int count)
{
	while (--count + 1)
		ft_endrjump(env);
}

void		ft_bjump(t_env *env, int count)
{
	while (--count + 1)
		ft_ljump(env);
}

void		ft_pipejump(t_env *env, int count)
{
	ft_home(env, 1);
	ft_cursor_motion(env, MRIGHT, count - 1);
}
