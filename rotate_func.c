/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtewelde <mtewelde@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:09:48 by mtewelde          #+#    #+#             */
/*   Updated: 2024/07/08 14:12:40 by mtewelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack_node **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack_node **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*final;
	int				len;

	len = ft_stack_len(*stack);
	if (*stack == NULL || stack == NULL || len == 1)
		return ;
	final = ft_final_node(*stack);
	final->next = *stack;
	*stack = (*stack)->next;
	(*stack)->previous = NULL;
	final->next->previous = final;
	final->next->next = NULL;
}
