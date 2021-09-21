/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_macros.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:25:29 by sehhong           #+#    #+#             */
/*   Updated: 2021/09/16 16:30:19 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/pipex.h"

int	wstatus(int status)
{
	return (status & 0177);
}

int	wifexited(int status)
{
	return (wstatus(status) == 0);
}

int	wexitstatus(int status)
{
	return ((wstatus(status) >> 8) & 0x000000ff);
}

int	wifsignaled(int status)
{
	return (wstatus(status) != 0177 && wstatus(status) != 0);
}

int	wtermsig(int status)
{
	return (wstatus(status));
}
