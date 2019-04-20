#include "line_edition.h"

void		ft_wjump(t_env *env, int count)
{
	while (--count + 1)
		ft_rjump(env);
}

void		ft_bigwjump(t_env *env, int count)
{
	while (--count + 1)
		ft_rbig_jump(env);
}

void		ft_ejump(t_env *env, int count)
{
	while (--count + 1)
		ft_ljump(env);
}

void		ft_bigejump(t_env *env, int count)
{
	while (--count + 1)
		ft_lbig_jump(env);
}
