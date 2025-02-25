/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_min_max_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:07:33 by dclement          #+#    #+#             */
/*   Updated: 2024/11/14 18:46:31 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_stack_b(t_stacks *stacks, int nbr);

void	new_min_max_b(t_stacks *stacks)
{
	int	i;
	int	size;

	stacks->moves->rb = 0;
	stacks->moves->rrb = 0;
	if (stacks->head_b->num == stacks->value->max_b)
		return ;
	i = find_index_b(stacks, stacks->value->max_b);
	size = ft_lstsize_b(stacks->head_b);
	if (size % 2 == 0)
	{
		if (i + 1 > size / 2)
			stacks->moves->rrb = (size - i);
		else
			stacks->moves->rb = i;
	}
	else
	{
		if (i > size / 2)
			stacks->moves->rrb = (size - i);
		else
			stacks->moves->rb = i;
	}
}

void	new_num_b(t_stacks *stacks, int num)
{
	int	i;
	int	size;
	int	nbr;

	stacks->moves->rb = 0;
	stacks->moves->rrb = 0;
	nbr = search_stack_b(stacks, num);
	if (stacks->head_b->num == nbr)
		return ;
	i = find_index_b(stacks, nbr);
	size = ft_lstsize_b(stacks->head_b);
	if (size % 2 == 0)
	{
		if (i + 1 > size / 2)
			stacks->moves->rrb = (size - i);
		else
			stacks->moves->rb = i;
	}
	else
	{
		if (i > size / 2)
			stacks->moves->rrb = (size - i);
		else
			stacks->moves->rb = i;
	}
}

int	find_index_b(t_stacks *stacks, int nbr)
{
	t_stack_b	*head_b;
	int			i;

	i = 0;
	head_b = stacks->head_b;
	while (head_b != NULL)
	{
		if (head_b->num == nbr)
			break ;
		head_b = head_b->next;
		i++;
	}
	return (i);
}

int	search_stack_b(t_stacks *stacks, int nbr)
{
	t_stack_b	*head_b;
	int			size;
	int			flag;
	int			i;

	i = 0;
	flag = 0;
	head_b = stacks->head_b;
	size = ft_lstsize_b(stacks->head_b);
	while (flag == 0)
	{
		i = 0;
		nbr--;
		head_b = stacks->head_b;
		while (i++ < size)
		{
			if (head_b->num == nbr)
				flag = 1;
			head_b = head_b->next;
		}
	}
	return (nbr);
}
