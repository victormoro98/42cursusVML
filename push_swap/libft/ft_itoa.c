/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:21:12 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/02/04 19:56:08 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_num_digit(int n_1)
{
	int	counter;

	counter = 0;
	if (n_1 < 0)
	{
		n_1 = -n_1;
		count_num_digit(n_1);
	}
	while (n_1 > 0)
	{
		n_1 /= 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	int		n_digits;
	char	*ret;
	int		negative;

	negative = (n < 0);
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	n_digits = (count_num_digit(n) + negative);
	ret = malloc(sizeof(char) * (n_digits + 1));
	if (!ret)
		return (NULL);
	if (negative)
	{
		n = -n;
		ret[0] = '-';
	}
	ret[n_digits] = '\0';
	while (n != 0)
	{
		ret[n_digits-- -1] = (n % 10) + '0';
		n /= 10;
	}
	return (ret);
}

// int	main(void)
// {
// 	printf("%s\n", ft_itoa(123));
// 	printf("%s\n", ft_itoa(0));
// 	printf("%s\n", ft_itoa(-123));
// 	return (0);
// }
