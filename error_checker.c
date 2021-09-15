/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:32:47 by sehhong           #+#    #+#             */
/*   Updated: 2021/09/15 09:56:01 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_checker(char *str, int return_value)
{
	if (return_value == -1)
	{
		printf("zsh: %s\n", str);
		exit(EXIT_FAILURE);
	}
}