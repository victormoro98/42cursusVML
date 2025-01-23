/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:30:25 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/01/23 14:33:28 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char			*str_duplicated;
	size_t			len;

	len = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	str_duplicated = malloc(sizeof(char) * (len + 1));
	if (str_duplicated == NULL)
		return (NULL);
	ft_strlcpy(str_duplicated, (char *)s, len + 1);
	return (str_duplicated);
}
