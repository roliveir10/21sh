#include "line_edition.h"

void		ft_repeat(t_env *env, int rev)
{
	(void)rev;
	if (env->mode->v_lastc == 'f')
		env->mode->v_prior[0] = 1;
	else if (env->mode->v_lastc == 'F')
		env->mode->v_prior[0] = 1;
	else if (env->mode->v_lastc == 't')
		env->mode->v_prior[0] = 1;
	else if (env->mode->v_lastc == 'T')
		env->mode->v_prior[0] = 1;
	ft_get_prior_flag(env, &(env->mode->v_lasta));
}
