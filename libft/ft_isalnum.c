/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:36:31 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/01/14 18:30:44 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}
// #include <ctype.h>
// #include <stdio.h>
// int	main(void)
// {
// 	printf("%d\n", ft_isalnum('B'));
// 	printf("%d\n", isalnum('B'));
// 	printf("%d\n", ft_isalnum(' '));
// 	printf("%d\n", isalnum(' '));
// 	printf("%d\n", ft_isalnum('1'));
// 	printf("%d\n", isalnum('1'));
// }