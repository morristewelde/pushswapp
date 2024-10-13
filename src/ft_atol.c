/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtewelde <mtewelde@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 23:02:52 by mtewelde          #+#    #+#             */
/*   Updated: 2024/10/13 23:36:26 by mtewelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_atol(char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str < 48 || *str > 57)
			show_error();
		res = res * 10 + (*str - 48);
		str++;
	}
	if ((res * sign) > 2147483647 || (res * sign) < -2147483648)
		show_error();
	return (res * sign);
}

void	show_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}