/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:58:38 by aalleon           #+#    #+#             */
/*   Updated: 2022/02/16 15:13:59 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_child_stuff(int pipe_fd[], int fd_in, t_cmd *cmd, char *envp[])
{
	close(pipe_fd[READ_END]);
	if (dup2(fd_in, STDIN_FILENO) < 0)
		exit(FDIN_ERRORNO);
	if (cmd->fd_out)
	{
		if (dup2(cmd->fd_out, STDOUT_FILENO) < 0)
			exit(FDOUT_ERRORNO);
	}
	else
	{
		if (dup2(pipe_fd[WRITE_END], STDOUT_FILENO) < 0)
			exit(DUP_ERRORNO);
	}
	close(fd_in);
	close(pipe_fd[WRITE_END]);
	execve(cmd->cmd_tab[0], cmd->cmd_tab, envp);
	exit(EXEC_ERRORNO);
}

int	exec_cmd(int fd_in, t_cmd *cmd, char *envp[])
{
	int		pipe_fd[2];
	pid_t	pid;

	if (pipe(pipe_fd) < 0)
		return (PIPE_ERRORNO);
	pid = fork();
	if (pid < 0)
		return (FORK_ERRORNO);
	if (!pid)
		do_child_stuff(pipe_fd, fd_in, cmd, envp);
	close(pipe_fd[WRITE_END]);
	cmd->child_pid = pid;
	if (cmd->fd_in)
		close(fd_in);
	if (cmd->fd_out)
	{
		close(cmd->fd_out);
		close(pipe_fd[READ_END]);
		return (1);
	}
	return (pipe_fd[READ_END]);
}

int	monitor_children(t_list **cmds)
{
	int		status;
	t_list	*cmd;
	t_cmd	*content;

	cmd = *cmds;
	while (cmd)
	{
		content = (t_cmd *)(cmd->content);
		waitpid(content->child_pid, &status, 0);
		if (status)
			ft_print_error("pipex", status / 256, content->cmd_tab[0]);
		cmd = cmd->next;
	}
	return (status);
}

int	run_pipex(char *f_in, char *f_out, t_list **cmds, char *envp[])
{
	int		fd_in;
	int		fd_out;
	t_list	*cmd;
	t_cmd	*content;

	fd_in = open(f_in, O_RDONLY);
	fd_out = open(f_out, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	cmd = *cmds;
	while (cmd)
	{
		content = ((t_cmd *)(cmd->content));
		if (content->fd_out)
			content->fd_out = fd_out;
		fd_in = exec_cmd(fd_in, content, envp);
		if (fd_in < 0)
		{
			ft_lstclear(cmds, &del_cmd);
			return (fd_in);
		}
		cmd = cmd->next;
	}
	fd_in = monitor_children(cmds);
	ft_lstclear(cmds, &del_cmd);
	return (fd_in);
}
