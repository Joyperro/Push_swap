/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:56:51 by dclement          #+#    #+#             */
/*   Updated: 2025/01/15 16:01:44 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_a	*ft_newnode_a(int content)
{
	t_stack_a	*ptr;

	ptr = (t_stack_a *)malloc(sizeof(t_stack_a));
	if (!ptr)
		return (NULL);
	ptr->num = content;
	ptr->next = NULL;
	return (ptr);
}

t_stack_a	*create_list_a(int num, char **str, int flag)
{
	int			i;
	t_stack_a	*head_a;
	t_stack_a	*tmp;

	if (flag == 0)
		i = 1;
	else
		i = 0;
	head_a = ft_newnode_a(ft_atoi(str[i]));
	tmp = head_a;
	while (++i < num)
	{
		tmp->next = ft_newnode_a(ft_atoi(str[i]));
		tmp = tmp->next;
		tmp->next = NULL;
	}
	return (head_a);
}

void	ft_clearnode_a(t_stack_a **lst)
{
	t_stack_a	*ptr;

	while (*lst != NULL)
	{
		ptr = *lst;
		*lst = ptr->next;
		free(ptr);
	}
}

int	ft_lstsize_a(t_stack_a *head_a)
{
	t_stack_a	*tmp;
	int			count;

	tmp = head_a;
	count = 0;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

t_stack_a	*ft_lstlast_a(t_stack_a *head_a)
{
	if (head_a == NULL)
		return (NULL);
	while (head_a->next != NULL)
		head_a = head_a->next;
	return (head_a);
}
