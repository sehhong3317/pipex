/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 08:28:44 by sehee             #+#    #+#             */
/*   Updated: 2021/09/19 07:37:50 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONOUS_H

# include <unistd.h>
# include <errno.h>
# include <fcntl.h>

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1
# define PIPE_RD_FD 0
# define PIPE_WR_FD	1
# define STDIN_FD	0
# define STDOUT_FD	1
# define ECMD_NOT_FND	127
# define PERMS_DND		126

typedef struct	s_storage
{
	char	*infile_name;
	char	*outfile_name;
	char	***cmd_args;
	int		num_of_cmds;
	int		**pipe_fds;
	pid_t	*grandchild_pids;
}				t_storage;

void	error_print(char *error_str, char *error_str2);

//libft functions


#endif