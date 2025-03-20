/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:35:05 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/03/11 11:48:32 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *count)
{
	if (n == -2147483648)
		ft_putstr("-2147483648", count);
	else if (n < 0)
	{
		n = -n;
		ft_putchar('-', count);
		ft_putnbr(n, count);
	}
	else if (n >= 10 && n <= 2147483647)
	{
		ft_putnbr(n / 10, count);
		ft_putchar(n % 10 + '0', count);
	}
	else if (n >= 0 && n <= 9)
		ft_putchar(n + '0', count);
	return ;
}
