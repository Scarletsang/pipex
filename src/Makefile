NAME=pipex
LIBFT_SRC= \
	libft/libft.c
LEXER_SRC= \
	parser/lexer/lexer.c \
	parser/lexer/structural_consumer.c \
	parser/lexer/word_consumer.c \
	parser/lexer/converter.c \
	parser/lexer/converter_copier.c
PARSER_SRC= \
	parser/parser.c \
	parser/parser_getter.c \
	parser/parse_inputs.c \
	parser/checker.c \
	parser/path_expander.c
STATES_SRC= \
	states/states.c \
	states/error.c \
	states/error_printer.c \
	states/utils.c
PROCESSES_SRC= \
	processes/child.c \
	processes/parent.c \
	processes/safe_executor.c \
	processes/utils.c
HEREDOC_SRC= \
	heredoc/get_next_line/get_next_line.c \
	heredoc/get_next_line/get_next_line_utils.c \
	heredoc/heredoc.c \
	heredoc/utils.c
LEXER_OBJS=${LEXER_SRC:.c=.o}
PARSER_OBJS=${PARSER_SRC:.c=.o}
LIBFT_OBJS=${LIBFT_SRC:.c=.o}
STATES_OBJS=${STATES_SRC:.c=.o}
PROCESSES_OBJS=${PROCESSES_SRC:.c=.o}
HEREDOC_OBJS=${HEREDOC_SRC:.c=.o}
OBJS=${LIBFT_OBJS} ${LEXER_OBJS} $(PARSER_OBJS) ${STATES_OBJS} ${PROCESSES_OBJS} ${HEREDOC_OBJS} pipex_main.o
CC=cc
CFLAGS= -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME} && \
		echo "Compilation successful"

pipex_main.o: ${PROCESSES_OBJS} ${HEREDOC_OBJS}

${HEREDOC_OBJS}: ${PROCESSES_OBJS}

${PROCESSES_OBJS}: ${STATES_OBJS}

${STATES_OBJS}: ${PARSER_OBJS}

${PARSER_OBJS}: ${LEXER_OBJS}

${LEXER_OBJS}: ${LIBFT_OBJS}

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@rm -f ${OBJS}

fclean: clean
	@rm -f ${NAME}

re: fclean all

bonus: re