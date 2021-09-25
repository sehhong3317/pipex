/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_fail_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 20:05:47 by sehee             #+#    #+#             */
/*   Updated: 2021/09/24 20:05:48 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/pipex_bonus.h"

void	ft_malloc_fail_str(char **str, int max)
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
