/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:00:38 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/01/16 20:29:19 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memcpy(void	*dest, const void *src, int n)
{
	int				i;
	unsigned char	*srcc;
	unsigned char	*destc;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	destc = (unsigned char *)dest;
	srcc = (unsigned char *)src;
	while (i < n)
	{
		destc[i] = srcc[i];
		++i;
	}
	return (dest);
}
