/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:37:57 by kporceil          #+#    #+#             */
/*   Updated: 2025/01/10 14:03:55 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/libft.h"
#include "memory.h"
#include "parsing.h"
#include "swap_mov.h"

int	push_swap(int argc, char **argv)
{
	t_stack	*stacks;

	if (argc < 2)
		return (-1);
	if (check_args(argc, argv) != 0)
		return (-2);
	if (parse_args(argc, argv, &stacks) != 0)
		return (-3);
	if (exec_instructions(stacks) != 0)
		return (free_stack(&stacks, -4));
	if (is_sorted(stacks) != 0)
		return (free_stack(&stacks, -5));
	return (free_stack(&stacks, 0));
}

int	main(int argc, char **argv)
{
	int	res;

	res = push_swap(argc, argv);
	if (res < 0)
	{
		if (res == -5)
			ft_putstr_fd("KO\n", 1);
		else if (res != -1)
			ft_putstr_fd("Error\n", 1);
		return (res);
	}
	ft_putstr_fd("OK\n", 1);
	return (0);
}
