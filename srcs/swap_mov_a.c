/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_mov_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:31:40 by kporceil          #+#    #+#             */
/*   Updated: 2025/01/09 19:05:36 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "sort.h"

void	ra(t_stack *stacks)
{
	int		tmp;
	size_t	i;

	tmp = (stacks->stack_a)[0];
	i = 1;
	while (i < stacks->a_size)
	{
		(stacks->stack_a)[i - 1] = (stacks->stack_a)[i];
		++i;
	}
	(stacks->stack_a)[stacks->a_size - 1] = tmp;
	ft_putstr_fd("ra\n", 1);
}

void	rra(t_stack *stacks)
{
	ssize_t	i;
	int		tmp;

	i = stacks->a_size - 2;
	tmp = (stacks->stack_a)[stacks->a_size - 1];
	while (i >= 0)
	{
		(stacks->stack_a)[i + 1] = (stacks->stack_a)[i];
		--i;
	}
	(stacks->stack_a)[0] = tmp;
	ft_putstr_fd("rra\n", 1);
}

void	pa(t_stack *stacks)
{
	ssize_t	i;
	size_t	j;

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
	ft_putstr_fd("pa\n", 1);
}

void	sa(t_stack	*stacks)
{
	int	tmp;

	if (stacks->a_size > 1)
	{
		tmp = stacks->stack_a[0];
		stacks->stack_a[0] = stacks->stack_a[1];
		stacks->stack_a[1] = tmp;
		ft_putstr_fd("sa\n", 1);
	}
}
