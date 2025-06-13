/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:10:33 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/06/12 12:25:33 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->first = NULL;
	stack->last = NULL;
	stack->size = 0;
}

void	free_stack(t_stack *stack)
{
	t_stack_node	*temp;

	while (stack->first)
	{
		temp = stack->first;
		stack->first = stack->first->next;
		free(temp);
	}
}
