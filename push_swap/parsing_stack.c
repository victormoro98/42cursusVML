/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:25:57 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/03/27 17:59:56 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

bool	is_valid(char **str_num)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (str_num[i])
	{
		if (str_num[i][j] == '-' || str_num[i][j] == '+')
			j++;
		if (!str_num[i][j])
			return (0);
		while (str_num[i][j] != '\0')
		{
			if(ft_isdigit(str_num[i][j]))
				j++;
			else
				return(0);
		}
		j = 0;
		i++;
	}
	return (1);
}
