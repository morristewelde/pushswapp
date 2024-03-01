/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtewelde <mtewelde@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:28:31 by mtewelde          #+#    #+#             */
/*   Updated: 2024/02/24 14:01:00 by mtewelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//morrisT

#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_stack_node *stack)
{
	while (stack)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	bool			ac2;

	a = NULL;
	ac2 = false;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		ac2 = true;
	}

	initiate_stack(&a, av + 1, ac2);

	if (!check_sort(a))
	{
		if (ft_stack_len(a) == 2)
		{
			sa(&a);
			print_stack(a);
		} 
		else if (ft_stack_len(a) == 3)
		{
			tiny_sort(&a);
			print_stack(a);
		}
	} 
	else if (check_sort(a))
	{
		printf("is already sorted\n");
	}
	free_stack(&a);
}

