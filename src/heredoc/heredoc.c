/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:58:24 by htsang            #+#    #+#             */
/*   Updated: 2023/01/07 00:30:17 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex_heredoc.h"

static int	pipex_heredoc(const char *delimiter)
{
	char	*line;

	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
		{
			return (1);
		}
		write(1, line, ft_strlen(line));
		if (is_delimiter_with_new_line(line, delimiter))
		{
			free(line);
			close(fd);
			return (0);
		}
		write(fd, line, ft_strlen(line));
		free(line);
	}
	return (1);
}

int	run_heredoc(t_pipex_states *states)
{
	int	*next_pipe;

	next_pipe = get_next_pipe(states);
	dup2(next_pipe[0], STDIN_FILENO);
	dup2(next_pipe[1], STDOUT_FILENO);
	close_pipe(next_pipe);
	parser_walk_forward(get_parser(states));
	if (pipex_heredoc(get_parser_filename(get_parser(states))))
	{
		free_parser_data(get_parser(states));
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	fork_command_from_heredoc(t_pipex_states *states)
{
	int		wstatus;
	pid_t	pid;

	safe_pipe(get_next_pipe(states), states);
	pid = safe_fork(states);
	if (pid == 0)
	{
		exit(run_heredoc(states));
	}
	waitpid(pid, &wstatus, 0);
	if (!WIFEXITED(wstatus))
	{
		free(states);
		exit(WEXITSTATUS(wstatus));
	}
	switch_pipe(states);
	parser_walk_forward(get_parser(states));
}

t_pipex_parser	*parse_heredoc(t_pipex_parser *parser)
{
	if (is_heredoc(*(parser->inputs)))
	{
		parser_walk_forward(parser);
		parser->data = (void *) parser->inputs[0];
		parser->data_type = CONST_STRING;
		return (parser);
	}
	return (NULL);
}
