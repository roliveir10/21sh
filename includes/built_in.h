/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 16:22:54 by oboutrol          #+#    #+#             */
/*   Updated: 2019/05/12 16:54:08 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BUILT_IN_H
# define _BUILT_IN_H

# define NB_FCT 8

typedef struct			s_lstenv
{
	char				*name;
	char				*value;
	struct s_lstenv		*next;
}						t_lstenv;

typedef enum			e_berror
{
	BMALLOC
}						t_berror;

typedef struct			s_cdflag
{
	int					p;
	int					l;
	int					minus;
	char				*path;
}						t_cdflag;

typedef struct			s_lstarg
{
	char				*name;
	char				*value;
	struct s_lstarg		*next;
}						t_lstarg;

typedef struct			s_envflag
{
	int					argc;
	int					i;
	struct s_lstarg		*ft;
}						t_envflag;

/*
**	built_in name
*/

int						ft_echo(char **args, char ***env);
int						ft_cd(char **args, char ***env);
int						ft_env(char **args, char ***env);
void					exec_env(char **args, char **env);
int						ft_setenv(char **args, char ***env);
int						ft_setenv_eq(char *args, char ***env, t_envflag *flag);
int						ft_unsetenv(char **args, char ***env);
int						blt_edition(char **args, char ***env);
int						blt_history(char **args, char ***env);

/*
**	manager
*/

int						ft_do_home(int k, char **argv, char ***arge);
int						ft_get_home_cmd(char *name);
int						ft_error_message(t_berror error);

/*
**	lst
*/

int						ft_free_lstenv(t_lstenv **env);
int						ft_envtolst(t_lstenv **env, char **arge);
int						ft_lsttotab(t_lstenv *env, char ***arge);
char					*ft_get_name(char *str);
char					*ft_get_value(char *str);

/*
**	cd
*/

int						ft_getoption(char **args, t_cdflag *flag);
int						ft_cderr(char *str, char *file);
int						ft_setpwd(char *name, char *value, char ***env);
int						ft_cdminus(char ***env);
int						ft_cdpath(t_cdflag flag, char ***env);
int						ft_cdhome(char ***env);

/*
**	env
*/

int						ft_get_envoption(char **args, t_envflag *flag);
int						ft_enverr(char *str, char *file);
int						ft_free_ft(t_lstarg *ft);
#endif
