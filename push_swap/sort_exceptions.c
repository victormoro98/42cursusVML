/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_exceptions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 23:41:55 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/06/03 01:04:49 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a, t_stack *b)
{
	int	fst;
	int	scd;
	int	trd;

	fst = a->first->dato;
	scd = a->first->next->dato;
	trd = a->last->dato;
	
	if(fst > scd && scd < trd)
		swap_op(a, b, 1);
	else if(fst < scd && scd > fst)
	{
		reverse_rotate_op(a, b, 1);
		if (trd > fst)
			swap_op(a, b, 1);
	}
	else if(fst > scd)
	{
		rotate_op(a, b, 1);
		if(scd > trd)
			swap_op(a, b, 1);
	}
}
