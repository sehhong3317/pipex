/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:27:40 by sehhong           #+#    #+#             */
/*   Updated: 2021/09/13 09:25:13 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fds_redirector_in_child1(t_storage *info)
{
	int infile_fd;

	infile_fd = open(info->infile_name, O_RDONLY);
	error_checker("open() has failed.", infile_fd);
	error_checker("dup2() has failed.", dup2(infile_fd, STD_INPUT));
	close(infile_fd);
	error_checker("dup2() has failed.", dup2(info->pipe_fds[PIPE_WRITE], \
																STD_OUTPUT));
	close(info->pipe_fds[PIPE_WRITE]);
}

void	fds_redirector_in_child2(t_storage *info)
{
	int outfile_fd;

	error_checker("dup2() has failed.", dup2(info->pipe_fds[PIPE_READ], \
																	STD_INPUT));
	close(info->pipe_fds[PIPE_READ]);
	outfile_fd = open(info->outfile_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	error_checker("open() has failed.", outfile_fd);
	error_checker("dup2() has failed.", dup2(outfile_fd, STD_OUTPUT));
	close(outfile_fd);
}

void	cmd1_forker(t_storage *info, char **envp)
{
	info->pids[1] = fork();
	error_checker("fork() has failed.\n", info->pids[1]);
	if (info->pids[1] == 0)
	{
		close(info->pipe_fds[PIPE_READ]);
		fds_redirector_in_child1(info);
		execve_with_path(path_separator(envp), info->cmd1_arg, envp);
	}
}

void	cmd2_forker(t_storage *info, char **envp)
{
	info->pids[2] = fork();
	error_checker("fork() has failed.\n", info->pids[2]);
	if (info->pids[2] == 0)
	{
		close(info->pipe_fds[PIPE_WRITE]);
		fds_redirector_in_child2(info);
		execve_with_path(path_separator(envp), info->cmd2_arg, envp);
	}
}
