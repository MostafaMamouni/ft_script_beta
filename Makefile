# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmostafa <mmostafa@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/15 12:14:50 by mmostafa          #+#    #+#              #
#    Updated: 2020/12/05 17:29:11 by mmostafa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_script

SRC = ft_script.c utilities.c
OBJ = obj/ft_script.o obj/utilities.o

SRCDIR = ./srcs/
INC = ./incs/
OBJDIR = ./obj/

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) $(OBJ) -o $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c $(INC)ft_script.h
	@mkdir -p $(OBJDIR)
	gcc $(FLAGS) -I $(INC) -c $< -o $@

clean:
	rm -fr $(NAME)

fclean:
	make clean
	rm -fr $(OBJDIR)
re:
	make fclean
	make all