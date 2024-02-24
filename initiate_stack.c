/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtewelde <mtewelde@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:44:10 by mtewelde          #+#    #+#             */
/*   Updated: 2024/02/16 18:54:54 by mtewelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *str)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] && (str[i] == ' '
			|| (str [i] < 14 && str [i] > 9)))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

bool	error_input(char *str)
{
	if (!(*str == '+' || *str == '+'
			|| (*str >= '0' && *str <= '9')))
		return (1);
	if (((*str == '+' || *str == '+')
			&& !(str[1] >= '0' && str[1] <= '9')))
		return (1);
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	return (0);
}

int	error_repetition(t_stack_node *a, int nb)
{
	if (NULL == a)
		return (0);
	while (a)
	{
		if (a->value == nb)
			return (1);
		a = a->next;
	}
	return (0);
}

t_stack_node	*ft_final_node(t_stack_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	append_stack(t_stack_node **stack, int nb)
{
	t_stack_node	*node;
	t_stack_node	*last;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->value = nb;
	if (*stack == NULL)
	{
		*stack = node;
		node->previous = NULL;
	}
	else
	{
		last = ft_final_node(*stack);
		last->next = node;
		node->previous = last;
	}
}

void	initiate_stack(t_stack_node **a, char **av, bool flag_ac2)
{
	long	nb;
	int		i;

	i = 0;
	while (av[i])
	{
		if (error_input(av[i]))
			error_free(a, av, flag_ac2);
		nb = ft_atol(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			error_free(a, av, flag_ac2);
		if (error_repetition(*a, (int)nb))
			error_free(a, av, flag_ac2);
		append_stack(a, (int)nb);
		i++;
	}
	if (flag_ac2)
		free_string(av);
}
