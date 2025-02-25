/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_min_max_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:23:56 by dclement          #+#    #+#             */
/*   Updated: 2024/11/14 18:47:28 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_min_a(t_stacks *stacks);
void	move_max_a(t_stacks *stacks);

void	new_min_a(t_stacks *stacks)
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
	move_min_a(stacks);
}

void	new_max_a(t_stacks *stacks)
{
	int	i;
	int	size;

	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	if (ft_lstlast_a(stacks->head_a)->num != stacks->value->max_a)
	{
		i = find_index_a(stacks, stacks->value->max_a);
		size = ft_lstsize_a(stacks->head_a);
		if (size % 2 == 0)
		{
			if (i + 1 > size / 2)
				stacks->moves->rra = (size - i) - 1;
			else
				stacks->moves->ra = i + 1;
		}
		else
		{
			if (i > size / 2)
				stacks->moves->rra = (size - i) - 1;
			else
				stacks->moves->ra = i + 1;
		}
	}
	move_max_a(stacks);
}

void	move_min_a(t_stacks *stacks)
{
	while (stacks->moves->ra-- != 0)
		ft_rotate(stacks, 'a');
	while (stacks->moves->rra-- != 0)
		ft_rev_rotate(stacks, 'a');
	ft_push(stacks, 'a');
}

void	move_max_a(t_stacks *stacks)
{
	while (stacks->moves->ra-- != 0)
		ft_rotate(stacks, 'a');
	while (stacks->moves->rra-- != 0)
		ft_rev_rotate(stacks, 'a');
	ft_push(stacks, 'a');
	ft_rotate(stacks, 'a');
}
