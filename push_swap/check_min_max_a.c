/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_min_max_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:56:20 by dclement          #+#    #+#             */
/*   Updated: 2024/10/25 15:57:33 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_max_a(t_stacks *stacks, t_stack_a *head_a)
{
	int	i;
	int	size;

	size = ft_lstsize_a(head_a);
	i = 0;
	stacks->value->max_a = head_a->num;
	while (i < size)
	{
		if (stacks->value->max_a < head_a->num)
			stacks->value->max_a = head_a->num;
		head_a = head_a->next;
		i++;
	}
}

void	check_min_a(t_stacks *stacks, t_stack_a *head_a)
{
	int	i;
	int	size;

	size = ft_lstsize_a(head_a);
	i = 0;
	stacks->value->min_a = head_a->num;
	while (i < size)
	{
		if (stacks->value->min_a > head_a->num)
			stacks->value->min_a = head_a->num;
		head_a = head_a->next;
		i++;
	}
}

void	check_min_max_a(t_stacks *stacks)
{
	check_max_a(stacks, stacks->head_a);
	check_min_a(stacks, stacks->head_a);
}
