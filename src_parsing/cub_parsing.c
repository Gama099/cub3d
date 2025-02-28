/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hadd <sel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:13:45 by sel-hadd          #+#    #+#             */
/*   Updated: 2025/02/28 16:08:46 by sel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_memoryblock	*ghead = NULL;

void	check_after_parsing(t_map_data *data)
{
	int	i;

	if (!data->north_texture || !data->south_texture
		|| !data->west_texture || !data->east_texture)
	{
		handle_error(ERR_MISSING_TEXTURE);
	}
	i = 0;
	while (i < 3)
	{
		if (data->floor_color[i] == -1 || data->ceiling_color[i] == -1)
			handle_error(ERR_MISSING_COLOR);
		i++;
	}
	i = 0;
}

void	parsing_loop(t_map_data *data, int fd)
{
	while (data->buffer)
	{
		trim_buffer(&data->buffer);
		if (*data->buffer == '\0')
		{
			data->buffer = get_next_line(fd);
			continue ;
		}
		else if (identifier_found(data->buffer))
			parse_texture(data);
		else if (is_colors(data->buffer))
			parse_colors(data);
		else if (is_maap(data->buffer))
			parse_map(data, fd);
		else
			handle_error(ERR_INVALID_LINE);
		data->buffer = get_next_line(fd);
	}
}

t_map_data	*parsing_file(char *file_name)
{
	t_map_data		*data;
	int				fd;

	data = (t_map_data *)my_malloc(sizeof(t_map_data));
	assign_struct(data);
	check_file(file_name, &fd);
	data->buffer = get_next_line(fd);
	parsing_loop(data, fd);
	check_after_parsing(data);
	return (data);
}

void print_map_data(t_map_data *data) {
    printf("\n");
    printf("--------------\n");
    printf("North texture: %s\n", data->north_texture);
    printf("South texture: %s\n", data->south_texture);
    printf("West texture: %s\n", data->west_texture);
    printf("East texture: %s\n", data->east_texture);

    printf("Floor color: RGB(%d, %d, %d)\n", data->floor_color[0], data->floor_color[1], data->floor_color[2]);
    printf("Ceiling color: RGB(%d, %d, %d)\n", data->ceiling_color[0], data->ceiling_color[1], data->ceiling_color[2]);

    printf("Map dimensions: %dx%d\n", data->map_width, data->map_height);

    // Printing the map if it's a 2D array of characters
    printf("Map:\n");
    for (int i = 0; i < data->map_height; i++) {
        printf("%s\n", data->map[i]);
    }

    printf("Player position: (%d, %d)\n", data->player_x, data->player_y);
    printf("Player direction: %c\n", data->player_dir);
    printf("--------------");
    printf("\n");
}

int	main(int ac, char **av)
{
	t_map_data *data;
	if (ac == 2)
	{
		data = parsing_file(av[1]);
		print_map_data(data);
		cleanup();
	}
}