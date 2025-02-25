/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 18:13:58 by dclement          #+#    #+#             */
/*   Updated: 2025/01/15 15:44:17 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	identify_order(t_stacks *stacks, int num, int num2, int num3);

void	sort_three(t_stacks *stacks, int flag)
{
	t_stack_a	*head_a;
	int			num;
	int			num2;
	int			num3;

	head_a = stacks->head_a;
	num = head_a->num;
	num2 = head_a->next->num;
	num3 = head_a->next->next->num;
	identify_order(stacks, num, num2, num3);
	if (flag)
	{
		ft_clearnode_a(&stacks->head_a);
		if (stacks->one_arg != NULL)
			ft_split_free(stacks->one_arg);
		exit(0);
	}
}

void	identify_order(t_stacks *stacks, int num, int num2, int num3)
{
	if (num > num2 && num < num3)
		ft_swap(stacks, 'a');
	else if (num > num2 && num > num3 && num2 < num3)
		ft_rotate(stacks, 'a');
	else if (num < num2 && num > num3 && num2 > num3)
		ft_rev_rotate(stacks, 'a');
	else if (num > num2 && num > num3 && num2 > num3)
	{
		ft_swap(stacks, 'a');
		ft_rev_rotate(stacks, 'a');
	}
	else if (num < num2 && num < num3 && num2 > num3)
	{
		ft_swap(stacks, 'a');
		ft_rotate(stacks, 'a');
	}
}
