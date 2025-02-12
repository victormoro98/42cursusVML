/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:08:17 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/02/04 20:44:50 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!new || !lst)
		return ;
	last = ft_lstlast(*lst);
	if (!last)
		*lst = new;
	else
		last->next = new;
}

// int main (void)
// {	
// 	t_list *new = ft_lstnew("nodo final");
// 	t_list *node1 = ft_lstnew("nodo 1");
// 	t_list *node2 = ft_lstnew("nodo 2");
// 	t_list *node3 = ft_lstnew("nodo 3");
// 	t_list **primer_nodo = &node1;
// 	t_list *temp;
// 	node1->next = node2;
// 	node2->next = node3;
// 	ft_lstadd_back(primer_nodo, new);
// 	temp = *primer_nodo;
// 	while(temp)
// 	{
// 		printf("%s\n", (char *)temp->content);
// 		temp = temp->next;	
// 	}
// 	free(node1);
// 	free(node2);
// 	free(node3);
// 	free(new);
// 	return (0);
// }