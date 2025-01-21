/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:28:14 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/01/20 20:42:17 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == (char)c && c != '\0')
			return ((char *)(s + i));
		else
			i++;
	}
	return (NULL);
}
