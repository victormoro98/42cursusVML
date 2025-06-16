/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:03:40 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/06/16 14:37:29 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_node(int *number, t_stack *stack)
{
	t_stack_node	*new;

	new = malloc(sizeof(t_stack_node));
	if (!new)
		return ;
	new->dato = *number;
	new->next = NULL;
	if (stack->first == NULL)
	{
		stack->first = new;
		stack->last = new;
	}
	else
	{
		stack->last->next = new;
		stack->last = new;
	}
	stack->size++;
}

int	ft_atoi(const char *str)
{
	bool	is_negative;
	int		n;

	is_negative = false;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		++str;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_negative = !is_negative;
		++str;
	}
	n = 0;
	while (*str >= '0' && *str <= '9')
	{
		n *= 10;
		n += *str - '0';
		++str;
	}
	if (is_negative)
		n = -n;
	return (n);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		chunk_count;

	if (argc < 2)
		return (0);
	init_stack(&a);
	init_stack(&b);
	if (!parse_stack(argc, argv, &a))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	assign_indexes(&a);
	if (a.size == 2)
		sort_two(&a, &b);
	else if (a.size == 3)
		sort_three(&a, &b);
	else if (a.size == 4)
		sort_four(&a, &b);
	else
	{
		chunk_count = (a.size <= 100) ? 5 : 10;
		push_chunks(&a, &b, chunk_count);
		empty_b_to_a(&a, &b);
	}
	free_stack(&a);
	return (0);
}
