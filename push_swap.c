/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:37:57 by kporceil          #+#    #+#             */
/*   Updated: 2025/01/07 11:50:57 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	push_swap(int argc, char **argv)
{
	t_stack	*stacks;

	if (argc < 2)
		return (-1);
	if (check_args(argc, argv) != 0)
		return (-2);
	if (parse_args(argc, argv, &stacks) != 0)
		return (-3);
}
