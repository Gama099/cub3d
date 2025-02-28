/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hadd <sel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:02:53 by sel-hadd          #+#    #+#             */
/*   Updated: 2025/02/28 16:05:34 by sel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	set_color(char *buffer, char type, t_map_data *data, char *start)
{
	static int	f_i;
	static int	c_i;

	on_off(buffer);
	if ((type == 'F') && (f_i < 3))
	{
		data->floor_color[f_i] = ft_atoi(start);
		if (data->floor_color[f_i] < 0 || data->floor_color[f_i] > 250)
			handle_error(ERR_COLOR_OUT_OF_RANGE);
		f_i++;
	}
	else if ((type == 'C') && (c_i < 3))
	{
		data->ceiling_color[c_i] = ft_atoi(start);
		if (data->ceiling_color[c_i] < 0 || data->ceiling_color[c_i] > 250)
			handle_error(ERR_COLOR_OUT_OF_RANGE);
		c_i++;
	}
	else if (f_i >= 3 || c_i >= 3)
		handle_error(ERR_INVALID_COLOR_FORMAT);
	on_off(buffer);
}

static void	clr(char *buffer, t_map_data *data, char type)
{
	char	*start;

	while (buffer)
	{
		if (*buffer == '\0')
			break ;
		if (!is_digit(*buffer))
			handle_error(ERR_INVALID_COLOR_FORMAT);
		start = buffer;
		while (is_digit(*buffer))
			buffer++;
		if (*buffer == ',' || *buffer == '\n')
			set_color(buffer, type, data, start);
		else
			handle_error(ERR_MISSING_COLOR);
		buffer++;
	}
}

void	parse_colors(t_map_data *data)
{
	char	type;
	char	*buffer;

	buffer = data->buffer;
	type = *buffer;
	if (!is_space(*(buffer + 1)))
		handle_error(ERR_INVALID_COLOR_FORMAT);
	buffer = (buffer + 1);
	while (is_space(*buffer))
		buffer++;
	clr(buffer, data, type);
}

int	is_colors(char *buffer)
{
	return ((*buffer == 'F' || *buffer == 'C'));
}
