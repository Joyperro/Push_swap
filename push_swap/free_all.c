/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:56:27 by dclement          #+#    #+#             */
/*   Updated: 2025/01/27 12:55:17 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_stacks *stacks)
{
	ft_clearnode_a(&stacks->head_a);
	ft_clearnode_b(&stacks->head_b);
	free(stacks->moves);
	free(stacks->value);
	free(stacks->cheapest);
	free(stacks->one_arg);
	free(stacks);
}

int	ft_split_count(char **str)
{
	int	i;

	if (!str || !str[0])
		return (0);
	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

int	is_flag(int flag)
{
	if (flag == 0)
		return (1);
	else
		return (0);
}

void	ft_split_free(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
