/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:11:28 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/03/10 14:24:30 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_complete_line(int fd, char *static_buffer)
{
	char	*read_buffer;
	int		bytes_read;

	bytes_read = 1;
	if (!static_buffer)
		static_buffer = ft_calloc(sizeof(char), 1);
	read_buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!read_buffer)
		return (NULL);
	while (bytes_read > 0 && !ft_strchr(read_buffer, '\n'))
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(static_buffer);
			free(read_buffer);
			return (NULL);
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
		return (free(new_line), NULL);
	remaining = ft_substr(new_line, i + 1, ft_strlen(new_line) - (i + 1));
	free(new_line);
	return (remaining);
}

char	*get_next_line(int fd)
{
	static char		*static_buffer[4096];
	char			*next_line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	static_buffer[fd] = read_complete_line(fd, static_buffer[fd]);
	if (!static_buffer[fd])
		return (NULL);
	next_line = process_line(static_buffer[fd]);
	if (next_line == NULL)
		return (free(static_buffer[fd]), static_buffer[fd] = NULL);
	static_buffer[fd] = remaining_line(static_buffer[fd]);
	if (next_line && *next_line == '\0')
		return (free(next_line), free(static_buffer[fd]), NULL);
	return (next_line);
}

// int main(void)
// {
//     int fd1 = open("prueba.txt", O_RDONLY);
// 	int fd2 = open("prueba_1.txt", O_RDONLY);
// 	char *line1;
// 	char *line2;
// 	int  flag = 1;
// 	int	i = 1;
// 	int j = 1;
// 	while (flag != 0 || line1 || line2)
// 	{
// 		flag = 0;
// 		line1 = get_next_line(fd1);
// 		line2 = get_next_line(fd2);
// 		if (line1)
// 		{
// 		printf("linea_fd1[%i] = %s\n", i++, line1);
// 		free(line1);
// 		}
// 		if (line2)
// 		{
// 		printf("linea_fd2[%i] = %s\n", j++, line2);
// 		free(line2);
// 		}
// 	}
// 	close(fd1);
// 	close(fd2);
//     return (0);
// }
