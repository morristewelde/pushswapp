/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtewelde <mtewelde@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:15:49 by mtewelde          #+#    #+#             */
/*   Updated: 2024/07/08 14:30:14 by mtewelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack_node	*ft_find_largest(t_stack_node *stack)
{
	int				largest;
	t_stack_node	*largest_node;

	if (stack == NULL)
		return (NULL);
	largest = INT_MIN;
	while (stack)
	{
		if (stack->value > largest)
		{
			largest = stack->value;
			largest_node = stack;
		}
		stack = stack->next;
	}
	return (largest_node);
}

void	tiny_sort(t_stack_node **stack_a)
{
	t_stack_node	*largest_node;

	largest_node = ft_find_largest(*stack_a);
	if (*stack_a == largest_node)
		ra(stack_a);
	else if ((*stack_a)->next == largest_node)
		rra(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

void	sort_five(t_stack_node **a, t_stack_node **b)
{
	while (ft_stack_len(*a) > 3)
	{
		initiate_stack(*a, *b);
		finish_rotation(a, ft_find_smallest(*a), 'a');
		pb(b, a);
	}
}
