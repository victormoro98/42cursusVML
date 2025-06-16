/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:47:58 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/06/16 14:34:15 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack *stack)
{
	t_stack_node	*last;
	t_stack_node	*prev;

	if (!stack || stack->size < 2)
		return ;
	last = stack->first;
	while (last->next && last->next->next)
		last = last->next;
	prev = last;
	last = last->next;
	prev->next = NULL;
	last->next = stack->first;
	stack->first = last;
	stack->last = prev;
}

void	reverse_rotate_op(t_stack *a, t_stack *b, int option)
{
	if (option == 1)
	{
		reverse_rotate(a);
		ft_putstr_fd("rra\n", 1);
	}
	else if (option == 2)
	{
		reverse_rotate(b);
		ft_putstr_fd("rrb\n", 1);
	}
	else if (option == 3)
	{
		reverse_rotate(a);
		reverse_rotate(b);
		ft_putstr_fd("rrr\n", 1);
	}
}
