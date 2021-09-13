#include "pipex.h"

char	**path_separator(char **envp)
{
	char **path_list;

	while (*envp)
	{
		if (!ft_strncmp(*envp, "PATH=", 5))
		{
			*envp += 5;
			path_list = ft_split(*envp, ':');
		}
		envp++;
	}
	return (path_list);
}

void	execve_with_path(char **path_list, char **cmd_arg, char **envp)
{
	char	*tmp_path;
	char	*final_path;

	while (*path_list)
	{
		tmp_path = ft_strjoin(*path_list, "/");
		final_path = ft_strjoin(tmp_path, cmd_arg[0]);
		free_ptr(tmp_path);
		if (access(final_path, X_OK) == -1 && errno == ENOENT)
		{	
			free_ptr(final_path);
			path_list++;
		}
		else
			break;
	}
	if (*path_list != NULL)		//해당 파일이 존재할때!
		error_checker(strerror(errno), execve(final_path, cmd_arg, envp));
	else						//해당 파일이 존재하지 않을 때!
		error_checker(strerror(ENOENT), -1);
}
