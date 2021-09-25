/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:35:47 by sehhong           #+#    #+#             */
/*   Updated: 2021/09/25 16:11:11 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_storage	info;
	pid_t		pid;
	int			status;

	parse_arguments(&info, argc, argv);
	pid = fork();
	print_error_and_exit("fork() has failed", NULL, pid);
	if (pid == 0)
	{
		fork_1st_grandchild(&info, envp);
		fork_2nd_grandchild(&info, envp);
		wait_and_exit_for_grand_children(info);
	}
	else
	{	
		waitpid(pid, &status, 0);
		exit_for_child(status);
	}
}
