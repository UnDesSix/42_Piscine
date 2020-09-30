NAME		=	rush-02

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
IFLAGS 		=	-I$(INC_PATH)
RM			=	rm -rf

INC_PATH 	=	includes
INC_NAME	=	libft.h
SRC_PATH	= 	srcs
SRC_NAME 	=	annex_functions_a.c annex_functions_b.c annex_functions_c.c display_nb.c ft_check_dict.c ft_clear_data.c ft_split.c ft_tab_malloc.c main.c display_nb_bis.c ft_free_functions.c
INC 		=	$(addprefix $(INC_PATH)/, $(INC_NAME))
SRC 		=	$(addprefix $(SRC_PATH)/, $(SRC_NAME))

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
