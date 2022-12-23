# Please only change the following line
TARGET_NAMES=

NAME=debug.out
TARGET_DIR=../src
TESTS:=$(shell find tests -name '*.c')
TARGETS=${addprefix ${TARGET_DIR},${TARGET_NAMES}}
TESTS_OBJS=${TESTS:.c=.o}
CC=cc
CFLAGS= -g3 -fsanitize=address

all: ${NAME}

${NAME}: targetall ${TESTS_OBJS}
ifeq ($(findstring .a, ${TARGETS}),)
	@${CC} ${CFLAGS} -Wformat main.c ${TESTS_OBJS} ${TARGETS:.c=.o} -o ${NAME} && \
	echo "Success compiling with the target binary ${TARGET_NAMES}!"
else
	@${CC} ${CFLAGS} -Wformat main.c ${TESTS_OBJS} -L./${TARGET_DIR} -l$(patsubst lib%.a,%,${TARGET_NAMES}) -o ${NAME} && \
	echo "Success compiling with the target library ${TARGET_NAMES}!"
endif

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

clean: targetclean
	@rm -f ${TESTS_OBJS}

fclean: targetfclean clean
	@rm -f ${NAME}

re: fclean all

# Target rules

targetall:
	@make CFLAGS="${CFLAGS} -Wall -Wextra -Werror" re -C ${TARGET_DIR}

targetclean:
	@make clean -C ${TARGET_DIR}

targetfclean:
	@make fclean -C ${TARGET_DIR}