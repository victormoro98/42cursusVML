#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmoro-lu <vmoro-lu@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/27 16:54:18 by vmoro-lu          #+#    #+#              #
#    Updated: 2025/04/14 17:05:51 by vmoro-lu         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# # Nombre del ejecutable
# NAME = push_swap

# # Compilador y flags
# CC = cc
# CFLAGS = -Wall -Wextra -Werror

# # Archivos del proyecto
# SRC = parsing_stack.c prueba_listas_fdoble.c
# OBJ = $(SRC:.c=.o)

# # Librería Libft
# LIBFT_DIR = ./libft
# LIBFT = $(LIBFT_DIR)/libft.a

# # Regla para compilar los archivos del proyecto y la libft
# all: $(LIBFT) $(NAME)

# $(LIBFT):
# 	@$(MAKE) -C $(LIBFT_DIR)

# $(NAME): $(OBJ) $(LIBFT)
# 	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

# # Regla para compilar archivos .c en .o
# %.o: %.c push_swap.h
# 	$(CC) $(CFLAGS) -c $< -o $@

# # Limpiar archivos objeto
# clean:
# 	@$(MAKE) -C $(LIBFT_DIR) clean
# 	rm -f $(OBJ)

# # Limpiar todo, incluyendo la librería compilada
# fclean: clean
# 	@$(MAKE) -C $(LIBFT_DIR) fclean
# 	rm -f $(NAME)

# # Recompilar desde cero
# re: fclean all

# # Regla para evitar errores si se usa "make" con un nombre de archivo que exista
# .PHONY: all clean fclean re

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = parsing_stack.c prueba_listas_fdoble.c
OBJ = $(SRC:.c=.o)
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# Si quieres generar push_swap.a
PUSH_SWAP_LIB = push_swap.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(PUSH_SWAP_LIB): $(OBJ)
	ar rcs $@ $^

$(NAME): $(PUSH_SWAP_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(PUSH_SWAP_LIB) $(LIBFT)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME) $(PUSH_SWAP_LIB)

re: fclean all

.PHONY: all clean fclean re
