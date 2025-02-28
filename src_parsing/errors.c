/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hadd <sel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:45:31 by sel-hadd          #+#    #+#             */
/*   Updated: 2025/02/28 15:59:16 by sel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	print_file_error(error_code code)
{
	if (code == ERR_FILE_NOT_FOUND)
		printf("ERR_FILE_NOT_FOUND\n");
	else if (code == ERR_FILE_EXTENSION)
		printf("ERR_FILE_EXTENSION\n");
	else if (code == ERR_EMPTY_FILE)
		printf("ERR_EMPTY_FILE\n");
	else if (code == ERR_FILE_PERMISSION)
		printf("ERR_FILE_PERMISSION\n");
}

// Texture-related errors
void	print_texture_error(error_code code)
{
	if (code == ERR_MISSING_TEXTURE)
		printf("ERR_MISSING_TEXTURE\n");
	else if (code == ERR_DUPLICATE_TEXTURE)
		printf("ERR_DUPLICATE_TEXTURE\n");
	else if (code == ERR_INVALID_TEXTURE_PATH)
		printf("ERR_INVALID_TEXTURE_PATH\n");
	else if (code == ERR_TEXTURE_FILE_MISSING)
		printf("ERR_TEXTURE_FILE_MISSING\n");
}

// Color-related errors
void	print_color_error(error_code code)
{
	if (code == ERR_MISSING_COLOR)
		printf("ERR_MISSING_COLOR\n");
	else if (code == ERR_DUPLICATE_COLOR)
		printf("ERR_DUPLICATE_COLOR\n");
	else if (code == ERR_INVALID_COLOR_FORMAT)
		printf("ERR_INVALID_COLOR_FORMAT\n");
	else if (code == ERR_COLOR_OUT_OF_RANGE)
		printf("ERR_COLOR_OUT_OF_RANGE\n");
}

// Map-related errors
void	print_map_error(error_code code)
{
	if (code == ERR_MAP_NOT_CLOSED)
		printf("ERR_MAP_NOT_CLOSED\n");
	else if (code == ERR_INVALID_MAP_CHAR)
		printf("ERR_INVALID_MAP_CHAR\n");
	else if (code == ERR_MULTIPLE_PLAYERS)
		printf("ERR_MULTIPLE_PLAYERS\n");
	else if (code == ERR_MISSING_PLAYER)
		printf("ERR_MISSING_PLAYER\n");
	else if (code == ERR_INVALID_MAP_START)
		printf("ERR_INVALID_MAP_START\n");
	else if (code == ERR_INVALID_MAP_END)
		printf("ERR_INVALID_MAP_END\n");
	else if (code == ERR_NEW_LINE_IN_MAP)
		printf("ERR_NEW_LINE_IN_MAP\n");
}

// General errors
void	print_general_error(error_code code)
{
	if (code == ERR_INVALID_LINE)
		printf("ERR_INVALID_LINE\n");
	else if (code == ERR_MEMORY_ALLOCATION)
		printf("ERR_MEMORY_ALLOCATION\n");
	else if (code == ERR_NOT_TEXTURE)
		printf("ERR_NOT_TEXTURE\n");
	else if (code == ERR_NOT_IMG)
		printf("ERR_NOT_IMG\n");
	else if (code == ERR_NOT_MAP)
		printf("ERR_NOT_MAP\n");
}
