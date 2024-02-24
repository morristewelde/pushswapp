/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtewelde <mtewelde@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:06:09 by mtewelde          #+#    #+#             */
/*   Updated: 2024/02/24 14:09:01 by mtewelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void swap(t_stack_node **stack)
{
	int	len;

	len = ft_stack_len(*stack);
	if (*stack == NULL || stack == NULL || len == 1)
		return ;
	*stack = (*stack)->next;
	(*stack)->previous->previous = *stack;
	(*stack)->previous->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->previous = (*stack)->previous;
	(*stack)->next = (*stack)->previous;
	(*stack)->previous = NULL;
}

void	sa(t_stack_node **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_stack_node **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_stack_node **stack_a, t_stack_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*final;
	int				len;

	len = ft_stack_len(*stack);
	if(*stack == NULL || stack == NULL || len == 1)
		return ;
	final = ft_final_node(*stack);
	final->next = *stack;
	*stack = (*stack)->next;
	(*stack)->previous = NULL;
	final->next->previous = final;
	final->next->next = NULL;
}

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


static void reverse_rotate(t_stack_node **stack)
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

static t_stack_node *ft_find_largest(t_stack_node *stack)
{
	int				largest;
	t_stack_node	*largest_node;

	if (stack == NULL)
		return (NULL);
	largest = INT_MIN;
	while (stack)
	{
		if(stack->value > largest)
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

// void	sort_five(t_stack_node **stack_a, t_stack_node **stack_b)
// {
// 	while (ft_stack_len(*stack_a) > 3)
// 	{
// 		initiate_stack(*)
// 	}
// }