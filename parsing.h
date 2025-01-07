/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:58:30 by kporceil          #+#    #+#             */
/*   Updated: 2025/01/07 16:02:53 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H 

# include <sys/types.h>

# ifndef T_STACK
#  define T_STACK

typedef struct	s_stack
{
	int	*stack_a;
	int	*stack_b;
	size_t	a_size;
	size_t	b_size;
}				t_stack;

# endif

int	check_args(int argc, char **argv);
int	parse_args(int argc, char **argv, t_stack **stacks);

#endif
