/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcopy_with_delimiter.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 09:41:51 by sehee             #+#    #+#             */
/*   Updated: 2021/09/15 09:57:36 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_strcopy_with_delimiter(char *dest, char *src, char c)
{
	while (*src != '\0' && *src != c)
		*dest++ = *src++;
	*dest = '\0';
}