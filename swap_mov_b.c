/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_mov_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:04:54 by kporceil          #+#    #+#             */
/*   Updated: 2025/01/09 19:05:20 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "sort.h"

void	rb(t_stack *stacks)
{
	int		tmp;
	size_t	i;

	tmp = (stacks->stack_b)[0];
	i = 1;
	while (i < stacks->b_size)
	{
		(stacks->stack_b)[i - 1] = (stacks->stack_b)[i];
		++i;
	}
	(stacks->stack_b)[stacks->b_size - 1] = tmp;
	ft_putstr_fd("rb\n", 1);
}

void	rrb(t_stack *stacks)
{
	ssize_t	i;
	int		tmp;

	i = stacks->b_size - 2;
	tmp = (stacks->stack_b)[stacks->b_size - 1];
	while (i >= 0)
	{
		(stacks->stack_b)[i + 1] = (stacks->stack_b)[i];
		--i;
	}
	(stacks->stack_b)[0] = tmp;
	ft_putstr_fd("rrb\n", 1);
}

void	pb(t_stack *stacks)
{
	ssize_t	i;
	size_t	j;

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
	ft_putstr_fd("pb\n", 1);
}
