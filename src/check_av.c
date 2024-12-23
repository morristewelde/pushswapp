/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtewelde <mtewelde@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 21:44:55 by mtewelde          #+#    #+#             */
/*   Updated: 2024/10/23 02:04:56 by mtewelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_sorted(t_stack **lst)
{
	t_stack	*curr;

	curr = *lst;
	while (curr->next)
	{
		if (curr->value > curr->next->value)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	check_repetition(t_stack *stack, int new)
{
	while (stack)
	{
		if (stack->value == new)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	check_value(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '+' || av[i][j] == '-')
			{
				if (av[i][j - 1] && av[i][j - 1] != ' ')
					return (1);
				if (av[i][j + 1] < '0' || av[i][j + 1] > '9')
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_empty_value(char **av)
{
	int	i;
	int	j;
	int	is_all_whitespace;

	i = 1;
	while (av[i])
	{
		j = 0;
		is_all_whitespace = 1;
		while (av[i][j])
		{
			if (!(av[i][j] == 32 || (av[i][j] >= 9 && av[i][j] <= 13)))
			{
				is_all_whitespace = 0;
				break ;
			}
			j++;
		}
		if (is_all_whitespace)
			return (1);
		i++;
	}
	return (0);
}

int	valid_av(char **av)
{
	int		i;
	int		j;

	i = 1;
	while (av[i])
	{
		if (!av[i][0])
			return (1);
		j = 0;
		while (av[i][j])
		{
			if (!((av[i][j] >= '0' && av[i][j] <= '9')
				|| (av[i][j] == '-') || (av[i][j] == '+')
				|| av[i][j] == ' '))
				return (1);
			j++;
		}
		i++;
	}
	if (check_value(av) || check_empty_value(av))
		return (1);
	return (0);
}
