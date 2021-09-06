#include "pipex.h"

// extern char **environ;

// int main()
// {
//     int i = 0;
//     printf("=== environment list ===\n");
//     for(i=0; environ[i];i++)
//     {
//         printf("<%2d>: %s\n", i, environ[i]);
//     }
//     return 0;
// }

int main(int argc, char **argv, char **envp)
{
	//t_variables info;
	char *array[] = {"ls", "-al", (char*)0};

	//argument_checker(&info, argc, argv);
	printf("%d %s\n", argc, argv[1]);
	execve("/bin/ls", array, envp);
	printf("You did wrong!\n");
	return (0);
}