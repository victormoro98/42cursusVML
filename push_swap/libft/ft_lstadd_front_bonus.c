/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:39:53 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/02/04 19:56:12 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
	return ;
}

// int main (void)
// {
// 	t_list	*head = NULL;

// 	t_list *node1 = malloc(sizeof(t_list));
// 	t_list *node2 = malloc(sizeof(t_list));
// 	t_list *node3 = malloc(sizeof(t_list));

// 	node1->content = "Nodo 1";
// 	node1->next = NULL;
// 	node2->content = "Nodo 2";
// 	node2->next = NULL;
// 	node3->content = "Nodo 3";
// 	node3->next = NULL;

// 	ft_lstadd_front(&head, node1);
// 	ft_lstadd_front(&head, node2);
// 	ft_lstadd_front(&head, node3);

// 	while(head)
// 	{
// 		printf("%s\n", (char *)head->content);
// 		head=head->next;
// 	}
// 	return(0);
// }