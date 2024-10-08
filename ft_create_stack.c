/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtewelde <mtewelde@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 21:44:55 by mtewelde          #+#    #+#             */
/*   Updated: 2024/10/08 21:56:32 by mtewelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*ft_create_singlenode(int nb)
{
	t_stack_node	*res;

	res = malloc(sizeof (t_stack_node));
	if (!res)
		ft_error();
	res->value = nb;
	res->next = NULL;
	return (res);
}

t_stack_node	*ft_last_node(t_stack_node *a)
{
	if (!a)
		return (NULL);
	while (a->next)
		a = a->next;
	return (a);
}

void	ft_append_stack(t_stack_node **a, t_stack_node *b)
{
	if (!a)
		return ;
	if (!*a)
		*a = b;
	else
		(ft_last_node(*a))->next = b;
}

t_stack_node	*ft_create_stack_av2(char *av2)
{
	int				nb;
	int				i;
	char			**str;
	t_stack_node	*res;
	t_stack_node	*temp;

	str = ft_split(av2, ' ');
	while (*str)
	{
		nb = atol(*str);
		temp = ft_create_singlenode(nb);
		ft_append_stack(&res, temp);
		str++;
	}
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	str[i] = NULL;
	return (res);
}

t_stack_node	*ft_create_stack(int ac, char **av)
{
	int				i;
	int				nb;
	t_stack_node	*res;
	t_stack_node	*temp;

	i = 1;
	res = NULL;
	if (ac == 2)
		res = ft_create_stack_av2(av[1]);
	else
	{
		while (i < ac)
		{
			nb = ft_atol(av[i]);
			temp = ft_create_singlenode(nb);
			ft_append_stack(&res, temp);
			i++;
		}
	}
	return (res);
}
