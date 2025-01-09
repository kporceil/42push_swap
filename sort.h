/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:28:27 by kporceil          #+#    #+#             */
/*   Updated: 2025/01/09 19:10:02 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

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

# ifndef T_SIDE
#  define T_SIDE

typedef enum e_side
{
	TOP,
	BOT,
}			t_side;

# endif

void		pa(t_stack *stacks);
void		rb(t_stack *stacks);
void		pb(t_stack *stacks);
void		rrb(t_stack *stacks);
void		ra(t_stack *stacks);
void		rra(t_stack *stacks);
t_side		closer_highest_value(t_stack *stacks);
void		sort_stack(t_stack *stacks);

#endif
