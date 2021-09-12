#include "pipex.h"

char	**path_separator(char **environ)
{
	char **path_arr;

	while (*environ)
	{
		if (!ft_strncmp(*environ, "PATH=", 5))
		{
			*environ += 5;
			path_arr = ft_split(*environ, ':');		//free
			//while (*path_arr)
			// {
			// 	printf("%s\n", *path_arr);
			// 	path_arr++;
			// }
		}
		environ++;
	}
	return (path_arr);
}

void	execve_with_path(char **path_list)
{
	char	*tmp_path;
	char	*final_path;

	while (*path_list)
	{
		tmp_path = ft_strjoin(*path_list, "/");
		final_path = ft_strjoin(tmp_path, "grep");
		free(tmp_path);
		printf("%s\n", final_path);
		free(final_path);
		path_list++;
	}
}

int		main()
{
	int		ret_val;
	char *arr[] = {"grep", "mini", (char*)0};
	// char *haystack[] = {"USR=NOPE", "PATH=:/usr/local/bin:/usr/bin:/bin", (char*)0};
	// //printf("%d\n", count_chunk(haystack[1], ':'));
	// execve_with_path(path_separator(haystack));
	ret_val = execve(NULL, arr, 0);
	if (ret_val == -1)
	{
		printf("ERRNO: %d\n", errno);
		printf("ERROR MESSAGE: %s\n", strerror(errno));
	}
	return (0);
}