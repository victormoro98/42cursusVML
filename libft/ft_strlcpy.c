/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:44:49 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/01/23 14:34:27 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char	*dest, char *src, size_t c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen((const char *)src);
	if (src == NULL || dest == NULL)
		return (0);
	if (c > 0)
	{
		while ((i < c - 1) && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (len);
}
