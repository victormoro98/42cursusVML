/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:44:49 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/01/20 17:19:44 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char	*dest, char *src, unsigned int c)
{
	unsigned int	i;
	int				len;

	i = 0;
	len = ft_strlen(src);
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
