/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:40:44 by aalleon           #+#    #+#             */
/*   Updated: 2022/02/16 15:11:42 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdarg.h>
# include <sys/errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

// pipe end ids
# define READ_END 0
# define WRITE_END 1
// Error ids
# define FDIN_ERRORNO 3
# define FDOUT_ERRORNO 4
# define DUP_ERRORNO 5
# define EXEC_ERRORNO 127
# define PIPE_ERRORNO -1
# define FORK_ERRORNO -2

typedef struct s_cmd
{
	char	**cmd_tab;
	int		fd_in;
	int		fd_out;
	int		child_pid;
}	t_cmd;

int		run_pipex(char *fin, char *fout, t_list **cmds, char *envp[]);
char	**get_path(char *envp[]);
int		check_arguments(int argc, char *argv[], char **path, t_list **lst);
char	**check_command(char *cmd, char **paths);
t_cmd	*create_cmd(char **tab, int fd_in, int fd_out);
void	del_cmd(void *cmd);
void	ft_print_error(char *msg, int status, ...);
int		ft_exit_error(int status);
#endif
