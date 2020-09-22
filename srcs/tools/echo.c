/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deddara <deddara@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 11:43:27 by deddara           #+#    #+#             */
/*   Updated: 2020/09/22 11:48:19 by deddara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f_echo(char *str, int fd, int n)
{
	ft_putstr_fd(str, fd);
	if (!n)
		write(1, "\n", 1);
}