/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_to_tmpfile_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:50:53 by sehee             #+#    #+#             */
/*   Updated: 2021/09/26 10:22:12 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	heredoc_to_tmpfile(t_storage *info)
{
	int		tmp_fd;
	char	*line;
	char	*tmp_str;
	size_t	limiter_len;

	limiter_len = ft_strlen(info->limiter);
	info->infile_name = ".temporary";
	tmp_fd = open(info->infile_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	while (1)
	{
		ft_putstr_fd("pipe heredoc> ", STDOUT_FD);
		get_next_line(STDIN_FD, &line);
		if (limiter_len == ft_strlen(line) && \
			(!ft_strncmp(line, info->limiter, limiter_len)))
			break ;
		tmp_str = ft_strjoin(line, "\n");
		ft_putstr_fd(tmp_str, tmp_fd);
		ft_ptr_free(tmp_str);
	}
	ft_ptr_free(line);
	close(tmp_fd);
}
