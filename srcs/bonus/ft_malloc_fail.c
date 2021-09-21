/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_fail.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 10:54:06 by sehee             #+#    #+#             */
/*   Updated: 2021/09/19 08:58:20 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/pipex_bonus.h"

void	ft_malloc_fail(char **str, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
