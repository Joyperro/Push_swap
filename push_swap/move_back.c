/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:48:38 by dclement          #+#    #+#             */
/*   Updated: 2024/11/14 18:47:36 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_in_order(t_stacks *stacks);
void	do_back_moves(t_stacks *stacks);

void	move_back(t_stacks *stacks)
{
	while (stacks->head_b != NULL)
	{
		check_min_max_a(stacks);
		if (stacks->head_b->num < stacks->value->min_a)
			new_min_a(stacks);
		else if (stacks->head_b->num > stacks->value->max_a)
			new_max_a(stacks);
		else
			new_in_a(stacks, stacks->head_b);
	}
	check_min_max_a(stacks);
	put_in_order(stacks);
}

void	put_in_order(t_stacks *stacks)
{
	int	i;
	int	size;

	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	if (stacks->head_a->num != stacks->value->min_a)
	{
		i = find_index_a(stacks, stacks->value->min_a);
		size = ft_lstsize_a(stacks->head_a);
		if (size % 2 == 0)
		{
			if (i + 1 > size / 2)
				stacks->moves->rra = (size - i);
			else
				stacks->moves->ra = i;
		}
		else
		{
			if (i > size / 2)
				stacks->moves->rra = (size - i);
			else
				stacks->moves->ra = i;
		}
	}
	do_back_moves(stacks);
}

void	do_back_moves(t_stacks *stacks)
{
	while (stacks->moves->ra-- != 0)
		ft_rotate(stacks, 'a');
	while (stacks->moves->rra-- != 0)
		ft_rev_rotate(stacks, 'a');
}
