/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:28:45 by sehhong           #+#    #+#             */
/*   Updated: 2021/09/18 09:06:59 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/pipex.h"

static void	files_isvalid(char *infile, char *outfile)
{
	if (((access(infile, R_OK)) == -1)
		|| (((access(outfile, W_OK)) == -1) && errno == EACCES))
	{
		if ((access(infile, R_OK)) == -1)
			printf("zsh: %s: %s\n", strerror(errno), infile);
		if (((access(outfile, W_OK)) == -1) && errno == EACCES)
			printf("zsh: %s: %s\n", strerror(errno), outfile);
		exit(EXIT_FAILURE);
	}
}

void	arg_parser(t_storage *info, int argc, char **argv)
{
	if (argc != 5)
	{
		printf("zsh: %s", "Wrong number of arguments.\n");
		exit(EXIT_FAILURE);
	}
	files_isvalid(argv[INFILE_INDEX], argv[OUTFILE_INDEX]);
	info->infile_name = argv[INFILE_INDEX];
	info->outfile_name = argv[OUTFILE_INDEX];
	info->cmd1_arg = cmd_split(argv[COMMAND1_INDEX]);
	info->cmd2_arg = cmd_split(argv[COMMAND2_INDEX]);
}
