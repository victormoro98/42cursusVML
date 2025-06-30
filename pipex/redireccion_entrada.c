/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redireccion_entrada.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:59:42 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/06/24 18:20:29 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>


int	main(void)
{
	int		fd_in;
	int		fd_out;
	char	buffer[1024];
	ssize_t	bytes;

	fd_in = open("entrada.txt", O_RDONLY);
	fd_out = open("salida.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if (fd_in < 0 || fd_out < 0)
	{
		perror("open");
		return (1);
	}
	dup2(fd_in, STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(0, buffer, sizeof(buffer));
		write (1, buffer, bytes);
	}
	close(fd_in);
	close(fd_out);
	return (0);
}
