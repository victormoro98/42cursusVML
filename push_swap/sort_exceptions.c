/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_exceptions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 23:41:55 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/06/12 12:24:14 by vmoro-lu         ###   ########.fr       */
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
	trd = a->first->next->next->dato;

	if (fst < scd && scd < trd)
		return ;
	else if (fst > scd && scd < trd && fst < trd)
		swap_op(a, b, 1);
	else if (fst > scd && scd > trd)
	{
		swap_op(a, b, 1);
		reverse_rotate_op(a, b, 1);
	}
	else if (fst > scd && scd < trd && fst > trd)
		rotate_op(a, b, 1);
	else if (fst < scd && scd > trd && fst < trd)
	{
		swap_op(a, b, 1);
		rotate_op(a, b, 1);
	}
	else if (fst < scd && scd > trd && fst > trd)
		reverse_rotate_op(a, b, 1);
}
