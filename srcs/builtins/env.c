/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deddara <deddara@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 23:04:00 by deddara           #+#    #+#             */
/*   Updated: 2020/10/02 12:56:47 by awerebea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

void			f_env(int fd, t_data *data)
{
	int			equal_ind;
	int			i;

	i = 0;
	while (data->envp[i])
	{
		if ((equal_ind = f_coincidence_char_ind(data->envp[i], '=')) >= 0)
		{
			ft_putstr_fd(data->envp[i], fd);
			ft_putchar_fd('\n', 1);
		}
		i++;
	}
}
