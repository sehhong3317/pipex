/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:57:47 by sehhong           #+#    #+#             */
/*   Updated: 2021/09/16 10:48:12 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		main(int argc, char **argv, char **envp)
{
	t_storage 	info;
	pid_t		pid;
	int			status;

	arg_parser(&info, argc, argv);
	pid = fork();
	error_checker("fork() has failed.", pid);
	if (pid == 0)
	{
		error_checker("pipe() has failed.", pipe(info.pipe_fds));
		cmd1_forker(&info, envp);
		cmd2_forker(&info, envp);
		close(info.pipe_fds[PIPE_READ]);
		close(info.pipe_fds[PIPE_WRITE]);
		wait_and_exit_for_grand_children(info);
	}
	else
	{	
		waitpid(pid, &status, 0);
		exit_for_child(status);
	}

}
