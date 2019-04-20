#include "line_edition.h"
#include "libft.h"

static int	ft_isbig(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

void		ft_rbig_jump(t_env *env)
{
	int	i;

	i = env->cm->pos;
	while (env->line[i])
	{
		while (env->line[i] && env->line[i] != ' ')
			i++;
		while (env->line[i] && env->line[i] == ' ')
			i++;
		if (ft_isbig(env->line[i]))
			break ;
	}
	if (env->line[i])
		ft_cursor_motion(env, MRIGHT, i - env->cm->pos);
}

void		ft_lbig_jump(t_env *env)
{
	int	i;

	i = env->cm->pos - 1;
	while (i)
	{
		while (i && env->line[i] == ' ')
			i--;
		while (i && env->line[i] != ' ')
			i--;
		if (ft_isbig(env->line[i + 1]))
			break ;
	}
	if (env->line[i])
		ft_cursor_motion(env, MLEFT, env->cm->pos - i);
}
