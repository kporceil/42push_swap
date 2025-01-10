/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_mov_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:31:40 by kporceil          #+#    #+#             */
/*   Updated: 2025/01/10 14:01:00 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "swap_mov.h"

void	ra(t_stack *stacks)
{
	int		tmp;
	size_t	i;

	if (stacks->a_size < 2)
		return ;
	tmp = (stacks->stack_a)[0];
	i = 1;
	while (i < stacks->a_size)
	{
		(stacks->stack_a)[i - 1] = (stacks->stack_a)[i];
		++i;
	}
	(stacks->stack_a)[stacks->a_size - 1] = tmp;
}

void	rra(t_stack *stacks)
{
	ssize_t	i;
	int		tmp;

	if (stacks->a_size < 2)
		return ;
	i = stacks->a_size - 2;
	tmp = (stacks->stack_a)[stacks->a_size - 1];
	while (i >= 0)
	{
		(stacks->stack_a)[i + 1] = (stacks->stack_a)[i];
		--i;
	}
	(stacks->stack_a)[0] = tmp;
}

void	pa(t_stack *stacks)
{
	ssize_t	i;
	size_t	j;

	if (stacks->b_size < 1)
		return ;
	++(stacks->a_size);
	i = stacks->a_size - 2;
	while (i >= 0)
	{
		(stacks->stack_a)[i + 1] = (stacks->stack_a)[i];
		--i;
	}
	(stacks->stack_a)[0] = (stacks->stack_b)[0];
	j = 1;
	while (j < stacks->b_size)
	{
		(stacks->stack_b)[j - 1] = (stacks->stack_b)[j];
		++j;
	}
	--(stacks->b_size);
}

void	sa(t_stack	*stacks)
{
	int	tmp;

	if (stacks->a_size > 1)
	{
		tmp = stacks->stack_a[0];
		stacks->stack_a[0] = stacks->stack_a[1];
		stacks->stack_a[1] = tmp;
	}
}
