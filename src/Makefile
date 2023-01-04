NAME=pipex
LIBFT_SRC= \
	libft/libft.c
LEXER_SRC= \
	parser/lexer/lexer.c \
	parser/lexer/consumer.c \
	parser/lexer/quoted_string_consumer.c \
	parser/lexer/converter.c
PARSER_SRC= \
	parser/parser.c \
	parser/parser_getter.c \
	parser/parse_inputs.c \
	parser/checker.c
STATES_SRC= \
	states/states.c \
	states/error.c
PATH_EXPANDER_SRC= \
	path_expander/path_expander.c \
	path_expander/utils.c
PROCESSES_SRC= \
	processes/child.c \
	processes/parent.c \
	processes/safe_executor.c \
	processes/utils.c
LEXER_OBJS=${LEXER_SRC:.c=.o}
PARSER_OBJS=${PARSER_SRC:.c=.o}
LIBFT_OBJS=${LIBFT_SRC:.c=.o}
STATES_OBJS=${STATES_SRC:.c=.o}
PATH_EXPANDER_OBJS=${PATH_EXPANDER_SRC:.c=.o}
PROCESSES_OBJS=${PROCESSES_SRC:.c=.o}
OBJS=${LIBFT_OBJS} ${LEXER_OBJS} $(PARSER_OBJS) ${STATES_OBJS} ${PATH_EXPANDER_OBJS} ${PROCESSES_OBJS} pipex_main.o
CC=cc
CFLAGS= -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

pipex_main.o: ${PROCESSES_OBJS}

${PROCESSES_OBJS}: ${STATES_OBJS} ${PATH_EXPANDER_OBJS}

${STATES_OBJS}: ${PARSER_OBJS}

${PARSER_OBJS}: ${LEXER_OBJS}

${LEXER_OBJS}: ${LIBFT_OBJS}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

bonus: re