/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 13:03:19 by sehee             #+#    #+#             */
/*   Updated: 2021/09/19 08:58:41 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/pipex_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	while (n)
	{
		if ((*p1 != *p2) || !*p1 || !*p2)
			return (*p1 - *p2);
		n--;
		p1++;
		p2++;
	}
	return (0);
}
