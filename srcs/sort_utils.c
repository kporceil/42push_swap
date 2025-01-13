/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:52:28 by kporceil          #+#    #+#             */
/*   Updated: 2025/01/09 19:09:54 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

t_side	closer_highest_value(t_stack *stacks)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < stacks->b_size && (stacks->stack_b)[i] != (int)(stacks->b_size
			- 1))
		++i;
	j = stacks->b_size - 1;
	while ((stacks->stack_b)[j] != (int)(stacks->b_size - 1))
		--j;
	if (i < stacks->b_size - j - 1)
		return (TOP);
	return (BOT);
}

int	is_max(int value, int max)
{
	if (value <= max - 1 && value >= max - 3)
		return (0);
	return (1);
}

size_t	calc_chunk(size_t value)
{
	if (value < 20)
		return (1);
	return (0.000000053 * value * value + 0.03 * value + 14.5);
}
