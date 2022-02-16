/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:40:50 by aalleon           #+#    #+#             */
/*   Updated: 2022/02/16 15:13:42 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

char	*build_full_path(char *path, char *cmd)
{
	char	*dup_path;
	char	*tmp_path;
	char	*full_path;

	dup_path = ft_strdup(path);
	tmp_path = ft_strjoin(dup_path, "/");
	free(dup_path);
	full_path = ft_strjoin(tmp_path, cmd);
	free(tmp_path);
	return (full_path);
}

char	**check_command(char *cmd_str, char **paths)
{
	char	*cmd_path;
	char	**cmd_tab;

	cmd_tab = ft_split(cmd_str, ' ');
	if (!cmd_tab)
		return (0);
	if (!access(cmd_tab[0], X_OK))
		return (cmd_tab);
	while (*paths)
	{
		cmd_path = build_full_path(*paths, cmd_tab[0]);
		if (!access(cmd_path, X_OK))
		{
			free(cmd_tab[0]);
			cmd_tab[0] = cmd_path;
			return (cmd_tab);
		}
		free(cmd_path);
		paths++;
	}
	return (cmd_tab);
}

int	check_arguments(int argc, char *argv[], char **paths, t_list **cmds_lst)
{
	int		i;
	char	**cmd;
	t_cmd	*new_cmd;

	i = 1;
	while (++i < argc - 1)
	{
		cmd = check_command(argv[i], paths);
		if (i == 2)
			new_cmd = create_cmd(cmd, 1, 0);
		else if (i == argc - 2)
			new_cmd = create_cmd(cmd, 0, 1);
		else
			new_cmd = create_cmd(cmd, 0, 0);
		if (!new_cmd)
		{
			ft_free_tab(paths);
			ft_lstclear(cmds_lst, &del_cmd);
			return (0);
		}
		ft_lstadd_back(cmds_lst, ft_lstnew(new_cmd));
	}
	ft_free_tab(paths);
	return (1);
}
