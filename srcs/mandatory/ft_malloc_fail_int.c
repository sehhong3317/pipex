/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_fail_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 20:06:11 by sehee             #+#    #+#             */
/*   Updated: 2021/09/24 21:49:48 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/pipex.h"

void	ft_malloc_fail_int(int **arr, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}