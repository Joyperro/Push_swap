/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:53:11 by dclement          #+#    #+#             */
/*   Updated: 2024/05/07 18:03:14 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	error_check(argc, argv);
	stacks.head_a = create_list_a(argc, argv);
	stacks.head_b = NULL;
	check_doubles(stacks.head_a);
}