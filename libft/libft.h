/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:41:27 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/01/20 14:52:42 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_strlen(char *str);
void	*ft_memset(void *s, int c, int n);
void	ft_bzero(void *s, int n);
void	*ft_memcpy(void	*dest, const void *src, int n);
void	*ft_memmove(void	*dest, const void *src, int n);
int		ft_strlcpy(char	*dest, char *src, unsigned int c);
int		ft_strlcat(char *dst, const char *src, int size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);

#endif