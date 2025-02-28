/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilies1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hadd <sel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:20:20 by sel-hadd          #+#    #+#             */
/*   Updated: 2025/02/28 16:05:34 by sel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	on_off(char *change)
{
	static char	c;

	if (change == NULL)
		return ;
	if (c == '\0')
	{
		c = *change;
		*change = '\0';
	}
	else
	{
		*change = c;
		c = '\0';
	}
}

void	resize(char ***array, int size)
{
	char	**vector;
	int		i;

	i = 0;
	vector = (char **)my_malloc(sizeof(char *) * (size + 1));
	if (!vector)
		handle_error(ERR_MEMORY_ALLOCATION);
	while (i < size && size > 0)
	{
		if ((*array)[i] != NULL)
			vector[i] = (*array)[i];
		else
			vector[i] = NULL;
		i++;
	}
	*array = vector;
}

void	assign_struct(t_map_data *data)
{
	data->buffer = NULL;
	data->east_texture = NULL;
	data->west_texture = NULL;
	data->south_texture = NULL;
	data->north_texture = NULL;
	data->ceiling_color[0] = -1;
	data->ceiling_color[1] = -1;
	data->ceiling_color[2] = -1;
	data->floor_color[0] = -1;
	data->floor_color[1] = -1;
	data->floor_color[2] = -1;
	data->player_dir = '\0';
	data->map_height = 0;
	data->map_width = 0;
	data->player_x = 0;
	data->player_y = 0;
}

void	handle_error(error_code err)
{
	cleanup();
	print_error_message(err);
	exit(err);
}

int	open_file(char *file_name, int close_flag)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	if (close_flag)
	{
		close(fd);
		return (1);
	}
	else
		return (fd);
}
