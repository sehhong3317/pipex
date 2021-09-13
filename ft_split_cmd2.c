#include "pipex.h"

int		chunk_count(char *str, t_chunk_info *chunk_info)
{
	ft_memset(chunk_info, 0, sizeof(*chunk_info));
	while (*str)
	{
		if (*str == '\'')
		{
			if (chunk_info->quote_flag == 0)
				chunk_info->quote_flag++;
			else
				chunk_info->quote_flag--;
		}
		else if (*str == '"')
		{
			if (chunk_info->quote_flag == 1)
				chunk_info->quote_flag++;
			else
				chunk_info->quote_flag--;		
		}
		else if (*str == ' ')
		{
			if (!chunk_info->quote_flag && chunk_info->str_count)
			{
				chunk_info->chunk_count++;
				chunk_info->str_count = 0;
			}
			else if (chunk_info->quote_flag)
				chunk_info->str_count++;			
		}
		else
			chunk_info->str_count++;
		str++;
	}
	if (chunk_info->str_count)
		chunk_info->chunk_count++;
	return (chunk_info->chunk_count);
}

int		main(int argc, char **argv)
{
	t_chunk_info chunk_info;

	if (argc == 2)
		printf("%d\n", chunk_count(argv[1], &chunk_info));
	else
		printf("Only 1 argument needed.\n");
	return (0);
}