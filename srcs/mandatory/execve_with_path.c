/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_with_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 15:32:55 by sehee             #+#    #+#             */
/*   Updated: 2021/09/26 13:33:35 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**split_path_env(char **envp)
{
	char	**array_of_path;

	while (*envp)
	{
		if (!ft_strncmp(*envp, "PATH=", 5))
		{
			*envp += 5;
			array_of_path = ft_split(*envp, ':');
		}
		envp++;
	}
	return (array_of_path);
}

void	execve_with_path(char **array_of_path, char **cmd_arg, char **envp)
{
	char	*tmp_path;
	char	*final_path;

	while (*array_of_path)
	{
		tmp_path = ft_strjoin(*array_of_path, "/");
		final_path = ft_strjoin(tmp_path, cmd_arg[0]);
		ft_ptr_free(tmp_path);
		if (access(final_path, X_OK) == -1 && errno == ENOENT)
		{	
			ft_ptr_free(final_path);
			array_of_path++;
		}
		else
			break ;
	}
	if (!*array_of_path)
		print_execve_error_and_exit("command not found: ", cmd_arg[0], \
			ECMD_NOT_FND);
	execve(final_path, cmd_arg, envp);
	if (errno == EACCES)
		print_execve_error_and_exit("permission denied: ", cmd_arg[0], \
			EPERMS_DND);
	else
		print_execve_error_and_exit(strerror(errno), cmd_arg[0], EXIT_FAILURE);
}
