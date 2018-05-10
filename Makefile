##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##


CC	=	gcc

RM	= 	rm -f


SRC=		src/main.c	\
		src/get_line.c	\
		src/my_strlen.c	\
		src/my_putstr.c	\
		src/process.c 	\
		src/exec_prog.c \

OBJ=		$(SRC:.c=.o)

CFLAGS=		-I./include

CFLAGS=		-Wall -Wextra

NAME=		mysh

all:		$(NAME) clean

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		$(RM) $(OBJ)

fclean:
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
