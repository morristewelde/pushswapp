/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1swap.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtewelde <mtewelde@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 22:45:11 by mtewelde          #+#    #+#             */
/*   Updated: 2024/10/16 21:10:01 by mtewelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

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
}

void	sb(t_stack **b)
{
	swap(b);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
}
