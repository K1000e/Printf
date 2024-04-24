# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgorin <cgorin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/07 10:27:08 by cgorin            #+#    #+#              #
#    Updated: 2024/04/24 18:03:01 by cgorin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
NAME_LIBFT = libft.a

DIR_SRCS = ./srcs/
DIR_HDRS = ./includes
DIR_OBJ = ./objs/
DIR_LIB = ./libft/

SRC = 
SRCS = $(addprefix ${DIR_SRCS}, $(addsuffix .c ${SRC}))

OBJ = $(SRCS:.c=.o)

HDRS    = libft.h


RM = rm -f

all : $(NAME)

$(NAME): $(OBJ) $(DIR_HDRS)$(HDRS)
	ar rcs $(NAME) $(OBJ) 
	
.c.o: 
	 $(CC) $(CFLAGS) -I$(DIR_LIB) -I $(DIR_HDRS) -c $< -o $(<:.c=.o)
	
bonus : $(OBJ) $(OBJ_BONUS) $(DIR_HDRS) $(HDRS)
	ar rcs $(NAME) $(OBJ) $(OBJ_BONUS)
clean: 
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
	
.PHONY: all bonus clean fclean re