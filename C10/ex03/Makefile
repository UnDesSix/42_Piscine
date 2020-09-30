NAME		=	ft_hexdump
C			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
IFLAGS 		=	-I$(INC_PATH)
RM			=	rm -rf
INC_PATH 	=	includes
INC_NAME	=	ft_hexdump.h
SRC_PATH 	= 	srcs
SRC_NAME 	=	hex_copy_hexa_with_c.c hex_copy_line.c hex_counter.c hex_create_line.c hex_error.c hex_main.c hex_read_file.c hex_str_functions.c hex_struct.c main.c

INC 		=	$(addprefix $(INC_PATH)/, $(INC_NAME))
SRC 		=	$(addprefix $(SRC_PATH)/, $(SRC_NAME))

.SUFFIXES: 		.c .o .h

OBJ 		=	 $(SRC:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJ) $(INC)
				${CC} ${CFLAGS} -o ${NAME} ${OBJ}

%.o: %.c
				$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean		:
				$(RM) $(OBJ)

fclean		:	clean
				$(RM) $(NAME)

re			: 	fclean all

.PHONY: 		all fclean clean re
