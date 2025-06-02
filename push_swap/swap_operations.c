/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:03:32 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/06/02 20:10:21 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!stack || stack->size < 2)
		return ;
	first = stack->first;
	second = stack->first->next;

	first->next = second->next;
	second->next = first;
	stack->first = second;

	if (stack ->size == 2)
		stack ->last = first;
}

void	swap_op(t_stack *a, t_stack *b, int option)
{
	if (option == 1)
	{
		swap(a);
		write(1, "sa\n", 3);
	}
	else if (option == 2)
	{
		swap(b);
		write(1, "sb\n", 3);
	}
	else if(option == 3)
	{
		swap(a);
		swap(b);
		write(1, "ss\n", 3);
	}
}
