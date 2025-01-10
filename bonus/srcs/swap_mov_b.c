/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_mov_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:04:54 by kporceil          #+#    #+#             */
/*   Updated: 2025/01/10 14:00:47 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "swap_mov.h"

void	rb(t_stack *stacks)
{
	int		tmp;
	size_t	i;

	if (stacks->b_size < 2)
		return ;
	tmp = (stacks->stack_b)[0];
	i = 1;
	while (i < stacks->b_size)
	{
		(stacks->stack_b)[i - 1] = (stacks->stack_b)[i];
		++i;
	}
	(stacks->stack_b)[stacks->b_size - 1] = tmp;
}

void	rrb(t_stack *stacks)
{
	ssize_t	i;
	int		tmp;

	if (stacks->b_size < 2)
		return ;
	i = stacks->b_size - 2;
	tmp = (stacks->stack_b)[stacks->b_size - 1];
	while (i >= 0)
	{
		(stacks->stack_b)[i + 1] = (stacks->stack_b)[i];
		--i;
	}
	(stacks->stack_b)[0] = tmp;
}

void	pb(t_stack *stacks)
{
	ssize_t	i;
	size_t	j;

	if (stacks->a_size < 1)
		return ;
	++(stacks->b_size);
	i = stacks->b_size - 2;
	while (i >= 0)
	{
		(stacks->stack_b)[i + 1] = (stacks->stack_b)[i];
		--i;
	}
	(stacks->stack_b)[0] = (stacks->stack_a)[0];
	j = 1;
	while (j < stacks->a_size)
	{
		(stacks->stack_a)[j - 1] = (stacks->stack_a)[j];
		++j;
	}
	--(stacks->a_size);
}

void	sb(t_stack	*stacks)
{
	int	tmp;

	if (stacks->b_size > 1)
	{
		tmp = stacks->stack_b[0];
		stacks->stack_b[0] = stacks->stack_b[1];
		stacks->stack_b[1] = tmp;
	}
}
