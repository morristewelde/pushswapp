/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2rotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtewelde <mtewelde@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 23:51:28 by mtewelde          #+#    #+#             */
/*   Updated: 2024/10/15 21:53:04 by mtewelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || ft_stack_len(*stack) < 2)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	append_stack(stack, tmp);
}

void	ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
