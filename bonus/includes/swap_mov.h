/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_mov.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:28:27 by kporceil          #+#    #+#             */
/*   Updated: 2025/01/10 14:01:35 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_MOV_H
# define SWAP_MOV_H

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

void		sa(t_stack	*stacks);
void		sb(t_stack	*stacks);
void		pa(t_stack *stacks);
void		rb(t_stack *stacks);
void		pb(t_stack *stacks);
void		rrb(t_stack *stacks);
void		ra(t_stack *stacks);
void		rra(t_stack *stacks);
void		rr(t_stack *stacks);
void		rrr(t_stack *stacks);
void		ss(t_stack *stacks);
int			exec_instructions(t_stack *stacks);
int			is_sorted(t_stack *stacks);

#endif
