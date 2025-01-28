/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:13:36 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/01/28 17:52:44 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	start;
	size_t	finish;

	start = 0;
	while (set != '\0')
	{
		if (set == s1)
		{
			s1++;
			start++;
		}
		else
			set++;
	}
	while (set)
	{
		if (set == s1)
		{
			s1++;
			start++;
		}
		else
			set++;
	}
}
