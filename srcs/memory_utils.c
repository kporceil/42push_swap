/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:15:18 by kporceil          #+#    #+#             */
/*   Updated: 2025/01/08 12:10:05 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"
#include <stdlib.h>
#include "../libft/includes/libft.h"

t_stack	*init_stack(int size)
{
	t_stack	*stacks;

	stacks = malloc(sizeof(t_stack));
	if (!stacks)
		return (NULL);
	stacks->stack_a = malloc(sizeof(int) * size);
	if (!(stacks->stack_a))
	{
		free(stacks);
		return (NULL);
	}
	stacks->a_size = 0;
	stacks->stack_b = ft_calloc(sizeof(int), size);
	if (!(stacks->stack_b))
	{
		free(stacks->stack_a);
		free(stacks);
		return (NULL);
	}
	stacks->b_size = 0;
	return (stacks);
}

int	free_stack(t_stack **stacks, int ret_value)
{
	free((*stacks)->stack_a);
	free((*stacks)->stack_b);
	free(*stacks);
	*stacks = NULL;
	return (ret_value);
}
