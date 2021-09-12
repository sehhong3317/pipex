/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 18:25:44 by sehhong           #+#    #+#             */
/*   Updated: 2021/09/10 11:09:36 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pipex.h"

static void	my_strncpy(char *dst, char const *src, size_t src_len)
{
	size_t	i;

	i = 0;
	while (i < src_len)
	{
		dst[i] = src[i];
		i++;
	}
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1 || !s2)
		return (!s1 ? ft_strdup(s2) : ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret = (char*)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!ret)
		return (0);
	my_strncpy(ret, s1, s1_len);
	my_strncpy(ret + s1_len, s2, s2_len + 1);
	return (ret);
}
