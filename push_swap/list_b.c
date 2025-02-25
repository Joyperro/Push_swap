/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:58:52 by dclement          #+#    #+#             */
/*   Updated: 2024/10/17 19:11:10 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_b	*create_list_b(int argc, char **argv)
{
	int			i;
	t_stack_b	*head_b;
	t_stack_b	*tmp;

	i = 1;
	head_b = ft_newnode_b(ft_atoi(argv[i]));
	tmp = head_b;
	while (++i < argc)
	{
		tmp->next = ft_newnode_b(ft_atoi(argv[i]));
		tmp = tmp->next;
		tmp->next = NULL;
	}
	return (head_b);
}

t_stack_b	*ft_newnode_b(int content)
{
	t_stack_b	*ptr;

	ptr = (t_stack_b *)malloc(sizeof(t_stack_b));
	if (!ptr)
		return (NULL);
	ptr->num = content;
	ptr->next = NULL;
	return (ptr);
}

void	ft_clearnode_b(t_stack_b **lst)
{
	t_stack_b	*ptr;

	while (*lst != NULL)
	{
		ptr = *lst;
		*lst = ptr->next;
		free(ptr);
	}
}

int	ft_lstsize_b(t_stack_b *head_b)
{
	t_stack_b	*tmp;
	int			count;

	tmp = head_b;
	count = 0;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

t_stack_b	*ft_lstlast_b(t_stack_b *head_b)
{
	if (head_b == NULL)
		return (NULL);
	while (head_b->next != NULL)
		head_b = head_b->next;
	return (head_b);
}
