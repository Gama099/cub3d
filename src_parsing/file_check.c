/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hadd <sel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:17:20 by sel-hadd          #+#    #+#             */
/*   Updated: 2025/02/28 16:05:34 by sel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	is_readable(char *file_name, int *fd)
{
	*fd = open(file_name, O_RDONLY);
	return (*fd != -1);
}

static int	is_empty(int fd)
{
	char	buff;
	ssize_t	bytes_read;

	bytes_read = read(fd, &buff, 1);
	if (bytes_read == 0)
		return (0);
	return (1);
}

void	check_file(char *file_name, int *fd)
{
	if (!is_readable(file_name, fd))
		handle_error(ERR_FILE_PERMISSION);
	if (!is_extension(file_name, ".cub"))
		handle_error(ERR_FILE_EXTENSION);
	if (!is_empty(*fd))
		handle_error(ERR_EMPTY_FILE);
	close(*fd);
	*fd = open(file_name, O_RDONLY);
	return ;
}
