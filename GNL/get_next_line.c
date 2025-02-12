/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:11:28 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/02/11 18:57:11 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

char	*rest_line_before(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	while (buffer)
	{
		if (buffer[i] == '\n')
			line = ft_substr(buffer, 0, i - 1);
	}
	return(line);
}
char	*get_next_line(int	fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			bytes_read;
	int			i;
	char		*line;
	size_t		len_buff;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return(NULL);
	len_buff = ft_strlen(buffer);
	i = 0;
	while (buffer[i])
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line = ft_substr(buffer, 0, bytes_read - i);
	}
	line = ft_strjoin(buffer, line);
}
int main(void)
{
    int fd = open("prueba.txt", O_RDONLY);

    char *line;
    while ((line = get_next_line(fd)) != NULL) // Llamamos repetidamente hasta que devuelva NULL
    {
        printf("Línea: %s\n", line);
        free(line);  // Importante liberar la memoria después de cada línea
    }
    close(fd);
    return (0);
}