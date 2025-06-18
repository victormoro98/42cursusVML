/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:03:40 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/06/18 14:52:00 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	init_stack(&a);
	init_stack(&b);
	if (!parse_stack(argc, argv, &a))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	assign_indexes(&a);
	chose_sort(&a, &b, a.size);
	free_stack(&a);
	return (0);
}
