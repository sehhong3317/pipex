/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:57:12 by sehhong           #+#    #+#             */
/*   Updated: 2021/09/16 17:29:38 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/pipex.h"

void	exit_for_child(int status)
{
	if (wifexited(status))
		exit(wexitstatus(status));
	else if (wifsignaled(status))
		exit(wtermsig(status));
	else
		exit(EXIT_FAILURE);
}

void	wait_and_exit_for_grand_children(t_storage info)
{
	int		status;
	int		cmd2_status;
	pid_t	reaped_pid;

	reaped_pid = 0;
	while (reaped_pid != -1)
	{
		reaped_pid = waitpid(-1, &status, 0);
		if (reaped_pid == info.pids[1])
			cmd2_status = status;
	}
	exit_for_child(cmd2_status);
}