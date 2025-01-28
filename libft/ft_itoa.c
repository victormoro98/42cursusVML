/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:21:12 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/01/28 13:12:09 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

static int	count_num_digit(int n_1)
{
	int	counter;
	
	if (n_1 < 0)
	{
		n_1 = -n_1;
		count_num_digit(n_1);
	}
	else if (n_1== 0)
		counter = 1;
	while (n_1 > 0)
	{
		n_1 /= 10;
		counter++;
	}
	return (counter);
}
char	*ft_itoa(int n)
{
	int		len;
	// int		is_negative;
	char	*ret;
	int		i;

	len = count_num_digit(n);
	// is_negative = f_t_isnegative(n);
	i = (len + 1);
	ret = malloc(sizeof(char) * i);
	if (!ret)
		return (NULL);
	ret[--i] = '\0';
	if (n == 0)
		ret[0] = '0';
	if ()
	{
		n = -n;
		ret[0] = '-';
	}
	while (n > 0)
	{
		ret[i--] = (n % 10) + '0';
		n /= 10;
	}
	return(ret);
}

// int	main(void)
// {
// 	printf("%s\n", ft_itoa(123));
// 	printf("%s\n", ft_itoa(0));
// 	printf("%s\n", ft_itoa(-123));
// 	return (0);
// }