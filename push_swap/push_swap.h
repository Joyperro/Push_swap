/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:53:45 by dclement          #+#    #+#             */
/*   Updated: 2025/01/27 12:53:44 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INTMAX 2147483647
# define INTMIN -2147483648

# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"

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
	struct t_cheapest	*cheapest;
	char				**one_arg;
}						t_stacks;

typedef struct s_pos
{
	int	value;
	int	position;
}		t_pos;

typedef struct t_moves
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

typedef struct t_cheapest
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
}						t_cheapest;

typedef struct t_values
{
	int					max_a;
	int					min_a;
	int					max_b;
	int					min_b;
}						t_values;

void		check_double(t_stack_a *head_a, t_stacks *stacks);
void		error_check(int argc, char **argv, t_stacks *stacks);
void		sorting(t_stacks *stacks);
void		move_check(t_stacks *stacks);
t_stack_a	*create_list_a(int num, char **str, int flag);
int			ft_lstsize_a(t_stack_a *head_a);
void		new_min_max_b(t_stacks *stacks);
void		new_num_b(t_stacks *stacks, int num);
void		check_min_max_b(t_stacks *stacks);
void		ft_push(t_stacks *stacks, char ch);
void		ft_rev_rotate(t_stacks *stacks, char ch);
void		ft_rotate(t_stacks *stacks, char ch);
void		sort_five(t_stacks *stacks);
void		sort_four(t_stacks *stacks);
void		sort_three(t_stacks *stacks, int flag);
void		sort_two(t_stacks *stacks);
void		sorting(t_stacks *stacks);
void		ft_swap(t_stacks *stacks, char ch);
int			ft_lstsize_b(t_stack_b *head_b);
t_stack_b	*create_list_b(int argc, char **argv);
t_stack_b	*ft_newnode_b(int content);
t_stack_b	*ft_lstlast_b(t_stack_b *head_b);
void		move_cheapest(t_stacks *stacks);
t_stack_a	*ft_lstlast_a(t_stack_a *head_a);
int			find_index_a(t_stacks *stacks, int nbr);
void		ft_clearnode_a(t_stack_a **lst);
int			search_stack_a(t_stacks *stacks, int num);
void		move_elem_to_a(t_stacks *stacks);
void		get_top_a(t_stacks *stacks, t_stack_a *head_a, int i);
int			find_index_b(t_stacks *stacks, int nbr);
int			search_stack_b(t_stacks *stacks, int nbr);
void		move_back(t_stacks *stacks);
void		check_min_max_a(t_stacks *stacks);
void		new_in_a(t_stacks *stacks, t_stack_b *head_b);
void		new_max_a(t_stacks *stacks);
void		new_min_a(t_stacks *stacks);
void		free_all(t_stacks *stacks);
void		ft_clearnode_b(t_stack_b **lst);
int			check_order(t_stacks *stacks);
int			ft_split_count(char **str);
int			is_flag(int flag);
void		ft_split_free(char **split);

#endif
