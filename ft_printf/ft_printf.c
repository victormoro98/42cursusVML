/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:59:35 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/03/12 11:45:54 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	read_format(va_list args, const char *format, int *count)
{
	if (*format == 'd' || *format == 'i')
		ft_putnbr(va_arg(args, int), count);
	if (*format == 's')
		ft_putstr(va_arg(args, char *), count);
	if (*format == 'c')
		ft_putchar(va_arg(args, int), count);
	if (*format == 'u')
		ft_putnbr_u(va_arg(args, unsigned int), count);
	if (*format == '%')
		ft_putchar('%', count);
	if (*format == 'x')
		ft_putnbr_hex(va_arg(args, unsigned int), HEX_LOW, count);
	if (*format == 'X')
		ft_putnbr_hex(va_arg(args, unsigned int), HEX_UP, count);
	if (*format == 'p')
		ft_put_ptr(va_arg(args, size_t), count);
	return (*count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			read_format(args, str++, &len);
		}
		else
		{
			write(1, str, 1);
			str++;
			len++;
		}
	}
	return (len);
}
