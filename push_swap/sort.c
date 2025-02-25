/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:21:36 by dclement          #+#    #+#             */
/*   Updated: 2024/11/26 16:51:32 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(t_stacks *stacks)
{
	t_stack_a	*head_a;
	int			i;
	int			num;

	head_a = stacks->head_a;
	num = head_a->num;
	i = 1;
	while (i < ft_lstsize_a(stacks->head_a))
	{
		head_a = head_a->next;
		if (num > head_a->num)
			return (0);
		num = head_a->num;
		i++;
	}
	ft_clearnode_a(&stacks->head_a);
	exit(0);
}

void	sorting(t_stacks *stacks)
{
	if (check_order(stacks))
		return ;
	else if (ft_lstsize_a(stacks->head_a) == 2)
		sort_two(stacks);
	else if (ft_lstsize_a(stacks->head_a) == 3)
		sort_three(stacks, 1);
	else if (ft_lstsize_a(stacks->head_a) == 4)
	{
		sort_four(stacks);
		free_all(stacks);
		exit(0);
	}
	else if (ft_lstsize_a(stacks->head_a) == 5)
		sort_five(stacks);
	else
	{
		ft_push(stacks, 'b');
		ft_push(stacks, 'b');
		move_cheapest(stacks);
		sort_three(stacks, 0);
		move_back(stacks);
		if (!check_order(stacks))
			sorting(stacks);
	}
}
