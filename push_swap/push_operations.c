/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:08:40 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/06/12 12:22:25 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	t_stack_node *temp;

	temp = b->first;
	b->first = temp->next;

	if (b->size == 1)
		b->last = NULL;
	b->size--;

	temp->next = a->first;
	a->first = temp;

	if(a->size == 0)
		a->last = temp;
	a->size++;
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	t_stack_node *temp;

	temp = a->first;
	a->first = temp->next;

	if (a->size == 1)
		a->last = NULL;
	a->size--;

	temp->next = b->first;
	b->first = temp;

	if(b->size == 0)
		b->last = temp;
	b->size++;
	write(1, "pb\n", 3);
}
