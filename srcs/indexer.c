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

void	index_stack(t_stack *stacks)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < stacks->a_size)
	{
		j = 0;
		while (j < stacks->a_size)
		{
			if (stacks->stack_a[j] < stacks->stack_a[i])
				++(stacks->stack_b[i]);
			++j;
		}
		++i;
	}
	i = 0;
	while (i < stacks->a_size)
	{
		stacks->stack_a[i] = stacks->stack_b[i];
		stacks->stack_b[i] = -1;
		++i;
	}
}
