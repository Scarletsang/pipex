/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:45:37 by htsang            #+#    #+#             */
/*   Updated: 2022/12/14 19:25:10 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "error.h"
#include <unistd.h>

int	pipe_with_eh(int pipefd[2])
{
	int	pipe_succeed;

	pipe_succeed = pipe(pipefd);
	if (pipe_succeed == -1)
	{
		perror(errno);
		exit(EXIT_FAILURE);
	}
	return (pipe_succeed);
}

pid_t	fork_with_eh(void)
{
	int	fork_succeed;

	fork_succeed = fork();
	if (fork_succeed == -1)
	{
		perror(errno);
		exit(EXIT_FAILURE);
	}
	return (fork_succeed);
}

int	execve_with_eh(const char *pathname, char *const argv[], \
char *const envp[])
{
	int	execve_succeed;

	execve_succeed = execve(pathname, argv, envp);
	if (execve_succeed == -1)
	{
		perror(errno);
	}
	return (execve_succeed);
}
