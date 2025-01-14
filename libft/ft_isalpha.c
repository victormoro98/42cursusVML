/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:38:25 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/01/14 17:12:19 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}

// #include <ctype.h>
// #include <stdio.h>
// int	main(void)
// {
// 	printf("%d\n", ft_isalpha('a'));
// 	printf("%d\n", isalpha('B'));
// 	printf("%d\n", ft_isalpha(' '));
// 	printf("%d\n", isalpha(' '));
// }
