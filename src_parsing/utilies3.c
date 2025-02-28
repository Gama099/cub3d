/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilies3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hadd <sel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:25:25 by sel-hadd          #+#    #+#             */
/*   Updated: 2025/02/28 15:59:29 by sel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*ft_strdup(char *s1)
{
	int		i;
	int		dupsize;
	char	*dup;

	if (s1 == NULL)
		return (NULL);
	dupsize = ft_strlen(s1) + 1;
	dup = (char *)my_malloc(dupsize);
	i = 0;
	while (i < dupsize)
	{
		dup[i] = s1[i];
		i++;
	}
	return (dup);
}

int	ft_strlen(const char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

// Main error printing function
void	print_error_message(error_code code)
{
	if (code == ERR_NONE)
		printf("ERR_NONE\n");
	else if (code >= ERR_FILE_NOT_FOUND && code <= ERR_FILE_PERMISSION)
		print_file_error(code);
	else if (code >= ERR_MISSING_TEXTURE && code <= ERR_TEXTURE_FILE_MISSING)
		print_texture_error(code);
	else if (code >= ERR_MISSING_COLOR && code <= ERR_COLOR_OUT_OF_RANGE)
		print_color_error(code);
	else if (code >= ERR_MAP_NOT_CLOSED && code <= ERR_NEW_LINE_IN_MAP)
		print_map_error(code);
	else
		print_general_error(code);
}
