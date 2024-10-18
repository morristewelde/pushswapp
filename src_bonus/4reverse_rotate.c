/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4reverse_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtewelde <mtewelde@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 23:51:28 by mtewelde          #+#    #+#             */
/*   Updated: 2024/10/16 21:10:27 by mtewelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*before_last;
	t_stack	*last;

	if (!stack || ft_stack_len(*stack) < 2)
		return ;
	before_last = *stack;
	while (before_last->next->next)
		before_last = before_last->next;
	last = before_last->next;
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_stack **lst)
{
	reverse_rotate(lst);
}

void	rrb(t_stack **lst)
{
	reverse_rotate(lst);
}

void	rrr(t_stack **lst_a, t_stack **lst_b)
{
	reverse_rotate(lst_a);
	reverse_rotate(lst_b);
}
