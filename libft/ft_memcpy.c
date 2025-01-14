/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:00:38 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/01/14 21:33:00 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dest, const void *src, int n)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = dest;
	while (dest[i] != "\0")
	{
		ptr[i] = src[i];
		++i;
	}
}
