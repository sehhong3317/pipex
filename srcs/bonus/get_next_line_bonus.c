/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:00:32 by sehee             #+#    #+#             */
/*   Updated: 2021/09/26 10:21:59 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	nl_locater(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

static int	line_assigner(int nl_idx, char **left, char **line)
{
	char	*tmp;

	(*left)[nl_idx] = '\0';
	*line = ft_strdup(*left);
	tmp = ft_strdup(*left + nl_idx + 1);
	free(*left);
	*left = tmp;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	ssize_t			read_num;
	char			buff[BUFFER_SIZE + 1];
	static char		*left[OPEN_MAX];

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || line == NULL)
		return (-1);
	read_num = read(fd, buff, BUFFER_SIZE);
	while (read_num > 0)
	{
		buff[read_num] = '\0';
		left[fd] = ft_strjoin(left[fd], buff);
		if (ft_strchr(left[fd], '\n'))
			return (line_assigner(nl_locater(left[fd]), &left[fd], line));
		read_num = read(fd, buff, BUFFER_SIZE);
	}
	if (read_num < 0)
		return (-1);
	if (ft_strchr(left[fd], '\n'))
		return (line_assigner(nl_locater(left[fd]), &left[fd], line));
	if (left[fd] == NULL)
		*line = ft_strdup("");
	else
		*line = left[fd];
	left[fd] = NULL;
	return (0);
}
