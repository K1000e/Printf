# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgorin <cgorin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/07 10:27:08 by cgorin            #+#    #+#              #
#    Updated: 2024/05/11 17:12:16 by cgorin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -Wall -Wextra -Werror
CPPFLAGS := -I include
AR := ar
ARFLAGS := rcs

NAME := libftprintf.a
OBJ_DIR := objs
SRC_DIR := srcs

SRCS := 				\
	ft_printf.c 		\
	ft_print_i_d_c.c 	\
	ft_print_u_x.c 		\
	ft_print_p.c 		\
	ft_printf_utils.c

SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

MKDIR_P := mkdir -p
RM := rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
