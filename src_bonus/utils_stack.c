/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtewelde <mtewelde@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 22:18:35 by mtewelde          #+#    #+#             */
/*   Updated: 2024/10/16 21:11:15 by mtewelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

//create single stack
t_stack	*create_stack(int n)
{
	t_stack	*lst;

	lst = (t_stack *) malloc(sizeof(t_stack));
	if (!lst)
		ft_error();
	lst->value = n;
	lst->index = 0;
	lst->next = NULL;
	return (lst);
}

//this function will apppend a newly created stack after the last stack
void	append_stack(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (!*stack)
		*stack = new;
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

//returns the length of a given stack
int	ft_stack_len(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

//returns the last node of stack
t_stack	*ft_last_stack(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
