/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:53:45 by dclement          #+#    #+#             */
/*   Updated: 2024/05/13 17:25:11 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INTMAX 2147483647
# define INTMIN -2147483648

# include <stdlib.h>

typedef struct t_stack_a
{
	int					num;
	struct t_stack_a	*next;
}						t_stack_a;

typedef struct t_stack_b
{
	int					num;
	struct t_stack_b	*next;
}						t_stack_b;

typedef struct s_stacks
{
	struct t_stack_a	*head_a;
	struct t_stack_b	*head_b;
	struct t_moves		*moves;
	struct t_values		*value;
}						t_stacks;

typedef struct s_moves
{
	int					cost;
	int					sa;
	int					sb;
	int					ss;
	int					pa;
	int					pb;
	int					ra;
	int					rb;
	int					rr;
	int					rra;
	int					rrb;
	int					rrr;
}						t_moves;

typedef struct s_values
{
	int					max_a;
	int					min_a;
	int					max_b;
	int					min_b;
}						t_values;

void					check_double(t_stack_a *head_a);
void					error_check(int argc, char **argv);

#endif
