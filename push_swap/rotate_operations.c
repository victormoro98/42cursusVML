/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:17:35 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/06/16 14:33:02 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack)
{
	t_stack_node	*temp;

	if (!stack || stack->size < 2)
		return ;
	temp = stack->first;
	stack->first = temp->next;
	stack->last->next = temp;
	stack->last = temp;
	stack->last->next = NULL;
}

void	rotate_op(t_stack *a, t_stack *b, int option)
{
	if (option == 1)
	{
		rotate(a);
		ft_putstr_fd("ra\n", 1);
	}
	else if (option == 2)
	{
		rotate(b);
		ft_putstr_fd("rb\n", 1);
	}
	else if (option == 3)
	{
		rotate(a);
		rotate(b);
		ft_putstr_fd("rr\n", 1);
	}
}
