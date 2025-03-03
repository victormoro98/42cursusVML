/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:12:02 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/02/27 19:47:42 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*concat;
	size_t	len_concat;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (0);
	len_concat = (ft_strlen(s1) + ft_strlen(s2) + 1);
	concat = ft_calloc(sizeof(char), len_concat);
	if (!concat)
		return (0);
	while (s1[i] != '\0')
	{
		concat[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0' && j < (int)len_concat)
	{
		concat[i + j] = s2[j];
		j++;
	}
	concat[i + j] = '\0';
	free(s1);
	return (concat);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	len_s;
	size_t	i;
	char	*substr;

	i = 0;
	len_s = ft_strlen(s);
	if (s == NULL)
		return (0);
	if (len > len_s - start)
		len = len_s - start;
	if (start >= len_s)
	{
		substr = ft_calloc(sizeof(char), 1);
		return (substr);
	}
	substr = ft_calloc(sizeof(char), (len + 1));
	if (!substr)
		return (0);
	while (i < len)
	{
		substr[i] = s[start + i];
		++i;
	}
	substr[i] = '\0';
	return (substr);
}

// char	*ft_strdup(const char *s)
// {
// 	char			*str_duplicated;
// 	size_t			len;

// 	len = ft_strlen(s);
// 	if (s == NULL)
// 		return (NULL);
// 	str_duplicated = malloc(sizeof(char) * (len + 1));
// 	if (str_duplicated == NULL)
// 		return (NULL);
// 	ft_strlcpy(str_duplicated, (char *)s, len + 1);
// 	return (str_duplicated);
// }

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char )c == s[i])
		return ((char *)(s + i));
	return (0);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if(!str)
		return(0);
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	if (nmemb != 0 && (nmemb * size) / nmemb != size)
		return (NULL);
	ptr = (void *)malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	if (size == 0)
		return (ptr);
	i = 0;
	while (i < (nmemb * size))
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}