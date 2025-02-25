/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:03:58 by dclement          #+#    #+#             */
/*   Updated: 2025/01/27 13:24:36 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_last_push_a(t_stacks *stacks);
void	ft_push_a(t_stacks *stacks);
void	ft_push_b(t_stacks *stacks);
void	ft_push_empty_b(t_stacks *stacks);

void	ft_push(t_stacks *stacks, char ch)
{
	t_stack_b	*head_b;

	head_b = stacks->head_b;
	if (ch == 'a')
	{
		if (head_b == NULL)
			return ;
		else if (head_b->next == NULL)
			ft_last_push_a(stacks);
		else
			ft_push_a(stacks);
	}
	else if (ch == 'b')
	{
		if (head_b == NULL)
			ft_push_empty_b(stacks);
		else
			ft_push_b(stacks);
	}
}

void	ft_last_push_a(t_stacks *stacks)
{
	t_stack_a	*tmp;

	tmp = stacks->head_a;
	stacks->head_a = (t_stack_a *)stacks->head_b;
	stacks->head_a->next = tmp;
	stacks->head_b = NULL;
	ft_printf("pa\n");
}

void	ft_push_a(t_stacks *stacks)
{
	t_stack_a	*tmp;

	tmp = stacks->head_a;
	stacks->head_a = (t_stack_a *)stacks->head_b;
	stacks->head_b = stacks->head_b->next;
	stacks->head_a->next = tmp;
	ft_printf("pa\n");
}

void	ft_push_b(t_stacks *stacks)
{
	t_stack_b	*tmp;

	tmp = stacks->head_b;
	stacks->head_b = (t_stack_b *)stacks->head_a;
	stacks->head_a = stacks->head_a->next;
	stacks->head_b->next = tmp;
	ft_printf("pb\n");
}

void	ft_push_empty_b(t_stacks *stacks)
{
	stacks->head_b = (t_stack_b *)stacks->head_a;
	stacks->head_a = stacks->head_a->next;
	stacks->head_b->next = NULL;
	ft_printf("pb\n");
}
