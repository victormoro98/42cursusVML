/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asign_index_to_nodes_a.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:46:23 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/06/18 19:39:21 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*extract_values(t_stack *stack)
{
	t_stack_node	*current;
	int				*array_nums;
	int				i;

	i = 0;
	array_nums = malloc(sizeof(int) * (stack->size));
	if (!array_nums)
		return (NULL);
	current = stack->first;
	while (current)
	{
		array_nums[i] = current->dato;
		current = current->next;
		i++;
	}
	return (array_nums);
}

void	bubble_sort(int *array_nums, int size)
{
	int	i;
	int	temp;
	int	sorted;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = 0;
		while (i < size - 1)
		{
			if (array_nums[i] > array_nums[i + 1])
			{
				temp = array_nums[i];
				array_nums [i] = array_nums[i + 1];
				array_nums [i + 1] = temp;
				sorted = 0;
			}
			i++;
		}
	}
}

void	assign_indexes(t_stack *stack)
{
	int				*arr;
	t_stack_node	*node;
	int				i;

	arr = extract_values(stack);
	if (!arr)
		return ;
	bubble_sort(arr, stack->size);
	node = stack->first;
	while (node)
	{
		i = 0;
		while (i < stack->size)
		{
			if (node->dato == arr[i])
			{
				node->index = i;
				break ;
			}
			i++;
		}
		node = node->next;
	}
	free(arr);
}
