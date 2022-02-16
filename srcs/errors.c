/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 09:32:40 by aalleon           #+#    #+#             */
/*   Updated: 2022/02/16 15:12:54 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_exit_error(int status)
{
	return (status / 256);
}

void	ft_print_error(char *msg, int status, ...)
{
	va_list	args;

	va_start(args, status);
	if (status == 127)
	{
		ft_putstr_fd(msg, 1);
		ft_putstr_fd(": command not found: ", 1);
		ft_putendl_fd(va_arg(args, char *), 1);
	}
	else
		perror(msg);
	va_end(args);
}
