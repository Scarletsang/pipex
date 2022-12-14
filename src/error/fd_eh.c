/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_eh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:49:46 by htsang            #+#    #+#             */
/*   Updated: 2022/12/14 19:25:07 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	close_pipe_with_eh(int pipe[2])
{
	handle_err(close(pipe[0]));
	handle_err(close(pipe[1]));
}

void	close_with_eh(int fd)
{
	handle_err(close(fd));
}

int		open_with_eh(char *filename, int permission)
{
	return (handle_err(open(filename, permission)));
}
