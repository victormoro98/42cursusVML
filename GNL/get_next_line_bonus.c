/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:11:28 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/03/10 00:23:16 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

char	*read_complete_line(int	fd, char *static_buffer)
{
	char			*read_buffer;
	int				bytes_read = 1;
	
	if (!static_buffer)
		static_buffer = ft_calloc(sizeof(char), 1);
	read_buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!read_buffer)
		return(NULL);
	while(bytes_read > 0 && !ft_strchr(read_buffer, '\n'))
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(static_buffer);
			free(read_buffer);
			return(NULL);
		}
		read_buffer[bytes_read] = '\0';
		static_buffer = ft_strjoin(static_buffer, read_buffer);
	}
	free(read_buffer);
	return (static_buffer);
}
char	*process_line(char *new_line)
{
	int		i;
	char	*processed_line;

	i = 0;
	while (new_line[i] && new_line[i] != '\n')
		i++;
	processed_line = ft_substr(new_line, 0, i + 1);
	if (*new_line == '\0')
	{
		free(processed_line);
		processed_line = NULL;
	}
	return (processed_line);
}

char	*remaining_line(char *new_line)
{
	int		i;
	char	*remaining;

	i = 0;
	while (new_line[i] && new_line[i] != '\n')
		i++;
	if (!new_line[i])
		return(free(new_line), NULL);
	remaining = ft_substr(new_line, i + 1, ft_strlen(new_line) - (i + 1));
	free(new_line);
	return (remaining);
}


char	*get_next_line(int fd)
{
	int				i;
	static	char	*static_buffer[1024];
	char			*next_line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	static_buffer[i] = read_complete_line(fd, static_buffer);
	if (!static_buffer)
		return (NULL);
	next_line = process_line(static_buffer);
	if (next_line == NULL)
		return(free(static_buffer), static_buffer[i] = NULL);
	static_buffer[i] = remaining_line(static_buffer);
	if (next_line && *next_line == '\0')
		return (free(next_line), free(static_buffer), NULL);
	return (next_line);
}

// int main(void)
// {
//     int fd = open("prueba.txt", O_RDONLY);
// 	char *line = NULL;
// 	int flag = 1;
// 	int	i = 1;
// 	while (line || flag == 1)
// 	{
// 		flag = 0;
// 		line = get_next_line(fd);
// 		printf("linea[%i] = %s", i, line);
// 		free(line);
// 		i++;
// 	}
// 	// line = get_next_line(fd);
// 	// printf("linea[] = %s", line);
// 	// free(line);
// 	// line = get_next_line(fd);
// 	// printf("linea[] = %s", line);
// 	// free(line);
// 	// line = get_next_line(fd);
// 	// printf("linea[] = %s", line);
// 	// free(line);
// 	close(fd);
//     return (0);
// }
