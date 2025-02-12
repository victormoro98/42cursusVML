/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:11:28 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/02/12 16:24:39 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

char	*read_complete_line(int	fd, char *new_line)
{
	char			*read_buffer;
	int				bytes_read;

	read_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	bytes_read = 1;
	while (bytes_read != 0 && !ft_strchr(read_buffer, '\n'))
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(new_line);
			free(read_buffer);
			return (NULL);
		}
		read_buffer[bytes_read + 1] = '\0';
		new_line = ft_strjoin(new_line, read_buffer);
	}
	return (new_line);
}

char	*process_line(char *new_line)
{
	int		i;
	char	*processed_line;

	i = 0;
	while (new_line[i] != '\n')
		i++;
	processed_line = ft_substr(new_line, 0, i + 1);
	processed_line[i + 1] = '\0';
	return (processed_line);
}

char	*remaining_line(char *new_line)
{
	int		i;
	char	*remaining;

	i = 0;
	while (new_line[i] != '\n')
		i++;
	remaining = ft_substr(new_line, i + 1, ft_strlen(new_line) - i);
	return (remaining);
}

char	*get_next_line(int fd)
{
	static	char	*static_buffer;
	char			*new_line;

	if (!static_buffer)
		static_buffer = malloc(sizeof(char) * 1);
	new_line = read_complete_line(fd, static_buffer);
	if (ft_strchr(new_line, '\n'))
	{	
		static_buffer = 
		new_line = process_line(new_line);
	}
	return (new_line);
}

int main(void)
{
    int fd = open("prueba.txt", O_RDONLY);

    printf("Línea: %s\n", get_next_line(fd));
    close(fd);
	printf("Línea: %s\n", get_next_line(fd));
    close(fd);
    return (0);
}