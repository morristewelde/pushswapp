/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtewelde <mtewelde@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 21:44:55 by mtewelde          #+#    #+#             */
/*   Updated: 2024/10/15 22:18:08 by mtewelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*get_max(t_stack **stack)
{
	t_stack	*max;
	t_stack	*tmp;

	tmp = *stack;
	max = *stack;
	while (tmp && max->index)
	{
		if (!(tmp->index))
		{
			max = tmp;
			break ;
		}
		tmp = tmp->next;
	}
	while (tmp)
	{
		if (tmp->value > max->value && !(tmp->index))
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

//set the index by the length of the stack
//the smallest node setted to 1 the the biggest to the length of the stack
void	set_index(t_stack **a)
{
	int		size;
	t_stack	*max;
	t_stack	*tmp;

	tmp = *a;
	while (tmp)
	{
		tmp->index = 0;
		tmp = tmp->next;
	}
	size = ft_stack_len(*a);
	while (size)
	{
		max = get_max(a);
		max->index = size;
		size--;
	}
}

t_stack	**initialize_splited(t_stack **a, char **av)
{
	char	**splited;
	int		value;
	int		i;

	splited = ft_split(av[1], ' ');
	if (!splited)
		return (NULL);
	i = 0;
	while (splited[i])
	{
		value = ft_atol(splited[i]);
		check_repetition(*a, value);
		append_stack(a, create_stack(value));
		i++;
	}
	free_str(splited);
	return (a);
}

t_stack	**initialize_args(t_stack **a, char **av)
{
	int	i;
	int	value;

	i = 0;
	while (av[++i])
	{
		value = ft_atol(av[i]);
		check_repetition(*a, value);
		append_stack(a, create_stack(value));
	}
	return (a);
}

t_stack	**initialize(char **av)
{
	t_stack	**a;

	a = malloc(sizeof(t_stack *));
	if (!a)
		return (NULL);
	*a = NULL;
	if (av[2])
		a = initialize_args(a, av);
	else
		a = initialize_splited(a, av);
	set_index(a);
	return (a);
}
