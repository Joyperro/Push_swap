/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:22:00 by dclement          #+#    #+#             */
/*   Updated: 2024/05/07 18:00:39 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_check(int argc, char **argv)
{
	if (argc == 1)
		exit(0);
	check_ints(argc, argv);
	check_int_size(argc, argv);
}

void	check_ints(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '\0')
			error();
		while(j < (int)ft_strlen(argv[i]))
		{
			if (!ft_isdigit(argv[i][j]))
			{
				if (j == 0 && ft_strlen(argv[i]) != 1
					&& (argv[i][j] == '-' || argv[i][j] == '+'))
					j++;
				else
					error();
			}
			j++;
		}
		i++;
	}
}

void	check_int_size(int argc, char **argv)
{
	long	num;
	int		i;

	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		if (num > INTMAX || num < INTMIN)
			error();
		i++;
	}
}

void	check_double(t_stack_a *head_a)
{
	t_stack_a	*tmp;
	t_stack_a	*ptr;
	int			num;

	ptr = head_a;
	while (ptr != NULL)
	{
		tmp = ptr;
		num = tmp->num;
		tmp = tmp->next;
		while (tmp != NULL)
		{
			if (num = tmp->num)
			{
				ft_clearnode_a(&head_a);
				error();
			}
			tmp = tmp->next;
		}
		ptr = ptr->next;
	}
}

void	error()
{
	ft_printf("Error\n");
	exit(0);
}