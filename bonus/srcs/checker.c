/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:14:40 by kporceil          #+#    #+#             */
/*   Updated: 2025/01/10 14:04:31 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "swap_mov.h"
#include "../../libft/includes/libft.h"
#include "get_next_line.h"

static int	cmp_instruct(t_stack *stacks, char *line)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		sa(stacks);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		sb(stacks);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ss(stacks);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		ra(stacks);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rb(stacks);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rr(stacks);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		rra(stacks);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrb(stacks);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr(stacks);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		pa(stacks);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		pb(stacks);
	else
		return (-1);
	return (0);
}

int	exec_instructions(t_stack *stacks)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		if (cmp_instruct(stacks, line) != 0)
		{
			free(line);
			return (-1);
		}
		free(line);
		line = get_next_line(0);
	}
	return (0);
}

int	is_sorted(t_stack *stacks)
{
	size_t	i;

	if (stacks->b_size != 0)
		return (-1);
	i = 1;
	while (i < stacks->a_size)
	{
		if (stacks->stack_a[i - 1] > stacks->stack_a[i])
			return (-2);
		++i;
	}
	return (0);
}
