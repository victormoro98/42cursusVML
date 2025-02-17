/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:11:28 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/02/13 14:39:52 by vmoro-lu         ###   ########.fr       */
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
	printf("read_complete_line_new_line -> %s\n", new_line);
	return (new_line);
}

void	remaining_line(char **static_buffer, char *new_line, int i) //modificacion
{
	// char	*linea_guardada = NULL;
	int len = ft_strlen(new_line);
	printf("remaining_line_static_NW-> %s\n", new_line);
	if (new_line[i + 1] != '\0')
	{
		free(*static_buffer); // modificacion
		*static_buffer = ft_substr(new_line, i + 1, len); // modificacion (len - i)
	}
	printf("remaining_line_static_SB-> %s\n", *static_buffer);
}

char	*process_line(char *new_line, char **static_buffer)
{
	int		i;
	char	*processed_line;

	i = 0;
	while (new_line[i] != '\n')
		i++;

	processed_line = ft_substr(new_line, 0, i + 1);
	processed_line[i + 1] = '\0';
	printf("process_line_static_PROCESSED_LINE-> %s\n", processed_line);
	remaining_line(static_buffer, new_line, i);

	printf("process_line_static_SB-> %s\n", *static_buffer);
	//free(new_line);
	return (processed_line);
}

char	*get_next_line(int fd)
{
	static	char	*static_buffer;
	char			*new_line;

	if (!static_buffer)
		new_line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	else
		new_line = ft_strjoin(static_buffer, new_line);

	new_line = read_complete_line(fd, new_line);
	
	if (ft_strchr(new_line, '\n'))
		new_line = process_line(new_line, &static_buffer);
	
	printf("GNLstatic-> %s\n", static_buffer);
	printf("GNL_new_line %s\n", new_line);
	return (new_line);
}

int main(void)
{
    int fd = open("prueba.txt", O_RDONLY);

    printf("1_LECTURA_Línea: %s\n", get_next_line(fd));
	printf("2_LECTURA_Línea: %s\n", get_next_line(fd));
    close(fd);
    return (0);
}
