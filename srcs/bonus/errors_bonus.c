/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 09:43:51 by sehee             #+#    #+#             */
/*   Updated: 2021/09/19 08:58:11 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/pipex_bonus.h"

void	error_print(char *error_str, char *error_str2)
{
	write(2, "zsh: ", 5);
	write(2, error_str, ft_strlen(error_str));
	if (error_str2 != NULL)
		write(2, error_str2, ft_strlen(error_str2));
	write(2, "\n", 1);
}

void	error_exit(char *error_str, char *error_str2, int return_value)
{
	if (return_value == -1)
		error_print(error_str, error_str2);
	exit(EXIT_FAILURE);
}

void	execve_error_exit(char *error_str, char *error_str2, int exit_status)
{
	error_print(error_str, error_str2);
	exit(exit_status);
}
