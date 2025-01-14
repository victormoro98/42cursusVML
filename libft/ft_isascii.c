/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:46:14 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/01/14 18:28:32 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

// #include <ctype.h>
// #include <stdio.h>
// int	main()
// {
// 	printf("%d\n", ft_isascii('a'));
// 	printf("%d\n", __isascii('B'));
// 	printf("%d\n", ft_isascii(' '));
// 	printf("%d\n", __isascii(' '));
// }