/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:02:50 by sehee             #+#    #+#             */
/*   Updated: 2021/07/27 12:43:35 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int		chunk_counter(char *str, t_chunk_info *chunk_info)
{
	ft_memset(chunk_info, 0, sizeof(*chunk_info));
	while (*str)
	{
		if (*str == '\'')
		{
			chunk_info->quote_flag = !(chunk_info->quote_flag);
			chunk_info->str_count++;
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

static	void	str_copy(char *dest, char *src, char c)
{
	if (c == ' ')
	{
		while (*src != '\0' && *src != c)
			*dest++ = *src++;
	}
	else if (c == '\'')
	{
		*dest++ = *src++;
		while (*src != '\0' && *src != c)
			*dest++ = *src++;
		*dest++ =  *src++;
	}
	*dest = '\0';
}

static char	*mallocator(t_chunk_info *ck, char *str, int i, char **ret)
{
	int		j;

	if (ck->quote_flag == 0)
		ret[ck->chunk_count] = (char*)malloc(sizeof(char) * (i + 1));
	else
		ret[ck->chunk_count] = (char*)malloc(sizeof(char) * (i + 2));
	if (!ret)
	{
		j = -1;
		while (++j < ck->chunk_count)
			free(ret[j]);
		free(ret);
		printf("Malloc() failed.\n");
		exit(EXIT_FAILURE);
	}
	if (ck->quote_flag == 0)
		str_copy(ret[ck->chunk_count], str, ' ');
	else
		str_copy(ret[ck->chunk_count], str, '\'');
	ck->chunk_count++;
	if (ck->quote_flag == 0)
		str += i;
	else
		str += (i + 1);
	return (str);
}

static void		str_counter_mallocator(char **ret, char *str, char c)
{
	int	i;
	t_chunk_info ck;

	ft_memset(&ck, 0, sizeof(ck));
	while (*str)
	{
		if (*str == ' ')   //' '일때는 그냥 넘어가기
			str++;
		else
		{
			i = 0;
			if (str[i] == '\'')   //쉼표만났을 때
			{
				ck.quote_flag = 1;
				i++;
				c = '\'';
			}
			else
				c = ' ';
			while (str[i] != '\0' && str[i] != c)
				i++;
			str = mallocator(&ck, str, i, ret);
			ck.quote_flag = 0;
		}
	}
}

char			**ft_split_cmd(char *str)
{
	char	**ret;
	int		len_chunk;
	t_chunk_info chunk_info;

	if (str == NULL)
		return (NULL);
	len_chunk = chunk_counter(str, &chunk_info);
	ret = (char**)malloc(sizeof(char*) * (len_chunk + 1));
	if (!ret)
		return (NULL);
	ret[len_chunk] = 0;
	str_counter_mallocator(ret, str, ' ');
	return (ret);
}

// int	main(int argc, char **argv)
// {
// 	int				i;
// 	int				chunk_num;
// 	char			**ret;
// 	t_chunk_info	chunk_info;

// 	if (argc == 2)
// 	{
// 		chunk_num = chunk_counter(argv[1], &chunk_info);
// 		printf("%d\n", chunk_num);
// 	}
// 	else
// 		return (0);
// 	ret = ft_split_cmd(argv[1]);
// 	i = 0;
// 	while (i < chunk_num)
// 	{
// 		printf("%s\n", ret[i]);
// 		i++;
// 	}	
// 	return (0);
// }