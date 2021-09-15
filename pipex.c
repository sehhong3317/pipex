/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:57:47 by sehhong           #+#    #+#             */
/*   Updated: 2021/09/15 10:44:50 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		main(int argc, char **argv, char **envp)
{
	t_storage info;

	arg_parser(&info, argc, argv);
	info.pids[0] = fork();
	error_checker("fork() has failed.", info.pids[0]);
	if (info.pids[0] == 0)
	{
		error_checker("pipe() has failed.", pipe(info.pipe_fds));
		//손자 프로세스1 생성
		cmd1_forker(&info, envp);
		//손자 프로세스2 생성
		cmd2_forker(&info, envp);
		//자식 프로세스에서 파이프닫기
		close(info.pipe_fds[PIPE_READ]);
		close(info.pipe_fds[PIPE_WRITE]);
		//자식 프로세스에서 wait로 두 손자 프로세스 기다리기
		while (wait(&info.statuses[1]) != -1);
	}
	else
		wait(&info.statuses[0]);
	return (0);
}
