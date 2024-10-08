/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtewelde <mtewelde@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 22:18:35 by mtewelde          #+#    #+#             */
/*   Updated: 2024/10/08 22:43:49 by mtewelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_len(t_stack_node *a)
{
	size_t	len;

	len = 0;
	while (a)
	{
		a = a->next;
		len++;
	}
	return (len);
}
