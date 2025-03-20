/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:50:50 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/03/17 16:36:18 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>

# define HEX_LOW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"

int		ft_printf(const char *str, ...);
void	ft_putnbr(int n, int *count);
void	ft_putstr(char *s, int *count);
void	ft_putchar(int c, int *count);
void	ft_putnbr_u(unsigned int n, int *count);
void	ft_putnbr_hex(size_t n, char *base, int *count);
void	ft_put_ptr(size_t ptr, int *count);

#endif