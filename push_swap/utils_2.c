/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:29:22 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/06/30 16:34:01 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_node(long *number, t_stack *stack)
{
	t_stack_node	*new;

	new = malloc(sizeof(t_stack_node));
	if (!new)
		return ;
	new->dato = *number;
	new->next = NULL;
	if (stack->first == NULL)
	{
		stack->first = new;
		stack->last = new;
	}
	else
	{
		stack->last->next = new;
		stack->last = new;
	}
	stack->size++;
}

void	chose_sort(t_stack *a, t_stack *b, int size)
{
	int	chunk_count;

	if (size == 2)
		sort_two(a, b);
	else if (size == 3)
		sort_three(a, b);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
	else
	{
		if (size <= 100)
			chunk_count = 5;
		else
			chunk_count = 10;
		push_chunks(a, b, chunk_count);
		empty_b_to_a(a, b);
	}
}
