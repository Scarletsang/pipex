/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:58:24 by htsang            #+#    #+#             */
/*   Updated: 2023/01/07 15:59:05 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_heredoc.h"

static int	pipex_heredoc(int fd, const char *delimiter)
{
	char	*line;

	while (1)
	{
		write(STDOUT_FILENO, "pipex> ", 7);
		line = get_next_line(STDIN_FILENO);
		if (!line)
		{
			return (EXIT_FAILURE);
		}
		if (is_delimiter_with_new_line(line, delimiter))
		{
			free(line);
			return (EXIT_SUCCESS);
		}
		write(fd, line, ft_strlen(line));
		free(line);
	}
	return (EXIT_FAILURE);
}

static t_pipex_parser	*parse_heredoc(t_pipex_parser *parser)
{
	parser_walk_forward(parser);
	parser->data = (void *) parser->inputs[0];
	parser->data_type = CONST_STRING;
	return (parser);
}

static int	run_heredoc(t_pipex_states *states)
{
	int	*next_pipe;
	int	exit_code;

	next_pipe = get_next_pipe(states);
	parser_walk_forward(get_parser(states));
	exit_code = pipex_heredoc(next_pipe[1], \
		get_parser_filename(get_parser(states)));
	close_pipe(next_pipe);
	return (exit_code);
}

static void	fork_command_from_heredoc(t_pipex_states *states)
{
	int		wstatus;
	pid_t	pid;

	parse_heredoc(get_parser(states));
	safe_pipe(get_next_pipe(states), states);
	pid = safe_fork(states);
	if (pid == 0)
	{
		wstatus = run_heredoc(states);
		free_parser_data(get_parser(states));
		free(states);
		exit(wstatus);
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

int	heredoc_main(int argc, const char **argv, char *const *envp)
{
	t_pipex_states	*states;

	if (argc < 6)
	{
		return (EXIT_FAILURE);
	}
	states = init_states(argv, envp);
	if (!states)
	{
		return (EXIT_FAILURE);
	}
	fork_command_from_heredoc(states);
	while (!check_next_command_is_end(get_parser(states)))
	{
		fork_command(states);
	}
	return (fork_command_to_outfile(O_APPEND | O_CREAT | O_RDWR, states));
}
