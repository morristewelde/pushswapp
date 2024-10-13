/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtewelde <mtewelde@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:42:35 by mtewelde          #+#    #+#             */
/*   Updated: 2024/10/13 23:36:38 by mtewelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"

void	double_free(char **p)
{
	int	i;

	i = -1;
	while (p[++i])
		free(p[i]);
	free(p);
}

void	final_check(t_list *lst, int new)
{
	while (lst)
	{
		if (lst->nb == new)
			show_error();
		lst = lst->next;
	}
}

t_list	*get_max(t_list **lst)
{
	t_list	*max;
	t_list	*curr;

	curr = *lst;
	max = *lst;
	while (curr && max->rank)
	{
		if (!(curr->rank))
		{
			max = curr;
			break ;
		}
		curr = curr->next;
	}
	while (curr)
	{
		if (curr->nb > max->nb && !(curr->rank))
			max = curr;
		curr = curr->next;
	}
	return (max);
}

void	set_rank(t_list **lst_a)
{
	int		size;
	t_list	*max;
	t_list	*curr;

	curr = *lst_a;
	while (curr)
	{
		curr->rank = 0;
		curr = curr->next;
	}
	size = ft_lstsize(*lst_a);
	while (size)
	{
		max = get_max(lst_a);
		max->rank = size;
		size--;
	}
}

t_list	**initialize(char **av)
{
	t_list	**lst_a;
	char	**splited;
	int		i;
	int		j;

	lst_a = malloc(sizeof(t_list *));
	if (!lst_a)
		return (NULL);
	*lst_a = NULL;

	// Check if av[2] exists
	if (av[2]) // More than one argument passed
	{
		// Treat av[1], av[2], av[3], etc. as stack elements
		i = 0;
		while (av[++i])
		{
			final_check(*lst_a, atol(av[i]));  // Check and convert the argument
			ft_lstadd_back(lst_a, lst_new(av[i])); // Add it to the list
		}
	}
	else // Only av[1] is provided
	{
		// Split av[1] and treat the split result as the stack elements
		splited = ft_split(av[1], ' ');
		if (!splited)
			return (NULL);

		j = 0;
		while (splited[j])
		{
			final_check(*lst_a, atol(splited[j]));  // Check and convert the argument
			ft_lstadd_back(lst_a, lst_new(splited[j]));
			j++; // Add it to the list
		}
		double_free(splited); // Free the allocated memory for the split result
	}
	set_rank(lst_a);
	return (lst_a);
}

