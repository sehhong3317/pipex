/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_fds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 15:14:18 by sehee             #+#    #+#             */
/*   Updated: 2021/09/25 15:30:01 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/pipex.h"

void	redirect_fds_in_1st_grandchild(t_storage *info)
{
	int	infile_fd;

	infile_fd = open(info->infile_name, O_RDONLY);
	print_error_and_exit("open() has failed", NULL, infile_fd);
	print_error_and_exit("dup2() has failed", NULL, dup2(infile_fd, STDIN_FD));
	close(infile_fd);
	print_error_and_exit("dup2() has failed", NULL, \
		dup2(info->pipe_fds[PIPE_WR_FD], STDOUT_FD));
	close(info->pipe_fds[PIPE_WR_FD]);
}

void	redirect_fds_in_2nd_grandchild(t_storage *info)
{
	int	outfile_fd;

	print_error_and_exit("dup2() has failed", NULL, \
		dup2(info->pipe_fds[PIPE_RD_FD], STDIN_FD));
	close(info->pipe_fds[PIPE_RD_FD]);
	outfile_fd = open(info->outfile_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	print_error_and_exit("open() has failed", NULL, outfile_fd);
	print_error_and_exit("dup2() has failed", NULL, \
		dup2(outfile_fd, STDOUT_FD));
	close(outfile_fd);
}