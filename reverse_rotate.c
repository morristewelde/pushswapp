/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtewelde <mtewelde@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:13:40 by mtewelde          #+#    #+#             */
/*   Updated: 2024/07/08 14:13:47 by mtewelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*final;
	int				len;

	len = ft_stack_len(*stack);
	if (stack == NULL || *stack == NULL || len == 1)
		return ;
	final = ft_final_node(*stack);
	final->previous->next = NULL;
	final->next = *stack;
	final->previous = NULL;
	*stack = final;
	final->next->previous = final;
}

void	rra(t_stack_node **stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack_node **stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
