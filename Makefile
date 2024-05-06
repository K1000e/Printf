# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgorin <cgorin@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/07 10:27:08 by cgorin            #+#    #+#              #
#    Updated: 2024/05/06 00:34:48 by cgorin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 			:= cc
CFLAGS 		:= -Wall -Wextra -Werror
CPPFLAGS    := -I include
AR 			:= ar
ARFLAGS 	:= -r -c -s

NAME 		:= libftprintf.a
#NAME_LIBFT := libft.a

OBJ_DIR	:= objs
SRC_DIR := srcs
SRCS 	:= 						\
	ft_printf.c 			\
	ft_print_char.c \
	ft_print_i_d.c \
	ft_print_x.c \
	ft_print_s.c \
	ft_print_p.c \
	ft_strlen.c 			\
	ft_putnbr_fd.c 		\
	ft_putchar_fd.c 		\
	ft_putnbr_base.c 	\
	ft_strchr.c \
#	ft_itoa.c 			\
	ft_printf_type.c 	\
	ft_putstr_fd.c 		\

SRCS 	:= $(SRCS:%=$(SRC_DIR)/%)
OBJ 	:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

HDRS    := libft.h
#DIR_DUP := mkdir -p $(@D)

RM = rm -f

all : $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ) 
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c  -o $@ $<

clean: 
	$(RM) $(OBJ) 
# $(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
	
.PHONY: all bonus clean fclean re