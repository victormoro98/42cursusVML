/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:11:28 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/03/03 16:05:00 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

char	*process_line(char *new_line)
{
	int		i;
	char	*processed_line;

	i = 0;
	while (new_line[i] && new_line[i] != '\n')
		i++;
	processed_line = ft_substr(new_line, 0, i + 1);
	return (processed_line);
}

char	*remaining_line(char *new_line)
{
	int		i;
	char	*remaining;

	i = 0;
	while (new_line[i] && new_line[i] != '\n')
		i++;
	remaining = ft_substr(new_line, i + 1, ft_strlen(new_line) - (i + 1));
	free (new_line);
	return (remaining);
}

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
		// if (bytes_read == 0)
		// 	return(NULL);
		read_buffer[bytes_read] = '\0';
		static_buffer = ft_strjoin(static_buffer, read_buffer);
	}
	free(read_buffer);
	return (static_buffer);
}

char	*get_next_line(int fd)
{
	static	char	*static_buffer = NULL;
	char			*new_line = NULL;
	char			*next_line = NULL;

	new_line = read_complete_line(fd, static_buffer);
	if (!new_line)
		return(NULL);
	if (ft_strchr(new_line, '\n'))
	{
		// free(static_buffer);
		next_line = process_line(new_line);
		static_buffer = remaining_line(new_line);
		return(next_line);
	}
	// else
	else if(new_line && new_line[0] == '\0')
	{
		free(new_line);
		new_line = NULL;
	}
	return(new_line);
}

// int main(void)
// {
//     int fd = open("prueba.txt", O_RDONLY);
// 	char *line;
// 	// int i = 0;
// 	line = get_next_line(fd);
// 	printf("linea[] = %s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("linea[] = %s", line);
// 	free(line);
// 	// line = get_next_line(fd);
// 	// printf("linea[] = %s", line);
// 	// free(line);
// 	// while(line != NULL)
// 	// {
// 	// 	printf("linea[%i] = %s\n", i++, line);
// 	// 	free(line);
// 	// 	line = get_next_line(fd);
// 	// }
// 	close(fd);
//     return (0);
// }
