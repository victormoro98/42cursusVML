/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 11:35:30 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/06/12 12:41:16 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static int	get_chunk_limit(int chunk, int chunk_size)
{
	return ((chunk + 1) * chunk_size - 1);
}

static int	should_push(int index, int chunk_limit)
{
	if (index <= chunk_limit)
		return (1);
	return (0);
}

static void	push_and_rotate(t_stack *a, t_stack *b, int chunk_mid, int index)
{
	pb(a, b);
	if (b->first && index < chunk_mid)
		rotate_op(a,b,2);
}

void	push_chunks(t_stack *a, t_stack *b, int chunk_count)
{
	int	chunk;
	int	chunk_size;
	int	chunk_limit;
	int	chunk_mid;

	chunk = 0;
	chunk_size = a->size / chunk_count;
	while (a->size > 0)
	{
		chunk_limit = get_chunk_limit(chunk, chunk_size);
		chunk_mid = chunk_limit - chunk_size / 2;
		if (should_push(a->first->index, chunk_limit))
			push_and_rotate(a, b, chunk_mid, a->first->index);
		else
			rotate_op(a,b,1);
		if (b->size == (chunk + 1) * chunk_size)
			chunk++;
	}
}

/// creo que hay un fallo a la hora de asignar si pertenece al chunk o no?
/// cuando son 100 numeros me hace mal la asignacion y los tres ultimos numeros de a
/// hace que sea 88,98,100 indices = 87 97 99