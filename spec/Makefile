NAME=debug.out
TARGET_DIR=../src

LEXER_SRCS=${TARGET_DIR}/parser/lexer/*.c
LIBFT_SRCS=${TARGET_DIR}/libft/libft.c
PARSER_SRCS=${TARGET_DIR}/parser/*.c ${TARGET_DIR}/path_expander/*.c ${LIBFT_SRCS} ${LEXER_SRCS}
STATES_SRCS=${TARGET_DIR}/states/*.c ${PARSER_SRCS}
PROCESSES_SRCS=${TARGET_DIR}/processes/*.c ${STATES_SRCS}

TESTS:=$(shell find tests -name '*.c')
TESTS_OBJS=${TESTS:.c=.o}

CC=cc
CFLAGS= -g3 -Wall -Wextra -Werror -Wformat
CFLAGS += -fsanitize=address

lexer:
	${CC} ${CFLAGS} tests/test_lexer.c tests/printers.c ${LEXER_SRCS} -o ${NAME}

parser:
	${CC} ${CFLAGS} tests/test_parser.c tests/printers.c ${PARSER_SRCS} -o ${NAME}

states:
	${CC} ${CFLAGS} tests/test_states.c tests/printers.c ${STATES_SRCS} -o ${NAME}

# targetall:
# 	make -C ${TARGET_DIR} ${PROCESSES_OBJS}