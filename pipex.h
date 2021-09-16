/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:29:08 by sehhong           #+#    #+#             */
/*   Updated: 2021/09/16 09:24:09 by sehhong          ###   ########.fr       */
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
	pid_t	pids[2];
}				t_storage;

typedef struct	s_chunk_info
{
	int		chunk_count;
	int		str_count;
	int		quote_flag;
	char	delimiter;
}				t_chunk_info;

char	**cmd_split(char *str);

void	arg_parser(t_storage *arg_arr, int argc, char **argv);

void	error_checker(char *str, int return_value);

void	fds_redirector_in_child1(t_storage *info);
void	fds_redirector_in_child2(t_storage *info);
void	cmd1_forker(t_storage *info, char **envp);
void	cmd2_forker(t_storage *info, char **envp);

void	*ft_memset(void *b, int c, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char *str, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
void	ft_ptr_free(char *ptr);
void	ft_malloc_fail(char **str, int max);
void	ft_strcopy_with_delimiter(char *dest, char *src, char c);



char	**path_separator(char **envp);
void	execve_with_path(char **path_list, char **cmd_arg, char **envp);

#endif