/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_exceptions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 23:41:55 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/06/18 21:44:06 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a, t_stack *b)
{
	int	x;
	int	y;
	int	z;

	x = a->first->dato;
	y = a->first->next->dato;
	z = a->first->next->next->dato;
	if (x > y && x > z)
	{
		rotate_op(a, b, 1);
		if (y > z)
			swap_op(a, b, 1);
	}
	else if (x > y && x < z)
		swap_op(a, b, 1);
	else if (x < y && y > z)
	{
		reverse_rotate_op(a, b, 1);
		if (x < z)
			swap_op(a, b, 1);
	}
}

void	sort_two(t_stack *a, t_stack *b)
{
	int	x;
	int	y;

	x = a->first->dato;
	y = a->first->next->dato;
	if (x > y)
		swap_op(a, b, 1);
}

void	sort_four(t_stack *a, t_stack *b)
{
	int	pos;

	pos = get_position(a, 0);
	if (pos == 1)
		rotate_op(a, b, 1);
	else if (pos == 2)
	{
		rotate_op(a, b, 1);
		rotate_op(a, b, 1);
	}
	else if (pos == 3)
		reverse_rotate_op(a, b, 1);
	pb(a, b);
	sort_three(a, b);
	pa(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	t_stack_node	*current;

	current = a->first;
	while (current->index != 0)
	{
		if (get_position(a, 0) > 2)
			reverse_rotate_op(a, b, 1);
		else
			rotate_op(a, b, 1);
		current = a->first;
	}
	pb(a, b);
	while (current->index != 1)
	{
		if (get_position(a, 1) > 2)
			reverse_rotate_op(a, b, 1);
		else
			rotate_op(a, b, 1);
		current = a->first;
	}
	pb (a, b);
	sort_three(a, b);
	pa(a, b);
	pa(a, b);
}
