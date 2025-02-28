/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hadd <sel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:01:35 by sel-hadd          #+#    #+#             */
/*   Updated: 2025/02/28 16:05:34 by sel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*is_path(char *path)
{
	int		img_fd;
	char	*new_line;

	if (!*path)
		return (0);
	while (is_space(*path))
		path++;
	if (*path)
	{
		new_line = ft_strchr(path, '\n');
		on_off(new_line);
		path = ft_strdup(path);
		on_off(new_line);
		img_fd = open(path, O_RDONLY);
		if ((img_fd == -1) || !is_extension(path, ".txt"))
			handle_error(ERR_INVALID_TEXTURE_PATH);
		close(img_fd);
		return (path);
	}
}

static int	is_texture_full(t_map_data *data)
{
	return (data->north_texture && data->south_texture
		&& data->west_texture && data->east_texture);
}

int	identifier_found(char *buffer)
{
	if (((buffer[0] == 'N') && (buffer[1] == 'O') && (is_space(buffer[2])))
		|| ((buffer[0] == 'S') && (buffer[1] == 'O') && (is_space(buffer[2])))
		|| ((buffer[0] == 'W') && (buffer[1] == 'E') && (is_space(buffer[2])))
		|| ((buffer[0] == 'E') && (buffer[1] == 'A') && (is_space(buffer[2]))))
		return (1);
	return (0);
}

void	set_texture(t_map_data *data, char *buffer, char *img_path)
{
	if (is_texture_full(data))
		handle_error(ERR_DUPLICATE_TEXTURE);
	else if ((buffer[0] == 'N') && !data->north_texture)
		data->north_texture = img_path;
	else if ((buffer[0] == 'S'))
		data->south_texture = img_path;
	else if ((buffer[0] == 'W'))
		data->west_texture = img_path;
	else if ((buffer[0] == 'E'))
		data->east_texture = img_path;
	else
		handle_error(ERR_DUPLICATE_TEXTURE);
}

void	parse_texture(t_map_data *data)
{
	char	*img_path;
	char	*buffer;

	buffer = data->buffer;
	img_path = is_path(&buffer[2]);
	set_texture(data, buffer, img_path);
}
