/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:52:34 by sehee             #+#    #+#             */
/*   Updated: 2021/09/07 10:57:42 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define EXIT_FAILURE	1
# define EXIT_SUCCESS	0
# define INFILE_INDEX	1
# define COMMAND1_INDEX	2
# define COMMAND2_INDEX	3
# define OUTFILE_INDEX	4
# define STD_INPUT		0
# define STD_OUTPUT		1
# define PIPE_READ		0
# define PIPE_WRITE		1

# include <unistd.h>		//pipe, fork, execve, dup2, access
# include <stdio.h>			//perror, printf
# include <sys/wait.h>		//waitpid
# include <stdlib.h>		//exit
# include <fcntl.h>			//open

typedef struct	s_storage
{
	char	*infile_name;
	char	*outfile_name;
	char	**cmd1_arg;
	char	**cmd2_arg;
	int		infile_fd;
	int		outfile_fd;
	int		pipe_fds[2];
	pid_t	pid;
	int		status;
}				t_storage;

typedef struct	s_chunk_info
{
	int	chunk_count;
	int	str_count;
	int	quote_flag;
}				t_chunk_info;

char	**ft_split_cmd(char *str);
void	*ft_memset(void *b, int c, size_t len);
void	outfile_checker(char *outfile, t_storage *arg_arr);
void	file_checker(char *infile, char *outfile, t_storage *arg_arr);
void	argument_checker(t_storage *arg_arr, int argc, char **argv);

#endif