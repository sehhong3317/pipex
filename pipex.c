#include "pipex.h"

extern char **environ;

void	error_checker(char *str, int return_value, int error_value)
{
	if (return_value == error_value)
	{
		perror(str);
		exit(EXIT_FAILURE);
	}
}

int		main(int argc, char **argv)
{
	t_storage info;
	int gc1, gc2, status2;
	char *array1[] = {"cat" , (char*)0};
	char *array2[] = {"grep", "mini", (char*)0};

	argument_checker(&info, argc, argv);
	info.pid = fork();
	error_checker("fork() has failed.\n", info.pid, -1);
	if (info.pid == 0)
	{
		printf("\t나는 자식 프로세스의 PID는 %d\n", getpid());
		error_checker("pipe() has failed.\n", pipe(info.pipe_fds), -1);
		//손자 프로세스1 생성
		gc1 = fork();
		error_checker("fork() has failed.\n", info.pid, -1);
		if (gc1 == 0)
		{
			printf("\t나는 손자1 프로세스\n");
			close(info.pipe_fds[PIPE_READ]);

			dup2(info.infile_fd, STD_INPUT);
			close(info.infile_fd);

			dup2(info.pipe_fds[PIPE_WRITE], STD_OUTPUT);
			close(info.pipe_fds[PIPE_WRITE]);

			execve("/bin/cat", array1, environ);
			perror("1st execve() has failed.\n");
			exit(EXIT_FAILURE);
		}
		//손자 프로세스2 생성
		gc2 = fork();
		error_checker("fork() has failed.\n", info.pid, -1);
		if (gc2 == 0)
		{
			printf("\t나는 손자2 프로세스\n");
			close(info.pipe_fds[PIPE_WRITE]);

			dup2(info.pipe_fds[PIPE_READ], STD_INPUT);
			close(info.pipe_fds[PIPE_READ]);

			dup2(info.outfile_fd, STD_OUTPUT);
 			close(info.outfile_fd);
			
			execve("/usr/bin/grep", array2, environ);
			perror("2nd execve() has failed.\n");
			exit(EXIT_FAILURE);
		}
		//자식 프로세스에서 파이프닫기
		close(info.pipe_fds[PIPE_READ]);
		close(info.pipe_fds[PIPE_WRITE]);
		//자식 프로세스에서 wait로 두 손자 프로세스 기다리기
		while (wait(&status2) != -1);
		printf("\t자식 프로세스 끝\n");
	}
	else
	{
		printf("\t나는 부모 프로세스이고 PID는 %d 이고 내 자식 프로세스의 PID는 %d\n", getpid(), info.pid);
		wait(&info.status);
		printf("\t부모프로세스 끝\n");
	}
	return (0);
}
