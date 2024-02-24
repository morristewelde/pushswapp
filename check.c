/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtewelde <mtewelde@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 13:17:46 by mtewelde          #+#    #+#             */
/*   Updated: 2024/02/24 13:50:54 by mtewelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_sort(t_stack_node *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

int	ft_stack_len(t_stack_node *stack)
{
	int	len;

	if (stack == NULL)
		return (0);
	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

static t_stack_node *ft_find_largest(t_stack_node *stack)
{
	int				largest;
	t_stack_node	*largest_node;

	if (stack == NULL)
		return (NULL);
	largest = INT_MIN;
	while (stack)
	{
		if(stack->value > largest)
		{
			largest = stack->value;
			largest_node = stack;
		}
		stack = stack->next;
	}
	return (largest_node);
}

