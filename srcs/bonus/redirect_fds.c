/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_fds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 15:14:13 by sehee             #+#    #+#             */
/*   Updated: 2021/09/19 08:59:01 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/pipex_bonus.h"

void	redirect_fds_in_1st_grandchild(t_storage *info)
{
	int	infile_fd;

	infile_fd = open(info->infile_name, O_RDONLY);
	error_exit("open() has failed", NULL, infile_fd);
	error_exit("dup2() has failed", NULL, dup2(infile_fd, STDIN_FD));
	close(infile_fd);
	error_exit("dup2() has failed", NULL, \
		dup2(info->pipe_fds[0][PIPE_WR_FD], STDOUT_FD));
	close(info->pipe_fds[0][PIPE_WR_FD]);
}

void	redirect_fds_in_nth_grandchild(t_storage *info, int cmd_idx)
{
	error_exit("dup2() has failed", NULL, \
		dup2(info->pipe_fds[cmd_idx - 1][PIPE_RD_FD], STDIN_FD));
	close(info->pipe_fds[cmd_idx - 1][PIPE_RD_FD]);
	error_exit("dup2() has failed", NULL, \
		dup2(info->pipe_fds[cmd_idx][PIPE_WR_FD], STDOUT_FD));
	close(info->pipe_fds[cmd_idx][PIPE_WR_FD]);
}

void	redirect_fds_in_last_grandchild(t_storage *info)
{
	int	outfile_fd;
	int	last_pipe_idx;

	last_pipe_idx = info->num_of_cmds - 2;
	error_exit("dup2() has failed", NULL, \
		dup2(info->pipe_fds[last_pipe_idx][PIPE_RD_FD], STDIN_FD));
	close(info->pipe_fds[last_pipe_idx][PIPE_RD_FD]);
	outfile_fd = open(info->outfile_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	error_exit("open() has failed", info->outfile_name, outfile_fd);
	error_exit("dup2() has failed", NULL, dup2(outfile_fd, STDOUT_FD));
	close(outfile_fd);
}
