# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabdulba <sabdulba@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 17:23:16 by sabdulba          #+#    #+#              #
#    Updated: 2024/12/04 19:07:46 by sabdulba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol
CC := cc
RM := rm -rf
FLAG := -Wall -Wextra -Werror -Ofast

MLX := $(MLX_DIR)/build/libmlx42.a
MLX_DIR := ./lib/MLX42
LIBFT := $(LIBFT_DIR)/libft.a
LIBFT_DIR := ./lib/libft
HEADERS := -I ./inc -I $(MLX_DIR)/include/MLX42 -I $(LIBFT_DIR)/inc

UNAME_S	:= $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	LINK := -L$(LIBFT_DIR) -lft $(MLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm
endif
ifeq ($(UNAME_S),Darwin)
	LINK := -L$(LIBFT_DIR) -lft $(MLX_DIR)/build/libmlx42.a \
	-Iinclude -lglfw -L"/opt/homebrew/opt/glfw" -pthread -lm
endif

SRC_DIR := src
SRC := $(shell ls src/*.c)

OBJ_DIR := obj
OBJ := $(SRC:src%.c=obj%.o)

all: $(NAME)

$(MLX): $(MLX_DIR)
	cmake $(MLX_DIR) -B $(MLX_DIR)/build;
	make -C$(MLX_DIR)/build -j4;

$(LIBFT): $(LIBFT_DIR)
	make -C $(LIBFT_DIR);

$(MLX_DIR):
	git clone https://github.com/codam-coding-college/MLX42.git $@;

$(LIBFT_DIR):
	git clone https://github.com/IbnBaqqi/libft.git $@;

$(OBJ_DIR):
	mkdir obj

$(NAME): $(MLX) $(LIBFT) $(OBJ_DIR) $(OBJ)
	$(CC) $(OBJ) $(LINK) $(HEADERS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c inc/fractol.h
	$(CC) -c $(FLAG) $< -o $@ $(HEADERS)

clean:
	$(RM) $(NAME)
	$(RM) $(OBJ_DIR)/*.o
	$(RM) $(LIBFT_DIR)/libft.a
	$(RM) $(LIBFT_DIR)/obj
	$(RM) $(MLX_DIR)/build/libmlx42.a

fclean: clean
	@rm -f $(NAME)
	$(RM) $(OBJ_DIR)
	$(RM) $(LIBFT_DIR)
	$(RM) $(MLX_DIR)

re: fclean all

m: all
	./$(NAME) mandelbrot

j: all
	./$(NAME) julia 6 7
