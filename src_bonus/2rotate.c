/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2rotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtewelde <mtewelde@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 23:51:28 by mtewelde          #+#    #+#             */
/*   Updated: 2024/10/16 21:10:17 by mtewelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

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
}

void	rb(t_stack **b)
{
	rotate(b);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}
