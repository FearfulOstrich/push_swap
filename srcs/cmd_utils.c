/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:48:31 by aalleon           #+#    #+#             */
/*   Updated: 2022/02/04 10:28:30 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_cmd	*create_cmd(char **cmd_tab, int fd_in, int fd_out)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(*cmd));
	if (!cmd)
		return (0);
	cmd->cmd_tab = cmd_tab;
	cmd->fd_in = fd_in;
	cmd->fd_out = fd_out;
	return (cmd);
}

void	del_cmd(void *cmd)
{
	ft_free_tab(((t_cmd *)cmd)->cmd_tab);
	free(cmd);
	return ;
}
