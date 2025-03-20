/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:18:52 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/03/11 11:43:40 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int *count)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		ft_putstr("(null)", count);
		return ;
	}
	else if (s[0] == '\0')
		return ;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
		(*count)++;
	}
	return ;
}
