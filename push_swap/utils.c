/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:10:33 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/06/06 12:51:33 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_positions(t_stack *stack)
{
	int				position;
	t_stack_node	*current;
	
	position = 0;
	current = stack->first;
	while(current)
	{
		current -> pos = position;
		current = current -> next;
		position++;
	}
}

int	get_target_pos_in_b(t_stack *b, int value)
{
	t_stack_node	*current;
	int 			pos;
	int				best_pos;
	int				best_diff = __INT_MAX__;

	pos = 0;
	best_pos = 0;
	if (b->size == 0)
		return(best_pos = 0, best_pos);
	while(current)
	{
		if (current->dato < value && (value - current->dato) < best_diff)
		{
			best_diff = value - current->dato;
			best_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (best_pos);
}

void	calculate_costs(t_stack *a, t_stack  *b)
{
	t_stack_node	*current;
	int				size_a;
	int				size_b;

	current = a->first;
	size_a = a->size;
	size_b = b->size;	
	update_positions(a);
	update_positions(b);
	while(current)
	{
		
	}
}