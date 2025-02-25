/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:22:00 by dclement          #+#    #+#             */
/*   Updated: 2025/01/27 13:02:04 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(t_stacks *stacks);

static void	check_ints(int num, char **str, int flag, t_stacks *stacks)
{
	int	i;
	int	j;

	i = is_flag(flag);
	while (i < num)
	{
		j = 0;
		if (str[i][j] == '\0')
			error(stacks);
		while (j < (int)ft_strlen(str[i]))
		{
			if (!ft_isdigit(str[i][j]))
			{
				if (j == 0 && ft_strlen(str[i]) != 1 && (str[i][j] == '-'
					|| str[i][j] == '+'))
				{
					j++;
					continue ;
				}
				error(stacks);
			}
			j++;
		}
		i++;
	}
}

static void	check_int_size(int n, char **str, int flag, t_stacks *stacks)
{
	long	num;
	int		i;

	if (flag == 0)
		i = 1;
	else
		i = 0;
	while (i < n)
	{
		num = ft_atol(str[i]);
		if (num > INTMAX || num < INTMIN)
			error(stacks);
		i++;
	}
}

void	error_check(int argc, char **argv, t_stacks *stacks)
{
	char	*trimmed;

	if (argc > 2)
	{
		check_ints(argc, argv, 0, stacks);
		check_int_size(argc, argv, 0, stacks);
		return ;
	}
	else if (argc == 2)
	{
		if (argv[1][0] == '"' || argv[1][ft_strlen(argv[1])] == '"')
			error(stacks);
		trimmed = ft_strdup(argv[1]);
		if (!trimmed)
			error(stacks);
		stacks->one_arg = ft_split(trimmed, ' ');
		if (!stacks->one_arg || !stacks->one_arg[0])
		{
			free(trimmed);
			error(stacks);
		}
	}
	check_ints(ft_split_count(stacks->one_arg), stacks->one_arg, 1, stacks);
	check_int_size(ft_split_count(stacks->one_arg), stacks->one_arg, 1, stacks);
	free(trimmed);
}

void	check_double(t_stack_a *head_a, t_stacks *stacks)
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
			if (num == tmp->num)
			{
				ft_clearnode_a(&head_a);
				error(stacks);
			}
			tmp = tmp->next;
		}
		ptr = ptr->next;
	}
}

void	error(t_stacks *stacks)
{
	ft_putstr_fd("Error\n", 2);
	free_all(stacks);
	exit(1);
}
