/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_mov_ab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:57:30 by kporceil          #+#    #+#             */
/*   Updated: 2025/01/10 14:00:27 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "swap_mov.h"

void	rr(t_stack *stacks)
{
	ra(stacks);
	rb(stacks);
}

void	rrr(t_stack *stacks)
{
	rra(stacks);
	rrb(stacks);
}

void	ss(t_stack *stacks)
{
	sa(stacks);
	sb(stacks);
}
