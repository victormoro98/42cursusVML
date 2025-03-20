/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:22:58 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/03/11 18:13:46 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex(size_t n, char *base, int *count)
{
	size_t	aux;

	aux = n;
	if (aux >= 16)
		ft_putnbr_hex(aux / 16, base, count);
	ft_putchar(base[aux % 16], count);
	return ;
}
