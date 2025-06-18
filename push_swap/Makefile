# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                       >                              +:+ +:+         +:+      #
#    By: vmoro-lu <vmoro-lu@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/27 16:54:18 by vmoro-lu          #+#    #+#              #
#    Updated: 2025/06/18 12:28:44 by vmoro-lu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = parsing_stack.c push_swap.c utils_1.c utils_2.c push_operations.c swap_operations.c rotate_operations.c reverse_rotate_operations.c sort_exceptions.c push_chunk.c asign_index_to_nodes_a.c final_merge.c
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
