/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deddara <deddara@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 12:14:32 by awerebea          #+#    #+#             */
/*   Updated: 2020/09/22 22:27:10 by deddara          ###   ########.fr       */
/*   Updated: 2020/09/23 17:37:22 by awerebea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

typedef struct	s_data
{
	char		**envp;
	char		*input;
	char		**inp_arr;
	int			pos;
	int			qt1_o;
	int			qt1_c;
	int			qt2_o;
	int			qt2_c;
	int			pars_complete;
	char		*w;
	int			last_saved;
	char		*errstr;
	int			slash;
}				t_data;

char			**f_strarr_dup(char **src_arr);
char			**f_strarr_add_elem(char **src_arr, char *str);
char			**f_strarr_rem_elem(char **src_arr, char *str, char *endcmp);
int				f_strarr_find_elem(char **src_arr, char *str, char *endcmp);
void			*f_strarr_free(char **strarr);
int				f_exit(t_data *data, int exitcode, char *exitstr);

int				test_strarr(t_data *data);
int				f_cd(char *path, char **envp);
char			*f_env_find_elem(char **src_arr, char *str, char *endcmp);
void			f_pwd(int fd);
void			f_env(int fd, t_data *data);
void			f_echo(char *str, int fd, int n);
<<<<<<< HEAD
int				f_export(t_data *data, char *str, int fd);
int				check_for_equal(char **words);
int				f_unset(t_data *data, char *str);
=======
void			f_export(t_data *data, char *str, int fd);
int				f_pars_input(t_data *data);

>>>>>>> awerebea
#endif
