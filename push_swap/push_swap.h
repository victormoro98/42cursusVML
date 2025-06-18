/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:41:11 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/06/18 21:45:47 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef struct s_stack_node
{
	int					dato;
	int					index;
	struct s_stack_node	*next;
}					t_stack_node;

typedef struct s_stack
{
	t_stack_node	*first;
	t_stack_node	*last;
	int				size;
}					t_stack;

//prueba_listas_dobles.c
void	insert_node(long *number, t_stack *stack);
int		ft_atoi(const char *str);

//parsing stack
bool	is_valid(char *str_num, t_stack *stack, long *new_number);
int		count_nums(char	*arg_array);
int		ft_isdigit(int c);
int		find_node(int	*to_find, t_stack *stack);
int		parse_stack(char **argv, t_stack *stack);
int		sorted_stack(t_stack *stack);
// static void	ft_free_arg(char **args);

//swap_operations
void	swap(t_stack *stack);
void	swap_op(t_stack *a, t_stack *b, int option);

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
void	sort_four(t_stack *a, t_stack *b);
void	sort_two(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);

//asign_index_to_nodes_a.c
int		*extract_values(t_stack *stack);
void	bubble_sort(int *array_nums, int size);
void	assign_indexes(t_stack *stack);

//push_chunk.c
void	push_chunks(t_stack *a, t_stack *b, int chunk_count);

//final_merge.c
void	empty_b_to_a(t_stack *a, t_stack *b);
int		get_max_index(t_stack *b);
int		get_position(t_stack *a, int index);

//utils_1.c
void	free_stack(t_stack *stack);
void	free_split(char **split);
void	init_stack(t_stack *stack);
void	print_list(t_stack *stack);

//utils_2.c
void	chose_sort(t_stack *a, t_stack *b, int size);

#endif