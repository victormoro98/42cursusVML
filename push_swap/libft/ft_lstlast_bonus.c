/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:49:17 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/02/04 19:56:29 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

// int main (void)
// {	
// 	t_list *node1 = ft_lstnew("nodo 1");
// 	t_list *node2 = ft_lstnew("nodo 2");
// 	t_list *node3 = ft_lstnew("nodo 3");

// 	node1->next = node2;
// 	node2->next = node3;

// 	t_list *final =  ft_lstlast(node1);

// 	if (final)
// 		printf("%s\n", (char *)final->content);
// 	free(node1);
// 	free(node2);
// 	free(node3);
// 	return (0);
// }