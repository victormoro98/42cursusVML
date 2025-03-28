/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:41:11 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/03/27 17:06:50 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

// Estructura de un nodo de la lista doblemente enlazada
typedef struct s_node
{
    int             value;
    struct s_node   *next;
    struct s_node   *prev;
} t_node;

// Estructura de la pila (stack)
typedef struct s_stack
{
    t_node  *top;   // Puntero al primer elemento
    t_node  *bottom; // Puntero al último elemento
    int     size;   // Tamaño de la pila
} t_stack;

#endif
