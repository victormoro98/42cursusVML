/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_merge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 11:55:14 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/06/18 21:44:26 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_index(t_stack *b)
{
	t_stack_node	*node;
	int				max;

	node = b->first;
	max = node->index;
	while (node)
	{
		if (node->index > max)
			max = node->index;
		node = node->next;
	}
	return (max);
}

int	get_position(t_stack *a, int index)
{
	t_stack_node	*current;
	int				pos;

	pos = 0;
	current = a->first;
	while (current && current->index != index)
	{
		current = current->next;
		pos++;
	}
	return (pos);
}

void	empty_b_to_a(t_stack *a, t_stack *b)
{
	int	max_index;
	int	pos;

	while (b->size > 0)
	{
		max_index = get_max_index(b);
		pos = get_position(b, max_index);
		if (pos <= b->size / 2)
		{
			while (b->first->index != max_index)
				rotate_op (a, b, 2);
		}
		else
		{
			while (b->first->index != max_index)
				reverse_rotate_op (a, b, 2);
		}
		pa(a, b);
	}
}
