# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmoro-lu <vmoro-lu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 21:58:06 by vmoro-lu          #+#    #+#              #
#    Updated: 2025/03/11 14:40:30 by vmoro-lu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_put_ptr.c ft_putchar.c ft_putnbr_hex.c ft_putnbr_u.c ft_putnbr.c ft_putstr.c
OBJS = $(SRC:.c=.o)

NAME = libftprintf.a

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)	

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) 
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
all: $(NAME)