/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:22:29 by dclement          #+#    #+#             */
/*   Updated: 2024/11/21 17:19:39 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min(t_stacks *stacks, t_pos *min)
{
	t_stack_a	*current;
	int			i;

	i = 0;
	min->value = INTMAX;
	min->position = -1;
	current = stacks->head_a;
	while (current)
	{
		if (current->num < min->value)
		{
			min->value = current->num;
			min->position = i;
		}
		current = current->next;
		i++;
	}
}

void	move_to_stack_b(t_stacks *stacks, t_pos *min)
{
	t_stack_a	*head_a;

	head_a = stacks->head_a;
	if (min->position <= 2)
	{
		while (head_a->num != min->value && min->position > 0)
		{
			ft_rotate(stacks, 'a');
			min->position--;
			head_a = stacks->head_a;
		}
	}
	else
	{
		while (head_a->num != min->value && min->position < 5)
		{
			ft_rev_rotate(stacks, 'a');
			min->position++;
			head_a = stacks->head_a;
		}
	}
	if (check_order(stacks))
		return ;
	ft_push(stacks, 'b');
}

void	move_min_to_b(t_stacks *stacks)
{
	t_pos	min;

	find_min(stacks, &min);
	move_to_stack_b(stacks, &min);
}

void	sort_five(t_stacks *stacks)
{
	move_min_to_b(stacks);
	sort_four(stacks);
	ft_push(stacks, 'a');
	free_all(stacks);
	exit(0);
}
