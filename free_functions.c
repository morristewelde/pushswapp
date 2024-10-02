/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtewelde <mtewelde@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 20:00:58 by mtewelde          #+#    #+#             */
/*   Updated: 2024/07/08 14:10:48 by mtewelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*main;

	if (stack == NULL)
		return ;
	main = *stack;
	while (main)
	{
		tmp = main->next;
		free(main);
		main = tmp;
	}
	*stack = NULL;
}

/*void	free_string(char **av)
{
	int	i;
	
	i = 0;
	if (av == NULL|| *av == NULL)
		return ;
	while (av[i])
	{
		free(av[i++]);
	}
}*/

void	free_string(char **av)
{
	int	i;

	i = -1;
	if (av == NULL || *av == NULL)
		return ;
	while (av[i])
		free(av[i++]);
	free(av - 1);
}

void	error_free(t_stack_node **a, char **av, bool flag_ac2)
{
	free_stack(a);
	if (flag_ac2)
		free_string(av);
	write(1, "Error\n", 6);
	exit(1);
}
