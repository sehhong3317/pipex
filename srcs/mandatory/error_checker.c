/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:29:52 by sehhong           #+#    #+#             */
/*   Updated: 2021/09/16 17:30:07 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/pipex.h"

void	error_checker(char *str, int return_value)
{
	if (return_value == -1)
	{
		printf("zsh: %s\n", str);
		exit(EXIT_FAILURE);
	}
}
