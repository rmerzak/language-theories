NAME = expression_regulier

CC = gcc

HEADER = regular.h

SRC_FILE = ./main/main.c\
			./utiles/ft_addstate.c\
			./utiles/ft_aide_list.c\
			./utiles/ft_append.c\
			./utiles/ft_debutlist.c\
			./utiles/ft_debutstate.c\
			./utiles/ft_dstate.c\
			./utiles/ft_erreur.c\
			./utiles/ft_est_regulier.c\
			./utiles/ft_fragment.c\
			./utiles/ft_nextstate.c\
			./utiles/ft_patch.c\
			./utiles/ft_state.c\
			./utiles/ft_step.c\


OBJ_FILE = $(SRC_FILE:%.c=%.o)

$(NAME) : $(OBJ_FILE)
	@echo $(OBJ_FILE)
	@$(CC) $(OBJ_FILE) -o $(NAME)

all : $(NAME)

clean :
	@rm -rf $(OBJ_FILE)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re

