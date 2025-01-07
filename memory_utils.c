/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:15:18 by kporceil          #+#    #+#             */
/*   Updated: 2025/01/07 19:23:56 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"
#include <stdlib.h>

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
	stacks->stack_b = malloc(sizeof(int) * size);
	if (!(stacks->stack_b))
	{
		free(stacks);
		free(stacks->stack_a);
		return (NULL);
	}
	return (stacks);
}

int	free_stack(t_stack **stacks)
{
	free((*stacks)->stack_a);
	free((*stacks)->stack_b);
	free(*stacks);
	*stacks = NULL;
	return (-1);
}
