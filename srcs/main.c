/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deddara <deddara@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 00:51:31 by awerebea          #+#    #+#             */
/*   Updated: 2020/10/06 15:36:51 by awerebea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <signal.h>
#include <search.h>

int				g_read_started;
int				g_sigquit;
int				g_sigint;

int				f_ind_arr_init(t_data *data)
{
	data->arr_size = 100;
	if (data->arr)
		free(data->arr);
	if (!(data->arr = (char*)malloc(sizeof(char) * data->arr_size)))
		return (1);
	ft_bzero(data->arr, data->arr_size);
	return (0);
}

void			f_clear_input_data(t_data *data)
{
	data->pars_complete = 0;
	data->inp_arr = f_strarr_free(data->inp_arr);
	if (data->w)
		free(data->w);
	data->w = NULL;
	if (data->input)
		free(data->input);
	data->input = NULL;
	data->pos = 0;
	data->start = 0;
	data->qt1_o = 0;
	data->qt1_c = 0;
	data->qt2_o = 0;
	data->qt2_c = 0;
	data->pars_complete = 0;
	data->last_saved = 0;
	data->slash = 0;
	data->sig = 0;
	g_read_started = 1;
	g_sigquit = 0;
	g_sigint = 0;
}

static int		f_data_init(t_data *data, char **argv)
{
	data->minishell_argv = argv;
	data->envp = NULL;
	data->inp_arr = NULL;
	data->cd = 0;
	data->input = NULL;
	data->in_fd_exst = 0;
	data->w = NULL;
	data->errcode = 0;
	data->arr = NULL;
	if (f_ind_arr_init(data))
		return (1);
	return (0);
}

static int		f_inner_loop(t_data *data, t_command *command)
{
	while (!data->pars_complete)
	{
		command = clear_list(command);
		if (!(command = create_command_lst()))
			return (1);
		data->inp_arr = f_strarr_free(data->inp_arr);
		if ((data->errcode = f_pars_input(data)))
			break ;
		if ((data->errcode = structer(data, command)))
		{
			data->errcode = (data->errcode == 2) ? 0 : data->errcode;
			continue;
		}
		if ((data->errcode = command_handler(data, command)))
		{
			g_read_started = 0;
			continue;
		}
		g_read_started = 0;
		cmd_caller(data, command);
	}
	command = clear_list(command);
	return (0);
}

int				main(int argc, char **argv, char **envp)
{
	t_data		data;
	t_command	*command;

	command = NULL;
	signal(SIGINT, (void*)f_sigint);
	signal(SIGQUIT, (void*)f_sigquit);
	(void)argc;
	if (f_data_init(&data, argv) || !(data.envp = f_strarr_dup(envp)))
		return (f_quit(&data, 1, "malloc error\n"));
	while (1)
	{
		f_clear_input_data(&data);
		ft_putstr_fd("minishell$ ", 1);
		if (f_readline(&data.input))
			return (f_quit(&data, 1, ""));
		if (g_sigint)
			data.errcode = 1;
		if (f_input_validator(&data))
			continue;
		if (f_inner_loop(&data, command))
			return (1);
	}
	return (f_quit(&data, 0, ""));
}
