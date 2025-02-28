/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hadd <sel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 04:19:12 by sel-hadd          #+#    #+#             */
/*   Updated: 2025/02/28 14:34:32 by sel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	add_node(t_list **head, char *buffer)
{
	t_list	*new_node;
	t_list	*current_node;

	new_node = my_malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->content = buffer;
	new_node->next = NULL;
	if (!*head)
		*head = new_node;
	else
	{
		current_node = *head;
		while (current_node->next)
			current_node = current_node->next;
		current_node->next = new_node;
	}
}

void	new_head(t_list **head)
{
	t_list	*last;
	int		i;
	char	*data;
	t_list	*node;
	char	*new_buffer;

	last = last_node(head);
	i = 0;
	data = last->content;
	node = my_malloc(sizeof(t_list));
	new_buffer = my_malloc(BUFFER_SIZE + 1);
	if (!new_buffer || !node)
		return ;
	while (*data && *data != '\n')
		data++;
	if (*data == '\n')
	{
		data++;
		while (*data)
			*(new_buffer + (i++)) = *data++;
	}
	*(new_buffer + i) = '\0';
	clear_list(head, new_buffer, node);
}

char	*process_list(t_list *head)
{
	size_t	count;
	char	*line;

	count = count_line(head);
	line = my_malloc(count + 1);
	if (!line)
		return (NULL);
	copy(head, line);
	return (line);
}

void	read_file(t_list **head, int fd)
{
	char	*buffer;
	ssize_t	rd_bytes;

	while (!check_new(head))
	{
		buffer = my_malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return ;
		rd_bytes = read(fd, buffer, BUFFER_SIZE);
		if (!rd_bytes || rd_bytes < 0)
		{
			return ;
		}
		buffer[rd_bytes] = '\0';
		add_node(head, buffer);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_file(&head, fd);
	if (!head)
		return (NULL);
	line = process_list(head);
	new_head(&head);
	return (line);
}
