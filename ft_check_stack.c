/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtewelde <mtewelde@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 21:50:25 by mtewelde          #+#    #+#             */
/*   Updated: 2024/10/08 21:55:27 by mtewelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_repetition(t_stack_node *a)
{
	t_stack_node	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (tmp->value == a->value)
				return (0);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (1);
}

int	ft_check_order(t_stack_node *a)
{
	int	nb;

	nb = a->value;
	while (a)
	{
		if (nb > a->value)
			return (0);
		nb = a->value;
		a = a->next;
	}
	return (1);
}
