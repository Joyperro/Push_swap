/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:53:11 by dclement          #+#    #+#             */
/*   Updated: 2025/01/27 13:00:55 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc == 1)
		return (0);
	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (1);
	error_check(argc, argv, stacks);
	if (argc > 2)
		stacks->head_a = create_list_a(argc, argv, 0);
	else
	{
		if (argc == 0)
			return (0);
		stacks->head_a = create_list_a(ft_split_count(stacks->one_arg),
				stacks->one_arg, 1);
	}
	stacks->head_b = NULL;
	check_double(stacks->head_a, stacks);
	sorting(stacks);
	free_all(stacks);
}
