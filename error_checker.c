/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:32:47 by sehhong           #+#    #+#             */
/*   Updated: 2021/09/09 15:08:23 by sehhong          ###   ########.fr       */
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