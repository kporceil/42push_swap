/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:29:58 by kporceil          #+#    #+#             */
/*   Updated: 2025/01/09 16:49:06 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include <signal.h>
#include <unistd.h>

static size_t	calc_chunk(size_t value)
{
	if (value < 20)
		return (1);
	return (0.000000053 * value * value + 0.03 * value + 14.5);
}

static void	sort_a_to_b(t_stack *stacks, size_t chunck_size)
{
	size_t	i;

	i = 0;
	while (stacks->a_size > 0)
	{
		if (stacks->stack_a[0] <= (int)i)
		{
			pb(stacks);
			++i;
		}
		else if ((int)i < stacks->stack_a[0] && stacks->stack_a[0] <= (int)(i
			+ chunck_size))
		{
			pb(stacks);
			rb(stacks);
			++i;
		}
		else
			ra(stacks);
	}
}

static void	sort_b_to_a(t_stack *stacks)
{
	while (stacks->b_size > 0)
	{
		if (closer_highest_value(stacks) == TOP)
			while (stacks->stack_b[0] != (int)(stacks->b_size - 1))
				rb(stacks);
		else
			while (stacks->stack_b[0] != (int)(stacks->b_size - 1))
				rrb(stacks);
		pa(stacks);
	}
}

static int	is_sorted(t_stack *stacks)
{
	size_t	i;

	if (stacks->a_size < 2)
		return (-1);
	i = 1;
	while (i < stacks->a_size)
	{
		if (stacks->stack_a[i - 1] > stacks->stack_a[i])
			return (0);
		++i;
	}
	return (-1);
}

void	sort_stack(t_stack *stacks)
{
	size_t	chunck_size;

	if (is_sorted(stacks) != 0)
		return ;
	chunck_size = calc_chunk(stacks->a_size);
	sort_a_to_b(stacks, chunck_size);
	sort_b_to_a(stacks);
}
