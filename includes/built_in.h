/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:49:26 by roliveir          #+#    #+#             */
/*   Updated: 2019/04/08 15:27:40 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BUILT_IN_H
# define _BUILT_IN_H

# define NB_FCT 6

typedef struct				s_lstenv
{
	char					*name;
	char					*value;
	struct s_lstenv			*next;
}							t_lstenv;

typedef enum				s_berror
{
	BMALLOC
}							t_berror;

typedef struct				s_cdflag
{
	int						p;
	int						l;
	int						minus;
	char					*path;
}							t_cdflag;
/*
**	built_in name
*/

int					ft_echo(char **args, char ***env);
int					ft_cd(char **args, char ***env);
int					ft_env(char **args, char ***env);
int					ft_setenv(char **args, char ***env);
int					ft_unsetenv(char **args, char ***env);

/*
**	manager
*/

int					ft_do_home(int k, char **argv, char ***arge);
int					ft_get_home_cmd(char *name);
int					ft_error_message(t_berror error);

/*
**	lst
*/

int					ft_free_lstenv(t_lstenv **env);
int					ft_envtolst(t_lstenv **env, char **arge);
int					ft_lsttotab(t_lstenv *env, char ***arge);

/*
**	cd
*/

int					ft_getoption(char **args, t_cdflag *flag);
int					ft_pwd_update(t_cdflag flag, char ***env);
int					ft_cderr(char *str, char *file);
int					ft_setpwd(char *name, char *value, char ***env);
int					ft_cdminus(char ***env);
int					ft_cdpath(t_cdflag flag, char ***env);
#endif
