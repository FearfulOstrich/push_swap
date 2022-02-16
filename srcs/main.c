/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:40:30 by aalleon           #+#    #+#             */
/*   Updated: 2022/02/10 16:23:44 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_list	*cmds;

	if (argc < 5)
	{
		ft_putendl_fd("Wrong usage of pipex. Usage:", 1);
		ft_putendl_fd("./pipex infile cmd1 cmd2 outfile", 1);
		ft_putendl_fd("Ex: ./pipex infile \"ls -l\" \"wc -l\" outfile", 1);
		return (1);
	}
	if (check_arguments(argc, argv, get_path(envp), &cmds))
		return (ft_exit_error(run_pipex(argv[1], argv[argc - 1], &cmds, envp)));
	return (1);
}
