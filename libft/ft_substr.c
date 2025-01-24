/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:48:06 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/01/24 18:08:35 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	size_t	i;
	char	*substr;

	i = 0;
	len_s = ft_strlen(s);
	if (s == NULL)
		return (0);
	if (len > len_s - start)
		len = len_s - start;
	if (start >= len_s)
	{
		substr = ft_strdup("");
		return (substr);
	}
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (0);
	while (i < len)
	{
		substr[i] = s[start + i];
		++i;
	}
	substr[i] = '\0';
	return(substr);
}
// #include <stdio.h>

// int	main(void)
// {

// }