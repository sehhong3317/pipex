/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_arguments.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 21:13:39 by sehee             #+#    #+#             */
/*   Updated: 2021/09/07 15:50:42 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// ./pipex infile "awk '{max = 0; for ;}' [filename]" "cmd2 -la" outfile

void	outfile_checker(char *outfile, t_storage *info)
{
	if ((access(outfile, F_OK)) == -1)  
	{
		info->outfile_fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		return ;
	}
	if ((access(outfile, W_OK)) == -1)
	{
		printf("permission denied: %s\n", outfile);
		exit(EXIT_FAILURE);
	}
	info->outfile_fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	// info->outfile_fd = open(outfile, O_WRONLY);
	//printf("outfile의 fd: %d\n", info->outfile_fd);
}

void	file_checker(char *infile, char *outfile, t_storage *info)
{
	outfile_checker(outfile, info);
	if ((access(infile, F_OK)) == -1)
	{
		printf("no such file or directory: %s\n", infile);
		exit(EXIT_FAILURE);
	}
	if ((access(infile, R_OK)) == -1)
	{
		printf("permission denied : %s\n", infile);
		exit(EXIT_FAILURE);
	}
	info->infile_fd = open(infile, O_RDONLY);
	//printf("infile의 fd: %d\n", info->infile_fd);
}

void	argument_checker(t_storage *info, int argc, char **argv)
{
	if (argc != 5)
	{
		printf("%s\n", "Wrong number of arguments.\n");
		exit(EXIT_FAILURE);
	}
	info->infile_name = argv[INFILE_INDEX];
	info->outfile_name = argv[OUTFILE_INDEX];
	info->cmd1_arg = ft_split_cmd(argv[COMMAND1_INDEX]);		//free
	info->cmd2_arg = ft_split_cmd(argv[COMMAND2_INDEX]);		//free
	file_checker(info->infile_name, info->outfile_name, info);
}
