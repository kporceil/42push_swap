/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:37:57 by kporceil          #+#    #+#             */
/*   Updated: 2025/01/09 14:35:37 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "indexer.h"
#include "memory.h"
#include "parsing.h"
#include "sort.h"

int	push_swap(int argc, char **argv)
{
	t_stack	*stacks;

	if (argc < 2)
		return (-1);
	if (check_args(argc, argv) != 0)
		return (-2);
	if (parse_args(argc, argv, &stacks) != 0)
		return (-3);
	if (stack_indexer(stacks->stack_a, stacks->a_size) != 0)
		return (free_stack(&stacks, -4));
	sort_stack(stacks);
	return (free_stack(&stacks, 0));
}

int	main(int argc, char **argv)
{
	int	res;

	res = push_swap(argc, argv);
	if (res < 0)
	{
		if (res != -1)
			ft_putstr_fd("Error\n", 1);
		return (res);
	}
	return (0);
}
