/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_parse_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 09:36:18 by sehee             #+#    #+#             */
/*   Updated: 2021/09/19 08:55:36 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/pipex_bonus.h"

static void	isvalid_files(char *infile, char *outfile)
{
	if (((access(infile, R_OK)) == -1)
		|| (((access(outfile, W_OK)) == -1) && errno == EACCES))
	{
		if ((access(infile, R_OK)) == -1)
			error_print(strerror(errno), infile);
		if (((access(outfile, W_OK)) == -1) && errno == EACCES)
			error_print(strerror(errno), outfile);
		exit(EXIT_FAILURE);
	}
}

void	grandchild_pids_malloc(t_storage *info)
{
	info->grandchild_pids = (pid_t *)malloc(sizeof(pid_t) * info->num_of_cmds);
	if (!info->grandchild_pids)
		error_exit("malloc() has failed", NULL, -1);
}

void	pipe_fds_malloc(t_storage *info)
{
	int	i;

	info->pipe_fds = (int **)malloc(sizeof(int *) * (info->num_of_cmds - 1));
	if (!info->pipe_fds)
		error_exit("malloc() has failed", NULL, -1);
	i = 0;
	while (i < info->num_of_cmds)
	{
		info->pipe_fds[i] = (int *)malloc(sizeof(int) * 2);
		if (!info->pipe_fds[i])
		{
			ft_malloc_fail(info->pipe_fds, info->num_of_cmds);
			error_exit("malloc() has failed", NULL, -1);
		}
		i++;
	}
}

void	cmd_args_malloc(t_storage *info, char **argv)
{
	int	i;

	info->cmd_args = (char ***)malloc(sizeof(char **) * (info->num_of_cmds));
	if (!info->cmd_args)
		error_exit("malloc() has failed", -1);
	i = 0;
	while (i < info->num_of_cmds)
	{
		info->cmd_args[i] = cmd_split(argv[i + 2]);
		i++;
	}	
}

void	arguments_parse(t_storage *info, int argc, char **argv)
{
	int	cmd_i;

	info->infile_name = argv[1];
	info->outfile_name = argv[argc - 1];
	isvalid_files(info->infile_name, info->outfile_name);
	info->num_of_cmds = argc - 3;
	grandchild_pids_malloc(info);
	pipe_fds_malloc(info);
	cmd_args_malloc(info, argv);
}
