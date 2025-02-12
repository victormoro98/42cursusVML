/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:30:41 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/02/04 19:57:12 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

static size_t	count_words(char const *s, char c)
{
	bool	in_word;
	size_t	count;
	int		i;

	count = 0;
	i = 0;
	in_word = false;
	while (s[i] != '\0')
	{
		if ((char)s[i] == c)
			in_word = false;
		else if ((char)s[i] != c && !in_word)
		{
			in_word = true;
			count++;
		}
		i++;
	}
	return (count);
}

static char	*add_words(char const *s, int *j, char c)
{
	int		i;
	char	*result;

	i = 0;
	while (s[*j] == c)
		(*j)++;
	i = *j;
	while (s[i] != '\0' && s[i] != c)
		i++;
	result = ft_substr(s, *j, i - *j);
	*j = i;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		j;
	int		i;
	int		words;

	words = count_words(s, c);
	j = 0;
	i = 0;
	result = malloc(sizeof(char *) * (words + 1));
	if (!result || !s)
		return (NULL);
	result[words] = NULL;
	while (i < words)
	{
		result[i] = add_words(s, &j, c);
		if (!result[i])
		{
			while (i > 0)
				free(result[--i]);
			free(result);
			return (NULL);
		}
		i++;
	}
	return (result);
}

/* int		main(void)
{
	char const *s1 = ",, hola ,pisha, q, tal     ";
	char c = ',';
	char **result;
	result = ft_split(s1, c);
	if (!result)
		return (0);
	for (size_t i = 0 ; i < count_words(s1, c) ; i++)
	{
		printf("%s", result[i]);
		free(result[i]);
	}
	free(result);
	return(0);
} */