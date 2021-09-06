/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_arguments.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 21:13:39 by sehee             #+#    #+#             */
/*   Updated: 2021/08/18 17:10:21 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// ./pipex infile "awk '{max = 0; for ;}' [filename]" "cmd2 -la" outfile

void	outfile_checker(char *outfile, t_variables *info)
{
	if ((access(outfile, F_OK)) == -1)  
	{
		info->outfile_fd = open(outfile, O_CREAT, 0644);
		return ;
	}
	if ((access(outfile, W_OK)) == -1)
	{
		printf("permission denied: %s\n", outfile);
		exit(EXIT_FAILURE);
	}
	info->outfile_fd = open(outfile, O_WRONLY);
}

void	file_checker(char *infile, char *outfile, t_variables *info)
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
}

void	argument_checker(t_variables *info, int argc, char **argv)
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
