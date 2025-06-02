/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 09:33:52 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/05/07 15:07:11 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*next_node;

	next_node = malloc(sizeof(struct s_list));
	if (!next_node)
		return (0);
	next_node->next = NULL;
	next_node->content = content;
	return (next_node);
}
/* int	main(void)
{
	t_list	*node;
	char	*str;

	str =  "esto no es facil, pero vas a conseguirlo!";
	node = ft_lstnew(str);
	if (!node)
		return (1);
	printf("que contiene el nodo?: %s\n", (char *)node->content);
	free (node);
	return(0);
} */
