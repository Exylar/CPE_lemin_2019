##
## EPITECH PROJECT, 2019
## PSU_minishell_bootstrap
## File description:
## Makefile
##

SRC	=	src/main.c	\
        src/get_map.c   \
		src/get_map2.c   \
        src/util_map.c  \
        src/my_pars.c   \
        src/pathfinder.c	\
		src/pathfinder_bis.c	\
        src/test_map.c  \
		src/move_ants.c \
		src/move_ants_tool.c \
		src/print_map.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	lem_in

all:	$(NAME)

$(NAME):
	make -C lib/my
	gcc -o $(NAME) $(SRC) -I./include -L./lib -lmy
	make -C lib/my clean

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
