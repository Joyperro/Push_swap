/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:37:09 by dclement          #+#    #+#             */
/*   Updated: 2025/01/27 13:23:59 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_stack_a *head_a, int print);
void	ft_swap_b(t_stack_b *head_b, int print);

void	ft_swap(t_stacks *stacks, char ch)
{
	t_stack_a	*head_a;
	t_stack_b	*head_b;

	head_a = stacks->head_a;
	head_b = stacks->head_b;
	if (ch == 'a')
		ft_swap_a(head_a, 1);
	else if (ch == 'b')
	{
		if (head_b == NULL || head_b->next == NULL)
			return ;
		ft_swap_b(head_b, 1);
	}
	else
	{
		if (head_a == NULL || head_a->next == NULL
			|| head_b == NULL || head_b->next == NULL)
			return ;
		ft_swap_a(head_a, 0);
		ft_swap_b(head_b, 0);
		ft_printf("ss\n");
	}
}

void	ft_swap_a(t_stack_a *head_a, int print)
{
	int	tmp;

	tmp = head_a->num;
	head_a->num = head_a->next->num;
	head_a->next->num = tmp;
	if (print != 0)
		ft_printf("sa\n");
}

void	ft_swap_b(t_stack_b *head_b, int print)
{
	int	tmp;

	tmp = head_b->num;
	head_b->num = head_b->next->num;
	head_b->next->num = tmp;
	if (print != 0)
		ft_printf("sb\n");
}
