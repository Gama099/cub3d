/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilies2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hadd <sel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:25:25 by sel-hadd          #+#    #+#             */
/*   Updated: 2025/02/28 15:07:17 by sel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	is_space(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '+' && str[i + 1] != '-')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	result *= sign;
	return (result);
}

void	trim_buffer(char **buffer)
{
	char	*start;
	char	*end;

	if (buffer == NULL || *buffer == NULL || **buffer == '\0')
		return ;
	start = *buffer;
	while (*start != '\0' && is_space((unsigned char)*start))
		start++;
	if (*start == '\0')
	{
		*buffer = start;
		return ;
	}
	end = start + ft_strlen(start) - 1;
	while (end > start && is_space((unsigned char)*end))
		end--;
	*(end + 1) = '\n';
	*buffer = start;
}

int	is_extension(char *file_name, char *extan)
{
	char	*dot;

	dot = strrchr(file_name, '.');
	if (!dot || dot == file_name)
		return (0);
	return (ft_strcmp(dot, extan) == 0);
}
