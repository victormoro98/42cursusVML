/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:44:56 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/01/16 20:36:19 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void	*dest, const void *src, int n)
{
	unsigned char	*dest_c;
	unsigned char	*src_c;
	int				i;

	if (src == NULL && dest == NULL)
		return (NULL);
	i = 0;
	dest_c = (unsigned char *)dest;
	src_c = (unsigned char *)src;
	if ((dest < src) || (dest >= (src + n)))
		ft_memcpy(dest, src, n);
	else
	{
		i = n - 1;
		while (i >= 0)
		{
			dest_c[i] = src_c[i];
			i--;
		}
	}
	return (dest);
}
