NAME=pipex
PARSER_SRC= \
	parser/parser.c \
	parser/parser_state.c \
	parser/parse_inputs.c \
	parser/checker.c
STATES_SRC= \
	states/states.c \
	states/error.c
PROCESSES_SRC= \
	processes/child.c \
	processes/parent.c \
	processes/safe_executor.c \
	processes/utils.c
MAIN_SRC= \
	pipex_main.c
PARSER_OBJS=${PARSER_SRC:.c=.o}
STATES_OBJS=${STATES_SRC:.c=.o}
PROCESSES_OBJS=${PROCESSES_SRC:.c=.o}
OBJS=libft/libft.a $(PARSER_OBJS) ${STATES_OBJS} ${PROCESSES_OBJS} pipex_main.o
CC=cc
CFLAGS= -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

${PROCESSES_OBJS}: ${STATES_OBJS}

${STATES_OBJS}: ${PARSER_OBJS}

${PARSER_OBJS}: libft/libft.a

libft/libft.a:
	make -C libft all

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	make -C libft clean
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

bonus: re