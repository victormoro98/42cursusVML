/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:41:11 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/05/06 14:29:07 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <stdbool.h>
# include "libft/libft.h"

// Estructura de un nodo de la lista doblemente enlazada

typedef	struct nodo{
	int			dato;
	struct nodo *next;
}				new_node;

// Estructura de la pila (stack)
typedef struct s_stack{
    new_node  *top;   // Puntero al primer elemento
    new_node  *bottom; // Puntero al último elemento
    int     size;   // Tamaño de la pila
} t_stack;

bool	is_valid(char *str_num);
int		count_nums(char	**arg_array);
int		ft_isdigit(int c);

#endif
