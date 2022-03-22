NAME = expression_regulier

CC = gcc

CFLAGS = -Wall -Wextra

HEADER = regular.h

SRC_FILE = ./main/main.c\
			./utiles/ft_est_regulier.c\
			./utiles/ft_strlen.c\
			./utiles/ft_erreur.c\
			./utiles/ft_append.c\
			./utiles/ft_fragment.c\
			./utiles/ft_list1.c\
			./utiles/ft_patch.c\
			./utiles/ft_state.c\
			./utiles/ft_postregulier_en_nfa.c\

OBJ_FILE = $(SRC_FILE:%.c=%.o)

$(NAME) : $(OBJ_FILE)
	@echo $(OBJ_FILE)
	@$(CC) $(CFLAGS)  $(OBJ_FILE) -o $(NAME)

all : $(NAME)

clean :
	@rm -rf $(OBJ_FILE)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re

