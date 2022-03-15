NAME = expression_regulier

CC = gcc

CFLAGS = -Wall -Wextra

HEADER = regular.h

SRC_FILE = ./main/main.c\
			./utiles/ft_est_regulier.c\
			./utiles/ft_strlen.c\

OBJ_FILE = $(SRC_FILE:%.c=%.o)

$(NAME) : $(OBJ_FILE)
	@$(CC) $(CFLAGS) -g $(OBJ_FILE) -o $(NAME)

all : $(NAME)

clean :
	@rm -rf $(OBJ_FILE)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re

