/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtewelde <mtewelde@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 23:18:52 by mtewelde          #+#    #+#             */
/*   Updated: 2024/10/15 22:06:18 by mtewelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// gives the real index (starting from 0) 
// meaning it will return the index of the minimum value from the stack 
int	min_index(t_stack **satck)
{
	int		index;
	int		min;
	int		i;
	t_stack	*tmp;

	tmp = *satck;
	min = tmp->value;
	index = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->value < min)
		{
			index = i;
			min = tmp->value;
		}
		i++;
		tmp = tmp->next;
	}
	return (index);
}

void	sort_three(t_stack **stack)
{
	if ((*stack)->index == 3)
		ra(stack);
	else if ((*stack)->next->index == 3)
		rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
}

void	sort_four(t_stack **a, t_stack **b)
{
	while (min_index(a))
	{
		if (min_index(a) < 2)
			ra(a);
		else
			rra(a);
	}
	pb(a, b);
	set_index(a);
	sort_three(a);
	while (*b)
		pa(a, b);
	set_index(a);
}

void	sort_five(t_stack **a, t_stack **b)
{
	while (min_index(a))
	{
		if (min_index(a) < 3)
			ra(a);
		else
			rra(a);
	}
	pb(a, b);
	while (min_index(a))
	{
		if (min_index(a) < 3)
			ra(a);
		else
			rra(a);
	}
	pb(a, b);
	set_index(a);
	sort_three(a);
	while (*b)
		pa(a, b);
	set_index(a);
}
