#include "pipex.h"

void	find_command(char **environ)
{
	char **path_arr;

	while (*environ)
	{
		if (!ft_strncmp(*environ, "PATH=", 5))
		{
			*environ += 5;
			path_arr = ft_split(*environ, ':');		//free
			
		}
		environ++:
	}

}