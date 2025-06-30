/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:25:57 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/06/30 16:45:00 by vmoro-lu         ###   ########.fr       */
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

bool	is_valid(char *str_num, t_stack *stack, long *new_number)
{
	int		i;
	int		int_number;

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
	*new_number = ft_atolong(str_num);
	if (*new_number < -2147483648 || *new_number > 2147483647)
		return (0);
	int_number = (int)*new_number;
	if (find_node(&int_number, stack))
		return (0);
	return (1);
}

int	parse_stack(char **argv, t_stack *stack)
{
	char		**arg_str;
	int			i;
	int			j;
	long		new_number;

	i = 1;
	while (argv[i])
	{
		arg_str = ft_split(argv[i], ' ');
		j = 0;
		if (arg_str[j] == NULL)
			return (free(arg_str), 0);
		while (arg_str[j])
		{
			if (!is_valid(arg_str[j], stack, &new_number))
				return (free_split(arg_str), free_stack(stack), 0);
			else
				insert_node(&new_number, stack);
			j++;
		}
		i++;
		free_split(arg_str);
	}
	return (1);
}
