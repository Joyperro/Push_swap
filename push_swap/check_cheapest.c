/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cheapest.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:32:37 by dclement          #+#    #+#             */
/*   Updated: 2024/11/14 18:49:51 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_moves(t_stacks *stacks)
{
	stacks->moves->rr = 0;
	stacks->moves->rrr = 0;
	while (stacks->moves->ra != 0 && stacks->moves->rb != 0)
	{
		stacks->moves->ra--;
		stacks->moves->rb--;
		stacks->moves->rr++;
	}
	while (stacks->moves->rra != 0 && stacks->moves->rrb != 0)
	{
		stacks->moves->rra--;
		stacks->moves->rrb--;
		stacks->moves->rrr++;
	}
}

void	cost_check(t_stacks *stacks, int i)
{
	stacks->moves->cost = stacks->moves->pb + stacks->moves->ra
		+ stacks->moves->rb + stacks->moves->rr + stacks->moves->rra
		+ stacks->moves->rrb + stacks->moves->rrr;
	if (i == 1 || (stacks->cheapest->cost > stacks->moves->cost))
	{
		stacks->cheapest->cost = stacks->moves->cost;
		stacks->cheapest->ra = stacks->moves->ra;
		stacks->cheapest->rb = stacks->moves->rb;
		stacks->cheapest->rr = stacks->moves->rr;
		stacks->cheapest->pb = stacks->moves->pb;
		stacks->cheapest->rra = stacks->moves->rra;
		stacks->cheapest->rrb = stacks->moves->rrb;
		stacks->cheapest->rrr = stacks->moves->rrr;
	}
}

void	move_check(t_stacks *stacks)
{
	int			i;
	int			size;
	t_stack_a	*head_a;

	head_a = stacks->head_a;
	size = ft_lstsize_a(head_a);
	i = 0;
	while (i++ < size)
	{
		get_top_a(stacks, head_a, i - 1);
		if (head_a->num > stacks->value->max_b || head_a->num
			< stacks->value->min_b)
			new_min_max_b(stacks);
		else
			new_num_b(stacks, head_a->num);
		double_moves(stacks);
		cost_check(stacks, i);
		head_a = head_a->next;
	}
}
