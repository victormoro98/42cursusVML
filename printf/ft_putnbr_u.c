/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:17:37 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/03/11 12:44:39 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_u(unsigned int n, int *count)
{
	if (n >= 10 && n <= 4294967295)
	{
		ft_putnbr_u(n / 10, count);
		ft_putchar(n % 10 + '0', count);
	}
	else if (n >= 0 && n <= 9)
		ft_putchar(n + '0', count);
	return ;
}
