/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba_listas_fdoble.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:03:40 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/06/03 00:24:04 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_node(int *number, t_stack *stack)
{
	t_stack_node *new;
	
	new = malloc(sizeof(t_stack_node));
	if (!new)
		return ;
	new->dato = *number;
	new->next = NULL;
	if (stack->first == NULL)
	{
		stack-> first = new;
		stack-> last = new;
	}
	else
	{
		stack->last->next = new;
		stack-> last= new;
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

void	print_list(t_stack *stack)
{
	t_stack_node *actual = stack->first;
	if (!actual)
	{
		printf("\nLa lista esta vacia\n");
		return ;
	}
	while(actual)
	{
		printf("%d\n", actual->dato);
		actual = actual->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack a = {0};
	t_stack b = {0};

	if (!parse_stack(argc, argv, &a))
		return (1);

	// swap_op(&a, &b, 1);
	// pb(&a, &b);
	// pb(&a, &b);
	// swap_op(&a, &b, 3);
	print_list(&a);
	if (count_nums(argv) == 3)
		sort_three(&a, &b);
	printf("---\n");
	print_list(&a);
	/*
	reverse_rotate_op(&a, &b, 1);
	reverse_rotate_op(&a, &b, 2);
	reverse_rotate_op(&a, &b, 3);
	print_list(&a);
	printf("---\n");
	print_list(&b);
	*/

	/*
	rotate_op(&a, &b, 3);
	print_list(&a);
	printf("---\n");
	print_list(&b);
	reverse_rotate_op(&a, &b, 3);
	print_list(&a);
	printf("---\n");
	print_list(&b);
	return (0);
	*/
}
