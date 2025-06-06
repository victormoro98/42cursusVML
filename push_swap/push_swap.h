/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:41:11 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/06/06 11:48:29 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef	struct s_stack_node{
	int					dato;
	int					index;
	int					pos;
	int					cost_a;
	int					cost_b;
	struct s_stack_node	*next;
}					t_stack_node;

typedef	struct s_stack{
	t_stack_node	*first;
	t_stack_node	*last;
	int				size;
}					t_stack;

//prueba_listas_dobles.c
void	insert_node(int *number, t_stack *stack);
int		ft_atoi(const char *str);

//parsing stack
bool	is_valid(char *str_num, t_stack *stack, int *new_number);
int		count_nums(char	**arg_array);
int		ft_isdigit(int c);
int		find_node(int	*to_find, t_stack *stack);
int		parse_stack(int argc, char **argv, t_stack *stack);
int     sorted_stack(t_stack *stack);
// static void	ft_free_arg(char **args);

//swap_operations
void	swap(t_stack *stack);
void	swap_op(t_stack *a, t_stack *b,int option);

//push_operations
void	pb(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);

//rotate_operations
void	rotate(t_stack *stack);
void	rotate_op(t_stack *a, t_stack *b, int option);

//reverse_rotate_operations
void	reverse_rotate(t_stack *stack);
void	reverse_rotate_op(t_stack *a, t_stack *b, int option);

//sort_exceptions.c
void	sort_three(t_stack *a, t_stack *b);

//utils.c
void	print_list(t_stack *stack);

#endif