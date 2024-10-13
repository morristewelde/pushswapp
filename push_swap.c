/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtewelde <mtewelde@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 23:09:12 by mtewelde          #+#    #+#             */
/*   Updated: 2024/10/13 23:45:01 by mtewelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_list	**lst_a;
	t_list	**lst_b;
	if (ac == 1)
		return (0);
	if (ac > 1)
	{
		if (valid_args(av))
			show_error();
		lst_b = malloc(sizeof(t_list *));
		if (!lst_b)
			show_error();
		*lst_b = NULL;
		lst_a = initialize(av);
		if (!lst_a)
			show_error();
		if (is_sorted(lst_a))
			return (0);
		if (ft_lstsize(*lst_a) == 2)
			sa(lst_a);
		else if (ft_lstsize(*lst_a) == 3)
			sort_three(lst_a);
		else if (ft_lstsize(*lst_a) <= 5)
			sort_five(lst_a, lst_b);
		else
			sort_x(lst_a, lst_b);
	}
}
