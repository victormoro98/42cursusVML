/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:25:57 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/06/16 14:18:48 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted_stack(t_stack *stack)
{
	int				i;
	t_stack_node	*head;

	if (!stack)
		return (0);
	i = 1;
	head = stack->first;
	while (head->next)
	{
		if (head->dato < head->next->dato)
			i++;
		else
			break ;
		head = head->next;
	}
	printf("size = %i\n", stack->size);
	if (i == stack->size)
		return (1);
	return (0);
}

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
			return (0);
	}
	*new_number = ft_atoi(str_num);
	if (find_node(new_number, stack))
		return (0);
	return (1);
}

int	count_nums(char *arg_array)
{
	int		j;
	int		count;
	bool	in_num;

	in_num = false;
	count = 0;
	j = 0;
	while (arg_array[j])
	{
		if (ft_isdigit(arg_array[j]) && !in_num)
		{
			in_num = true;
			count++;
		}
		else if (arg_array[j] == ' ')
		{
			in_num = false;
		}
		j++;
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
	if (argc < 2 || (argc == 2 && count_nums(argv[i]) < 2))
		return (0);
	while (argv[i])
	{
		arg_str = ft_split(argv[i], ' ');
		j = 0;
		while (arg_str[j])
		{
			if (!is_valid(arg_str[j], stack, &new_number))
				return (free_split(arg_str), 0);
			else
				insert_node(&new_number, stack);
			j++;
		}
		free_split(arg_str);
		i++;
	}
	return (1);
}
