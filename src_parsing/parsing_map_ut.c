/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_ut.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hadd <sel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:03:43 by sel-hadd          #+#    #+#             */
/*   Updated: 2025/02/28 16:05:34 by sel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	set_map_line(char *buffer, size_t *size, t_map_data *data)
{
	char	*new_line;

	new_line = strchr(buffer, '\n');
	on_off(new_line);
	(data)->map[*size] = ft_strdup(buffer);
	on_off(new_line);
	*size += 1;
}

int	is_allawed(char *iter)
{
	if (*iter != '1' && *iter != '0' && *iter != 'N'
		&& *iter != 'W' && *iter != 'E' && *iter != 'S' && *iter != ' ')
	{
		handle_error(ERR_INVALID_MAP_CHAR);
	}
}

void	check_position(char *iter, t_map_data *data, int w, int h)
{
	if ((*iter == 'N' || *iter == 'W' || *iter == 'E' || *iter == 'S'))
	{
		if (data->player_dir == '\0')
		{
			data->player_x = w;
			data->player_y = h;
			data->player_dir = *iter;
		}
		else
			handle_error(ERR_MULTIPLE_PLAYERS);
	}
}

void	assign_directions(int w, int h, t_map_data *data)
{
	if (w > data->map_width)
		data->map_width = w;
	if (h > data->map_height)
		data->map_height = h;
}

void	check_last_close(char *iter)
{
	if (*iter == '\n' && (*(iter -1) != '1'))
		handle_error(ERR_MAP_NOT_CLOSED);
}
