/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:28:14 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/01/20 17:19:31 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	s_cast; 

	i = 0;
	while (s[i] != '\0')
	{
		s_cast = (int)s;
		if (c == s_cast)
		{
			return (s);
			break ;
		}
		else
			++i;
	}
	return (NULL);
}
