/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:25:57 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/06/03 00:11:05 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_node(int *to_find, t_stack *stack)
{
	t_stack_node	*actual;
	
	actual = stack->first;
	while (actual)
	{
		if (actual->dato == *to_find)
			return (1);
		actual = actual->next;
	}
	return (0);
}

bool	is_valid(char *str_num, t_stack *stack, int *new_number)
{
	int		i;
	
	i = 0;
	while (str_num[i])
	{
		if (str_num[i] == ' ')
			i++;
		else if ((str_num[i] == '-' || str_num[i] == '+')
				&& (str_num[i + 1] >= '0' && str_num[i + 1] <= '9'))
			i++;
		else if (!str_num[i])
			break ;
		else if (ft_isdigit(str_num[i]))
			i++;
		else
			return(0);
	}
	*new_number = ft_atoi(str_num);
	if (find_node(new_number, stack))
		return (0);
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

int	parse_stack(int argc, char **argv, t_stack *stack)
{
	char	**arg_str;
	int		i;
	int		j;
	int		new_number;
	
	i = 1;
	if (argc < 2 || (argc == 2 && count_nums(argv) < 2))
		return (0);
	while (argv[i])
	{
		arg_str = ft_split(argv[i], ' ');
		j = 0;
		while (arg_str[j])
		{
			if (!is_valid(arg_str[j], stack, &new_number))
				return(0);
			else
				insert_node(&new_number, stack);
			j++;
		}
		free(arg_str);
		i++;
	}
	return (1);
}

// static void	ft_free_arg(char **args)
// {
// 	int	i;

// 	i = 0;
// 	while (args[i])
// 		free(args[i++]);
// 	free(args);
// }
