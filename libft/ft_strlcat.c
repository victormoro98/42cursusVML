/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:37:17 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/01/20 17:19:57 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dst, const char *src, int size)
{
	int		lendst;
	int		lensrc;
	char	*src_c;
	int		c;
 
	src_c = (char *)src;
	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src_c);

	c = 0;
	while (src[c] != '\0' && dst[lendst] != 0)
	{
		dst[lendst] = src[c];
		++c;
		lendst++;
	}
	dst[size -1] = '\0';
	return (ft_strlen(dst));
}
