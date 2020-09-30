NAME		=	ft_cat

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
IFLAGS 		=	-I$(INC_PATH)
RM			=	rm -rf

INC_PATH 	=	includes
INC_NAME	=	ft_cat.h
SRC_PATH 	= 	srcs
SRC_NAME 	=	main.c ft_cat.c annex_functions.c
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
