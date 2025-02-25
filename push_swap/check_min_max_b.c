/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_min_max_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:04:20 by dclement          #+#    #+#             */
/*   Updated: 2024/10/25 15:57:46 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_max_b(t_stacks *stacks, t_stack_b *head_b)
{
	int	i;
	int	size;

	size = ft_lstsize_b (head_b);
	i = 0;
	while (i < size)
	{
		if (stacks->value->max_b < head_b->num)
			stacks->value->max_b = head_b->num;
		head_b = head_b->next;
		i++;
	}
}

void	check_min_b(t_stacks *stacks, t_stack_b *head_b)
{
	int	i;
	int	size;

	size = ft_lstsize_b(head_b);
	i = 0;
	stacks->value->min_b = head_b->num;
	while (i < size)
	{
		if (stacks->value->min_b > head_b->num)
			stacks->value->min_b = head_b->num;
		head_b = head_b->next;
		i++;
	}
}

void	check_min_max_b(t_stacks *stacks)
{
	if (stacks->head_b != NULL)
	{
		check_max_b(stacks, stacks->head_b);
		check_min_b(stacks, stacks->head_b);
	}
}
