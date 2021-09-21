/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_macros_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 09:49:28 by sehee             #+#    #+#             */
/*   Updated: 2021/09/19 08:17:16 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/pipex_bonus.h"

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
