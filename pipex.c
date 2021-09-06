/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:13:27 by sehee             #+#    #+#             */
/*   Updated: 2021/08/18 19:45:38 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

extern char **environ;

void	error_checker(char *str, int return_value, int error_value)
{
	if (return_value == error_value)
	{
		perror(str);
		exit(EXIT_FAILURE);
	}
}

void	fds_arranger(int )

int		main(int argc, char **argv, char **envp)
{
	t_variables	info;

	argument_checker(&info, argc, argv);
	error_checker("pipe() has failed.\n", pipe(info.pipe_fds), -1);
	info.pid = fork();
	error_checker("fork() has failed.\n", info.pid, -1);
	if (info.pid == 0)		//child process
	{
		printf("I'm child process. My pid is %d\n", (int)info.pid);
		close(info.pipe_fds[PIPE_READ]);
		dup2(info.infile_fd, STD_INPUT);
		close(info.infile_fd);
		dup2(info.pipe_fds[PIPE_WRITE], STD_OUTPUT);
		close(info.pipe_fds[PIPE_WRITE]);			//error처리: dup2, close, execve
		execve(info.cmd1_arg[0], info.cmd1_arg, envp);
		perror("If you see this, execve() has failed.");
	}
	else					//parent process
	{
		printf("I'm parent process. I wait for my child %d.\n", (int)info.pid);
		waitpid(info.pid, &info.status, 0);
		if (WIFEXITED(info.status))
			printf("Parent successfully ends with its child.\n");
		else
			printf("Parent has failed to wait its child.\n");
		close(info.pipe_fds[PIPE_WRITE]);	
		dup2(info.outfile_fd, STD_OUTPUT);
		close(info.outfile_fd);
		dup2(info.pipe_fds[PIPE_READ], STD_INPUT);
		close(info.pipe_fds[PIPE_READ]);
		execve(info.cmd2_arg[0], info.cmd2_arg, envp);
		perror("execve() has failed.\n");
	}
	return (0);
}