/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:25:57 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/04/23 12:15:39 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

bool	is_valid(char *str_num)
{
	int		i;
	
	i = 0;
	while (str_num[i])
	{
		if (str_num[i] == ' ')
			i++;
		if (str_num[i] == '-' || str_num[i] == '+')
			i++;
		if (!str_num[i])
			break ;
		if (ft_isdigit(str_num[i]))
			i++;
		else
			return(0);
	}
	return (1);
}

int	count_nums(char **arg_array)
{
	int i = 1;
	int j;
	int count = 0;
	bool in_num = false;

	while (arg_array[i])
	{
		j = 0;
		while (arg_array[i][j])
		{
			if (ft_isdigit(arg_array[i][j]) && !in_num)
			{
				in_num = true;
				count++;
			}
			else if (arg_array[i][j] == ' ')
				in_num = false;
			j++;
		}
		in_num = false;
		i++;
	}
	return (count);
}

// int	main(int argc, char **argv)
// {
// 	int total_number = count_nums(argv);
// 	if (argc < 2 || (argc == 2 && total_number == 1))
// 		return (0);
// 	printf ("total_num = %i\n", total_number);
// 		//printerror
// 	return (0);
// }
