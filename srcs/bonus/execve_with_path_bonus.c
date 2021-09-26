/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_with_path_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 12:59:57 by sehee             #+#    #+#             */
/*   Updated: 2021/09/26 13:32:03 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
		if (access(final_path, F_OK) == -1)
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
