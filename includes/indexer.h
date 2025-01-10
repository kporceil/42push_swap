/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:46:57 by kporceil          #+#    #+#             */
/*   Updated: 2025/01/08 14:48:30 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INDEXER_H
# define INDEXER_H

# include <sys/types.h>

# ifndef T_STACK
#  define T_STACK

typedef struct s_stack
{
	int		*stack_a;
	int		*stack_b;
	size_t	a_size;
	size_t	b_size;
}			t_stack;

# endif

void	index_stack(t_stack *stacks);

#endif
