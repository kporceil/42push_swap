/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:37:37 by kporceil          #+#    #+#             */
/*   Updated: 2025/01/07 19:24:12 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"
#include "parsing.h"
#include "libft/includes/libft.h"

int	check_args(int argc, char **argv)
{
	int		i;
	size_t	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
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

int	parse_args(int argc, char **argv, t_stack **stacks)
{
	size_t	i;
	int		error;

	*stacks = init_stack(argc - 1);
	if (!(*stacks))
		return (-1);
	i = 1;
	while (i < argc)
	{
		(*stacks)->stack_a[i] = ft_atoi(argv[i], &error);
		if (error != 0)
			return (free_stack(stacks));
		++i;
	}
	return (0);
}
