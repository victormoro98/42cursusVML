/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_execve.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoro-lu <vmoro-lu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:53:34 by vmoro-lu          #+#    #+#             */
/*   Updated: 2025/06/25 15:32:57 by vmoro-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(int argc, char **argv, char **envp)
{
	int	fd_out;

	fd_out = open("salida.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out < 0)
	{
		perror("open");
		return (1);
	}
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);

	char	*cmd = "/bin/ls";
	char 	*args[] = {"ls", "-la", NULL};
	if (execve(cmd, argv, envp) == -1)
	{
		perror("execve");
		return (1);
	}
	return (0);
}
