/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:49:00 by kporceil          #+#    #+#             */
/*   Updated: 2025/01/08 15:30:21 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "indexer.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>

static int	*dup_tab(int *tab, size_t size)
{
	int	*dup;

	dup = malloc(sizeof(int) * size);
	if (!dup)
		return (NULL);
	ft_memmove(dup, tab, size * sizeof(int));
	return (dup);
}

static void	sort_int_tab(int *tab, size_t size)
{
	size_t	i;

	i = 1;
	while (i < size)
	{
		if (tab[i] < tab[i - 1])
		{
			tab[i] ^= tab[i - 1];
			tab[i - 1] ^= tab[i];
			tab[i] ^= tab[i - 1];
			i = 0;
		}
		++i;
	}
}

static void	index_tab(int *sorted, int *to_index, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (to_index[j] == sorted[i])
				to_index[j] = (int)i;
			++j;
		}
		++i;
	}
}

int	stack_indexer(int *stack, size_t stack_size)
{
	int	*dup_stack;

	dup_stack = dup_tab(stack, stack_size);
	if (!dup_stack)
		return (-1);
	sort_int_tab(dup_stack, stack_size);
	index_tab(dup_stack, stack, stack_size);
	free(dup_stack);
	return (0);
}
