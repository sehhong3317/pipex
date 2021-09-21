/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 08:50:23 by sehee             #+#    #+#             */
/*   Updated: 2021/09/19 08:55:14 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/pipex_bonus.h"

void	multi_pipe(int argc, char **argv, char **envp)
{
	t_storage	info;
	pid_t		pid;
	int			status;
	int			cmd_idx;

	arguments_parse(&info, argc, argv);
	pid = fork();
	error_exit("fork() has failed", NULL, pid);
	if (pid == 0)
	{
		fork_1st_grandchild(&info, envp);
		cmd_idx = 1;
		while (cmd_idx < info.num_of_cmds - 1)
			fork_nth_grandchild(&info, cmd_idx++, envp);
		fork_last_grandchild(&info, envp);
		wait_and_exit_for_grandchildren(info);
	}
	else
	{
		waitpid(pid, &status, 0);
		exit_for_child(status);
	}
}

int	main(int argc, char **argv, char **envp)
{
	if (argc < 5)
		error_exit("Number of arguments has to be more than 3.", NULL, -1);
	if (!ft_strncmp(argv[1], "here_doc", 8))
		here_doc();
	else
		multi_pipe(argc, argv, envp);
}
