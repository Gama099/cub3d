/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hadd <sel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:15:43 by sel-hadd          #+#    #+#             */
/*   Updated: 2025/02/28 16:05:34 by sel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	*my_malloc(size_t size)
{
	void			*ptr;
	t_memoryblock	*block;

	ptr = malloc(size);
	if (ptr == NULL)
		handle_error(ERR_MEMORY_ALLOCATION);
	block = (t_memoryblock *)malloc(sizeof(t_memoryblock));
	if (block == NULL)
		handle_error(ERR_MEMORY_ALLOCATION);
	block->ptr = ptr;
	block->size = size;
	block->next = ghead;
	ghead = block;
	return (ptr);
}

void	cleanup(void)
{
	t_memoryblock	*tmp2;
	t_memoryblock	*tmp;

	tmp = ghead;
	while (tmp != NULL)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2->ptr);
		tmp2->ptr = NULL;
		free(tmp2);
		tmp2 = NULL;
	}
	tmp = NULL;
	ghead = NULL;
}
