/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awerebea <awerebea@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 13:14:03 by awerebea          #+#    #+#             */
/*   Updated: 2020/10/02 22:41:53 by awerebea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <signal.h>

void			f_sigint(void)
{
	if (g_read_started)
		ft_putstr_fd("\b\b  \b\b\nminishell$ ", 1);
	else
		ft_putstr_fd("\n", 1);
	g_sigint = 1;
}

void			f_sigquit(void)
{
	g_sigquit = 1;
	ft_putstr_fd("\b\b  \b\b", 1);
}
