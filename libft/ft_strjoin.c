/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:11:58 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/01/25 16:57:42 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat;
	size_t	len_concat;
	int		i;
	int		j;

	j = 0;
	i = 0;
	len_concat = (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s1 || !s2)
		return (0);
	concat = malloc(sizeof(char) * len_concat);
	if (!concat)
		return (0);
	while(s1[i] != '\0')
	{
		concat[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0' && j < (int)len_concat)
	{
		concat[i + j] = s2[j];
		j++;
	}
	concat[i + j] = '\0';
	return (concat);
}
