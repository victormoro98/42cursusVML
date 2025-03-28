/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:09:59 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/02/04 20:23:14 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// void	del(void *content)
// {
// 	free(content);
// }
// int	main()
// {
// 	t_list *node1 = malloc(sizeof(char) * 15);
// 	ft_lstnew(node1);
// 	if (!node1)
// 		return (1);
// 	node1->content = "Hola mundo";
// 	printf("Contenido antes de la eliminación: %s\n", (char *)node1->content);
// 	ft_lstdelone(node1, del);
// 	return(0);
// }	