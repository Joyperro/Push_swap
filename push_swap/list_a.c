/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:56:51 by dclement          #+#    #+#             */
/*   Updated: 2024/05/07 18:09:52 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_a	*create_list_a(int argc, char **argv)
{
	int			i;
	t_stack_a	*head_a;
	t_stack_a	*tmp;

	i = 1;
	head_a = ft_newnode_a(ft_atoi(argv[i]));
	tmp = head_a;
	while(++i < argc)
	{
		tmp->next = ft_newnode_a(ft_atoi(argv[i]));
		tmp = tmp->next;
		tmp->next = NULL;
	}
	return (head_a);
}

t_stack_a	*ft_newnode_a(int content)
{
	t_stack_a	*ptr;

	ptr = (t_stack_a *)malloc(sizeof(t_stack_a));
	if (!ptr)
		return (NULL);
	ptr->num = content;
	ptr->next = NULL;
	return(ptr);
}

void	ft_clearnode_a(t_stack_a **lst)
{
	t_stack_a	*ptr;

	while(*lst != NULL)
	{
		ptr = *lst;
		*lst = ptr->next;
		free(ptr);
	}
}