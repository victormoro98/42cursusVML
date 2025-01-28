#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmoro-lu <vmoro-lu@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/14 15:41:42 by vmoro-lu          #+#    #+#              #
#    Updated: 2025/01/25 18:33:15 by vmoro-lu         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
SRC = ft_isalnum.c ft_isascii.c ft_isprint.c ft_isalpha.c ft_isdigit.c ft_strlen.c ft_memset.c  ft_strncmp.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_tolower.c ft_toupper.c ft_strchr.c ft_strlcat.c ft_strrchr.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_strdup.c ft_substr.c ft_calloc.c ft_strjoin.c ft_itoa.c
OBJ = $(SRC:.c=.o)
NAME = libft.a

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
all: $(NAME)