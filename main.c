/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtewelde <mtewelde@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:54:32 by mtewelde          #+#    #+#             */
/*   Updated: 2024/10/16 18:44:02 by mtewelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **a)
{
	t_stack	**b;

	b = malloc(sizeof(t_stack *));
	if (!b)
		return ;
	*b = NULL;
	if (ft_stack_len(*a) == 2)
		sa(a);
	else if (ft_stack_len(*a) == 3)
		sort_three(a);
	else
		sort_big(a, b);
	free_stack(b);
	free(b);
}

int	main(int ac, char *av[])
{
	t_stack	**a;

	if (ac == 1)
		return (0);
	if (ac > 1)
	{
		if (valid_av(av))
			ft_error();
		a = initialize(av);
		if (!a)
			ft_error();
		if (check_sorted(a))
		{
			free_stack(a);
			free(a);
			return (0);
		}
		else
			push_swap(a);
		free_stack(a);
		free(a);
	}
}
