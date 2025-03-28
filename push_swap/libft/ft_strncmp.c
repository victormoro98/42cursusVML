/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:36:18 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/01/21 17:08:21 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (((char)s1[i] != '\0' || (char)s2[i] != '\0') && i < n)
	{
		if ((char)s1[i] != (char)s2[i])
			return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
		i++;
	}
	return (0);
}

// #include <stdio.h>
// int	main(void)
// {
// 	printf ("%i", ft_strncmp("abcdefgh", "", 0));
// 	return (0);
// }
