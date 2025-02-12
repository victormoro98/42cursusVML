/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:20:33 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/02/04 19:56:40 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	counter;

	counter = 0;
	while (lst)
	{
		counter++;
		lst = lst->next;
	}
	return (counter);
}

// int main (void)
// {	
// 	t_list *node1 = ft_lstnew("nodo 1");
// 	t_list *node2 = ft_lstnew("nodo 2");
// 	t_list *node3 = ft_lstnew("nodo 3");

// 	node1->next = node2;
// 	node2->next = node3;

// 	printf("%d", ft_lstsize(node1));

// 	free(node1);
// 	free(node2);
// 	free(node3);
// 	return (0);
// }
