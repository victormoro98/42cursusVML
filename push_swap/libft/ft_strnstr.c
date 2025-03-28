/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:24:06 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/01/28 13:49:23 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

char	*ft_strnstr(const char	*big, const char	*little, size_t	len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] != '\0' && len != 0)
	{
		if ((little[0] == big[i]))
		{
			j = 0;
			while (big[i + j] == little[j] && len > i + j)
			{
				j++;
				if ((little[j] == '\0'))
					return ((char *)(big + i));
			}
		}
		i++;
	}
	return (0);
}
