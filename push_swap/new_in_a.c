/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_in_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:44:20 by dclement          #+#    #+#             */
/*   Updated: 2024/11/14 18:45:54 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	new_in_a(t_stacks *stacks, t_stack_b *head_b)
{
	int	i;
	int	size;

	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	if (stacks->head_a->num != search_stack_a(stacks, head_b->num))
	{
		i = find_index_a(stacks, search_stack_a(stacks, head_b->num));
		size = ft_lstsize_a(stacks->head_a);
		if (size % 2 == 0)
		{
			if (i + 1 > size / 2)
				stacks->moves->rra = (size - i);
			else
				stacks->moves->ra = i + 1;
		}
		else
		{
			if (i > size / 2)
				stacks->moves->rra = (size - i);
			else
				stacks->moves->ra = i;
		}
	}
	move_elem_to_a(stacks);
}

int	search_stack_a(t_stacks *stacks, int nbr)
{
	t_stack_a	*head_a;
	int			size;
	int			flag;
	int			i;

	i = 0;
	flag = 0;
	head_a = stacks->head_a;
	size = ft_lstsize_a(stacks->head_a);
	while (flag == 0)
	{
		i = 0;
		nbr++;
		head_a = stacks->head_a;
		while (i++ < size)
		{
			if (head_a->num == nbr)
				flag = 1;
			head_a = head_a->next;
		}
	}
	return (nbr);
}

void	move_elem_to_a(t_stacks *stacks)
{
	while (stacks->moves->ra-- != 0)
		ft_rotate(stacks, 'a');
	while (stacks->moves->rra-- != 0)
		ft_rev_rotate(stacks, 'a');
	ft_push(stacks, 'a');
}

void	get_top_a(t_stacks *stacks, t_stack_a *head_a, int i)
{
	int	size;

	stacks->moves->pb = 1;
	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	if (stacks->head_a->num == head_a->num)
		return ;
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

int	find_index_a(t_stacks *stacks, int nbr)
{
	t_stack_a	*head_a;
	int			i;

	head_a = stacks->head_a;
	i = 0;
	while (head_a != NULL)
	{
		if (head_a->num == nbr)
			break ;
		head_a = head_a->next;
		i++;
	}
	return (i);
}
