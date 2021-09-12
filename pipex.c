/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:57:47 by sehhong           #+#    #+#             */
/*   Updated: 2021/09/10 09:41:26 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		main(int argc, char **argv)
{
	t_storage info;
	char *array1[] = {"cat" , (char*)0};
	char *array2[] = {"grep", "mini", (char*)0};

	arg_checker(&info, argc, argv);
	info.pids[0] = fork();
	error_checker("fork() has failed.", info.pids[0]);
	if (info.pids[0] == 0)
	{
		error_checker("pipe() has failed.", pipe(info.pipe_fds));
		//손자 프로세스1 생성
		cmd1_forker(&info, array1, environ);
		//손자 프로세스2 생성
		cmd2_forker(&info, array2, environ);
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
