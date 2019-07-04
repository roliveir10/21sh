/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_completion.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 16:49:53 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/11 13:06:47 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _AUTO_COMPLETION_H
# define _AUTO_COMPLETION_H

# include <dirent.h>

# define COMWOPT 24 + 1

typedef struct			s_name
{
	char				*name;
	char				*desc;
}						t_name;

typedef struct			s_lstword
{
	t_name				*name;
	int					type;
	char				carac;
	int					len;
	int					select;
	struct s_lstword	*next;
}						t_lstword;

typedef struct			s_autodata
{
	int					status;
	int					type;
	struct s_lstword	*lw;
	int					wordpline;
	int					lenmax;
	int					lenlst;
	int					x;
	int					y;
	char				**path;
	char				*root;
	char				*com_option;
	int					spos;
}						t_autodata;

struct s_autodata		g_data;

int						auto_completion(char *str, int ret);
int						auto_getype(void);
void					auto_keep_comp(char *str, int ret);
int						auto_getstatype(char *name, char *carac, int index);

/*
**	iscarac
*/

int						auto_ispathcarac(char c);
int						auto_newtoken(char c, char prev);
int						auto_ischar(char c, char prev);
int						auto_isoption(char c, char prev);
int						auto_isblank(void);

/*
**	alloc
*/

t_lstword				*auto_new_lstword(void);
void					auto_lstmanager(struct dirent *dt, int i);
void					auto_lstword(char *orig, char **name, int index);
void					auto_free(void);
void					auto_free_lstword(t_lstword *lw);
void					auto_filldata(void);
char					*auto_getpath(void);
char					*auto_getroot(void);
char					*auto_getcomoption(void);
char					*auto_alloc_name(char **str);
void					auto_lstoption(char **name, char **desc);

/*
**	print
*/

int						auto_printword(void);
int						auto_printaligned(void);
void					auto_printoption();

/*
**	utils
*/

int						auto_checkroot(char *name, char *root);
void					auto_calclen(void);
void					auto_sort(void);
void					auto_swapstr(char **a, char **b);
void					auto_swapint(int *a, int *b);
void					auto_swapchar(char *a, char *b);
int						auto_lenrootwbs(void);
int						auto_istabshift(char *str, int ret);
int						auto_check_double(char *name);

/*
**	completion
*/

int						auto_comproot(int back);
int						auto_compath(int back);
int						auto_compoption(int back);

/*
**	choose
*/

int						auto_choose(int back);
int						auto_return(void);
void					auto_replace(char *str, int type);

/*
**	termcaps
*/

void					auto_print_select(void);
void					auto_print_color(void);

/*
**	option_text
*/

int						auto_ls(int index, char **name, char **desc);
int						auto_cat(int index, char **name, char **desc);
int						auto_date(int index, char **name, char **desc);
int						auto_chmod(int index, char **name, char **desc);
int						auto_cp(int index, char **name, char **desc);
int						auto_df(int index, char **name, char **desc);
int						auto_echo(int index, char **name, char **desc);
int						auto_kill(int index, char **name, char **desc);
int						auto_ln(int index, char **name, char **desc);
int						auto_mkdir(int index, char **name, char **desc);
int						auto_pax(int index, char **name, char **desc);
int						auto_ps(int index, char **name, char **desc);
int						auto_rm(int index, char **name, char **desc);
int						auto_stty(int index, char **name, char **desc);
int						auto_cd(int index, char **name, char **desc);
int						auto_type(int index, char **name, char **desc);
int						auto_export(int index, char **name, char **desc);
int						auto_set(int index, char **name, char **desc);
int						auto_unset(int index, char **name, char **desc);
int						auto_jobs(int index, char **name, char **desc);
int						auto_unalias(int index, char **name, char **desc);
int						auto_test(int index, char **name, char **desc);
int						auto_hash(int index, char **name, char **desc);
int						auto_fc(int index, char **name, char **desc);

#endif
