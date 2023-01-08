/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:58:24 by htsang            #+#    #+#             */
/*   Updated: 2023/01/08 18:23:28 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_heredoc.h"

static t_pipex_exit_code	pipex_heredoc(int fd, const char *delimiter)
{
	char	*line;

	while (1)
	{
		write(STDOUT_FILENO, "pipex> ", 7);
		line = get_next_line(STDIN_FILENO);
		if (!line)
		{
			return (PROGRAM_FAILURE);
		}
		if (is_delimiter_with_new_line(line, delimiter))
		{
			free(line);
			return (PROGRAM_SUCCESS);
		}
		write(fd, line, ft_strlen(line));
		free(line);
	}
	return (PROGRAM_FAILURE);
}

static t_pipex_parser	*parse_heredoc(t_pipex_parser *parser)
{
	parser_walk_forward(parser);
	parser->data = (void *) parser->inputs[0];
	parser->data_type = CONST_STRING;
	return (parser);
}

static t_pipex_exit_code	run_heredoc(t_pipex_states *states)
{
	int					*next_pipe;
	t_pipex_exit_code	exit_code;

	next_pipe = get_next_pipe(states);
	parser_walk_forward(get_parser(states));
	exit_code = pipex_heredoc(next_pipe[1], \
		get_parser_filename(get_parser(states)));
	close_pipe(next_pipe);
	return (exit_code);
}

static void	fork_heredoc(t_pipex_states *states)
{
	t_pipex_exit_code	exit_code;
	int					wstatus;
	pid_t				pid;

	parse_heredoc(get_parser(states));
	safe_pipe(get_next_pipe(states), states);
	pid = safe_fork(states);
	if (pid == 0)
	{
		exit_code = run_heredoc(states);
		free_parser_data(get_parser(states));
		free(states);
		exit(exit_code);
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
		write(STDOUT_FILENO, \
			"usage: ./pipex here_doc LIMITER cmd1 cmd2 ... outfile\n", 54);
		return (EXIT_FAILURE);
	}
	states = init_states(argv, envp);
	if (!states)
	{
		return (EXIT_FAILURE);
	}
	fork_heredoc(states);
	while (!check_next_command_is_end(get_parser(states)))
	{
		fork_command(states);
	}
	return (fork_command_to_outfile(O_APPEND | O_CREAT | O_RDWR, states));
}
