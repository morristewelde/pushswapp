/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1swap.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtewelde <mtewelde@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 22:45:11 by mtewelde          #+#    #+#             */
/*   Updated: 2024/10/16 22:23:44 by mtewelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack **stack)
{
	int	value;

	if (!stack || ft_stack_len(*stack) < 2)
		return ;
	value = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = value;
	value = (*stack)->index;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->index = value;
}

void	sa(t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
