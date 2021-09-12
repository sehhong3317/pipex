/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:29:08 by sehhong           #+#    #+#             */
/*   Updated: 2021/09/10 11:08:37 by sehee            ###   ########seoul.kr  */
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
# include <errno.h>
# include <string.h>
# include <sys/errno.h>

typedef struct	s_storage
{
	char	*infile_name;
	char	*outfile_name;
	char	**cmd1_arg;
	char	**cmd2_arg;
	int		pipe_fds[2];
	pid_t	pids[3];
	int		statuses[2];
}				t_storage;

typedef struct	s_chunk_info
{
	int	chunk_count;
	int	str_count;
	int	quote_flag;
}				t_chunk_info;

extern char **environ;

char	**ft_split_cmd(char *str);

void	arg_checker(t_storage *arg_arr, int argc, char **argv);

void	error_checker(char *str, int return_value);

void	fds_redirector_in_child1(t_storage *info);
void	fds_redirector_in_child2(t_storage *info);
void	cmd1_forker(t_storage *info, char **arr, char **environ);
void	cmd2_forker(t_storage *info, char **arr, char **environ);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char *str, char c);
char		*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);

#endif