/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:17:56 by kporceil          #+#    #+#             */
/*   Updated: 2025/01/07 19:24:34 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

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

t_stack		*init_stack(int size);
int			free_stack(t_stack **stacks, int ret_value);

#endif
