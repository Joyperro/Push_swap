/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:12:04 by dclement          #+#    #+#             */
/*   Updated: 2024/11/14 17:41:31 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stacks *stacks)
{
	t_stack_a	*head_a;
	t_stack_a	*next_a;

	head_a = stacks->head_a;
	next_a = stacks->head_a->next;
	if (head_a->num > next_a->num)
		ft_swap(stacks, 'a');
	free_all(stacks);
	exit(0);
}
