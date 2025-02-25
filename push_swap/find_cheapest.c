/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:43:27 by dclement          #+#    #+#             */
/*   Updated: 2024/11/21 16:48:53 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_cheapest_moves(t_stacks *stacks)
{
	while (stacks->cheapest->ra-- != 0)
		ft_rotate(stacks, 'a');
	while (stacks->cheapest->rb-- != 0)
		ft_rotate(stacks, 'b');
	while (stacks->cheapest->rr-- != 0)
		ft_rotate(stacks, 'r');
	while (stacks->cheapest->rra-- != 0)
		ft_rev_rotate(stacks, 'a');
	while (stacks->cheapest->rrb-- != 0)
		ft_rev_rotate(stacks, 'b');
	while (stacks->cheapest->rrr-- != 0)
		ft_rev_rotate(stacks, 'r');
	while (stacks->cheapest->pb-- != 0)
		ft_push(stacks, 'b');
}

void	move_cheapest(t_stacks *stacks)
{
	struct t_moves		*moves;
	struct t_cheapest	*cheapest;
	t_values			*value;

	moves = ft_calloc(1, sizeof(t_moves));
	stacks->moves = moves;
	cheapest = ft_calloc(1, sizeof(t_cheapest));
	stacks->cheapest = cheapest;
	value = ft_calloc(1, sizeof(t_values));
	stacks->value = value;
	while (ft_lstsize_a(stacks->head_a) != 3)
	{
		check_min_max_b(stacks);
		move_check(stacks);
		do_cheapest_moves(stacks);
	}
}
