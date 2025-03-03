/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:11:56 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/02/27 19:30:58 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
char	*read_complete_line(int	fd, char *new_line);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlen(char *str);
int		ft_strlcpy(char	*dest, char *src, size_t c);
void	*ft_calloc(size_t nmemb, size_t size);

#endif