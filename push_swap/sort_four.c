/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:49:48 by dclement          #+#    #+#             */
/*   Updated: 2024/11/21 15:35:50 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_four(t_stacks *stacks)
{
	struct t_moves		*moves;
	struct t_cheapest	*cheapest;
	t_values			*value;

	if (check_order(stacks))
		return ;
	moves = ft_calloc(1, sizeof(t_moves));
	stacks->moves = moves;
	cheapest = ft_calloc(1, sizeof(t_cheapest));
	stacks->cheapest = cheapest;
	value = ft_calloc(1, sizeof(t_values));
	stacks->value = value;
	ft_push(stacks, 'b');
	sort_three(stacks, 0);
	move_back(stacks);
}
