/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:13:50 by dclement          #+#    #+#             */
/*   Updated: 2025/01/27 13:22:32 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotate_a(t_stacks *stacks, t_stack_a *head_a, int print);
void	ft_rev_rotate_b(t_stacks *stacks, t_stack_b *head_b, int print);

void	ft_rev_rotate(t_stacks *stacks, char ch)
{
	t_stack_a	*head_a;
	t_stack_b	*head_b;

	head_a = stacks->head_a;
	head_b = stacks->head_b;
	if (ch == 'a')
		ft_rev_rotate_a(stacks, stacks->head_a, 1);
	else if (ch == 'b')
	{
		if (head_b == NULL || head_b->next == NULL)
			return ;
		ft_rev_rotate_b(stacks, head_b, 1);
	}
	else
	{
		if (head_a == NULL || head_a->next == NULL
			|| head_b == NULL || head_b->next == NULL)
			return ;
		ft_rev_rotate_a(stacks, stacks->head_a, 0);
		ft_rev_rotate_b(stacks, head_b, 0);
		ft_printf("rrr\n");
	}
}

void	ft_rev_rotate_a(t_stacks *stacks, t_stack_a *head_a, int print)
{
	t_stack_a	*tmp;
	int			size;
	int			i;

	tmp = head_a;
	size = ft_lstsize_a(head_a);
	while (head_a->next != NULL)
		head_a = head_a->next;
	head_a->next = tmp;
	stacks->head_a = head_a;
	tmp = stacks->head_a;
	i = 0;
	while (i++ < size - 1)
		tmp = tmp->next;
	tmp->next = NULL;
	if (print != 0)
		ft_printf("rra\n");
}

void	ft_rev_rotate_b(t_stacks *stacks, t_stack_b *head_b, int print)
{
	t_stack_b	*tmp;
	int			size;
	int			i;

	tmp = head_b;
	size = ft_lstsize_b(head_b);
	while (head_b->next != NULL)
		head_b = head_b->next;
	head_b->next = tmp;
	stacks->head_b = head_b;
	tmp = stacks->head_b;
	i = 0;
	while (i++ < size - 1)
		tmp = tmp->next;
	tmp->next = NULL;
	if (print != 0)
		ft_printf("rrb\n");
}
