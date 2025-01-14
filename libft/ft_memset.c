/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:55:48 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/01/14 20:51:08 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, int n)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = s;
	while (i < n)
	{
		ptr[i] = c;
		++i;
	}
	return (s);
}