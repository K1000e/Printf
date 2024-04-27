# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgorin <cgorin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/07 10:27:08 by cgorin            #+#    #+#              #
#    Updated: 2024/04/27 16:32:38 by cgorin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 			:= cc
CFLAGS 		:= -Wall -Wextra -Werror
CPPFLAGS    := -I include
AR 			:= ar
ARFLAGS 	:= -r -c -s

NAME 		:= libftprintf.a
NAME_LIBFT 	:= libft.a

OBJ_DIR	:= objs
SRC_DIR := srcs
SRCS 	:= 						\
	printf/ft_printf.c 			\
	printf/ft_printf_type.c 	\
	libft/ft_putstr_fd.c 		\
	libft/ft_putchar_fd.c 		\
	libft/ft_putnbr_base_fd.c 	\
	libft/ft_strlen.c 			\

SRCS 	:= $(SRCS:%=$(SRC_DIR)/%)
OBJ = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

HDRS    = libft.h
DIR_DUP     = mkdir -p $(@D)

RM = rm -f

all : $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ) 
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c  -o $@ $<

clean: 
	$(RM) $(OBJ) 
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
	
.PHONY: all bonus clean fclean re