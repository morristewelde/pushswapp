/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtewelde <mtewelde@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 23:10:25 by mtewelde          #+#    #+#             */
/*   Updated: 2024/10/16 21:11:02 by mtewelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	get_index(t_stack *lst, int start, int end)
{
	int	index;

	index = 0;
	while (lst)
	{
		if (lst->index >= start && lst->index <= end)
			return (index);
		lst = lst->next;
		index++;
	}
	return (-1);
}

void	push_to_b(t_stack **a, t_stack **b, int start, int end)
{
	while (get_index(*a, start, end) != -1)
	{
		if ((*a)->index >= start && (*a)->index <= end)
		{
			pb(a, b);
			if ((*b)->index <= (start + end) / 2)
			{
				if (*a && ((*a)->index > end || (*a)->index < start))
					rr(a, b);
				else
					rb(b);
			}
		}
		else
			ra(a);
	}
}

void	max_to_a(t_stack **a, t_stack **b, int size)
{
	while ((*b)->index != size)
		rb(b);
	pa(a, b);
}

void	push_back_to_a(t_stack **a, t_stack **b, int size)
{
	while (*b || !check_sorted(a))
	{
		if (*b && (*b)->index + 1 == (*a)->index)
			pa(a, b);
		else if (*b && ((*b)->index > ft_last_stack(*a)->index
				|| ft_last_stack(*a)->index == size))
		{
			pa(a, b);
			if (get_index(*b, (*a)->index - 1,
					(*a)->index - 1) < ft_stack_len(*b) / 2)
				rr(a, b);
			else
				ra(a);
		}
		else if ((*a)->index == ft_last_stack(*a)->index + 1)
			rra(a);
		else if (ft_stack_len(*b) > 1)
		{
			if (get_index(*b, (*a)->index - 1,
					(*a)->index - 1) < ft_stack_len(*b) / 2)
				rb(b);
			else
				rrb(b);
		}
	}
}

void	sort_big(t_stack **a, t_stack **b)
{
	int	i;
	int	size;

	i = 25;
	size = ft_stack_len(*a);
	if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
	else
	{
		while (*a)
		{
			push_to_b(a, b, (size / 2) - i, (size / 2) + i);
			i += 25;
		}
		max_to_a(a, b, size);
		push_back_to_a(a, b, size);
	}
}
