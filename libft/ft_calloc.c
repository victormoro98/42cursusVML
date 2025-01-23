/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:58:02 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/01/23 13:03:59 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr_calloc;

	arr_calloc = malloc(nmemb * size);
	if (arr_calloc == NULL)
		return (NULL);
	ft_bzero (arr_calloc, nmemb * size);
	return (arr_calloc);
}
