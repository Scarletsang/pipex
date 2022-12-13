NAME=
SRC= 
OBJS=${SRC:.c=.o}
CC=cc
FLAGS= -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	@ar -rcs ${NAME} ${OBJS}

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

clean: 
	@rm -f ${OBJS}

fclean: clean
	@rm -f ${NAME}

re: fclean all

bonus: re