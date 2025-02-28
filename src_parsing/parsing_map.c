/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hadd <sel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:03:43 by sel-hadd          #+#    #+#             */
/*   Updated: 2025/02/28 16:05:34 by sel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	check_start_close(char *iter)
{
	if (*iter != '1')
		handle_error(ERR_MAP_NOT_CLOSED);
}

static void	read_map(int fd, t_map_data *data, size_t *size)
{
	char	*buffer;
	char	*iter;
	int		w;
	int		h;

	h = 1;
	buffer = get_next_line(fd);
	while (buffer && *buffer != '\n')
	{
		w = 0;
		h++;
		iter = buffer;
		check_start_close(iter);
		while (*iter && *iter != '\n')
		{
			is_allawed(iter);
			check_position(iter++, data, w++, h);
		}
		check_last_close(iter);
		assign_directions(w, h, data);
		resize(&data->map, *size);
		set_map_line(buffer, size, data);
		buffer = get_next_line(fd);
	}
}

static void	check_eomap(int fd)
{
	char	*buffer;

	buffer = get_next_line(fd);
	while (buffer)
	{
		if (*buffer != '\n')
			handle_error(ERR_INVALID_LINE);
		buffer = get_next_line(fd);
	}
}

int	is_maap(char *buffer)
{
	if (*buffer == '1')
	{
		while (*buffer == '1')
			buffer++;
		if (*buffer == '\n')
			return (1);
		handle_error(ERR_INVALID_MAP_START);
	}
	return (0);
}

void	parse_map(t_map_data *data, int fd)
{
	size_t	size;
	char	*iter;

	size = 0;
	resize(&data->map, size);
	set_map_line(data->buffer, &size, data);
	read_map(fd, data, &size);
	if (!data->player_x || !data->player_y || !data->player_dir)
		handle_error(ERR_MISSING_PLAYER);
	check_eomap(fd);
	iter = data->map[data->map_height - 1];
	while (*iter == '1')
		iter++;
	if (*iter != '\n' && *iter != '\0')
		handle_error(ERR_INVALID_MAP_END);
}
