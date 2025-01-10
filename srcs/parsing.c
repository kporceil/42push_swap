/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:37:37 by kporceil          #+#    #+#             */
/*   Updated: 2025/01/08 12:49:47 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"
#include "parsing.h"
#include "../libft/includes/libft.h"

int	check_args(int argc, char **argv)
{
	int		i;
	size_t	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
			++j;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (-1);
			++j;
		}
		++i;
	}
	return (0);
}

static int	check_duplicates_value(t_stack *stack)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < stack->a_size)
	{
		j = 0;
		while (j < stack->a_size)
		{
			if (j != i && stack->stack_a[i] == stack->stack_a[j])
				return (-1);
			++j;
		}
		++i;
	}
	return (0);
}

int	parse_args(int argc, char **argv, t_stack **stacks)
{
	int	i;

	*stacks = init_stack(argc - 1);
	if (!(*stacks))
		return (-1);
	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i], (*stacks)->stack_a + (i - 1)) != 0)
			return (free_stack(stacks, -2));
		++((*stacks)->a_size);
		++i;
	}
	if (check_duplicates_value(*stacks) != 0)
		return (free_stack(stacks, -3));
	return (0);
}
