/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 13:24:51 by obouykou          #+#    #+#             */
/*   Updated: 2020/06/08 13:24:51 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
#include  <dirent.h>
#include  <errno.h>
#include  <signal.h>
#include "../libft/libft.h"

# define SIZE		16384
# define APPEND		'a'
# define TRUNC		'>'
# define READ		'<'
# define TRUE		1
# define FLASE		0
# define PIPE		124
# define S_COLON	59
# define STX_ERR	1
# define RDIN_ERR	2
# define SPLT_ERR	3

# define HELLO "\n\n======> SAFE <======\n\n"

typedef		struct	s_cmd
{
	char			*cmd;
	char			**args;
	char			start;
	char			end;
	char			redir;
	struct s_cmd	*prev;
	struct s_cmd	*next;
}					t_cmd;

typedef		struct	s_ms
{
	char			input[SIZE];
	char			*output;
	int				err;
	t_cmd			*cmds;
	t_cmd			*lst_end;
	int				redir;
	int				cmds_count;
	int				pp_count;
	char			*pwd;
	char			*old_pwd;
	char			**tab;
	char			**env;
	int				ret;
}					t_ms;

/* Parsing */
void				get_input(t_ms *ms);
int					tb_len(char **table);
char				**free_str_table(char **tab, int size);
void				init(t_ms *ms, char step);
void				parse(t_ms *ms);
int					char_counter(char *s, char c);
char				**parse_split(char const *s, char c);
void				errex(t_ms *ms, int ex);
char				**dup_str_tab(char **arr);
t_cmd				*get_head(t_cmd *cmds);
void				new_cmd(t_ms *ms, char del, char **tab);
// Debugging
void				print_tab(char **tab, FILE *f);
void				print_cmds(t_cmd *cmds);

/* Cmds */
int					arrlen(char **arr);
char				**arrdup(char **arr, int len);
char				*ft_strcpy_pro(char *dst, const char *src, char c);
int					get_env(char **env, char *var);
char				**get_arr(char *value, char **env);
int					check_exist(char **env, char *arg);
char				**rm_arr(char **env, int pos);
void				ft_print_env(char **env);
void				sort_env(char **env);
char				**add_to_arr(char *value, char **env);
char    			**set_env(char *var, char *value, char **env);
char    			**set_env(char *var, char *value, char **env);
int					ft_cd(t_ms *ms);
int					ft_env(t_ms *ms, char **env);
int					ft_export(t_ms *ms, char **env);
int					ft_pwd(t_ms *ms);
int					ft_unset(t_ms *ms, char **env);
/*  */
void				minishell(char **env, int step);
void				erase_file_debug();
void				write_to_file(char *s, char *num, int end);
#endif
