/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:13:36 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/01/30 10:24:57 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	start(char const *s1, char const *set)
{
	size_t	iter_s1;

	iter_s1 = 0;
	while (s1[iter_s1] && ft_strchr(set, s1[iter_s1]))
	{
		iter_s1++;
	}
	return (iter_s1);
}

static size_t	finish(char const *s1, char const *set)
{
	size_t	iter_s1;

	iter_s1 = ft_strlen(s1);
	while (iter_s1 > 0 && ft_strrchr(set, s1[iter_s1 - 1]))
	{
		iter_s1--;
	}
	return (iter_s1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1_start;
	size_t	s1_finish;
	char	*s1_trimed;

	if (s1 == NULL || set == NULL)
		return (ft_strdup(""));
	s1_start = start(s1, set);
	s1_finish = finish(s1, set);
	if (s1_start > s1_finish)
		return (ft_strdup(""));
	s1_trimed = malloc(sizeof(char) * (s1_finish - s1_start + 1));
	if (!s1_trimed)
		return (0);
	ft_strlcpy(s1_trimed, (char *)(s1 + s1_start), s1_finish - s1_start + 1);
	return (s1_trimed);
}

// int main(void)
// {
// 	const char *s1 = "";
// 	const char *set = "sd";

// 	char *result = ft_strtrim(s1, set);
// 	if (result)
// 	{
// 		printf("%s\n", result);
// 		free(result);
// 	}

// 	return (0);
// }