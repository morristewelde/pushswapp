/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtewelde <mtewelde@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:23:02 by mtewelde          #+#    #+#             */
/*   Updated: 2024/10/08 20:32:42 by mtewelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_separator(char c, char s)
{
	if (c == s)
		return (1);
	return (0);
}

int	ft_strlen_sep(char *str, char sep)
{
	int	i;

	i = 0;
	while (str[i] && !ft_is_separator(str[i], sep))
		i++;
	return (i);
}

int	count_str(char *str, char sep)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && ft_is_separator(str[i], sep))
			i++;
		if (str[i])
			res++;
		while (str[i] && !ft_is_separator(str[i], sep))
			i++;
	}
	return (res);
}

char	*ft_get_word(char *str, char sep)
{
	int		i;
	char	*res;

	i = 0;
	res = (char *)malloc(sizeof(char) * (ft_strlen_sep(str, sep) + 1));
	if (!res)
		return (NULL);
	while (str[i] && !ft_is_separator(str[i], sep))
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	**ft_split(char *av, char sep)
{
	int		i;
	int		j;
	char	**res;

	i = 0;
	j = 0;
	res = (char **)malloc(sizeof(char *) * (count_str(av, sep) + 1));
	if (!res)
		return (NULL);
	while (av[i])
	{
		while (av[i] && ft_is_separator(av[i], sep))
			i++;
		if (av[i] && !ft_is_separator(av[i], sep))
		{
			res[j] = ft_get_word(&av[i], sep);
			j++;
		}
		while (av[i] && !ft_is_separator(av[i], sep))
			i++;
	}
	res[j] = 0;
	return (res);
}
/*#include <stdio.h>
int main()
{
    char input_str[] = "  morris is testing his   new    split";
    char sep = ' '; 
    char **result = ft_split(input_str, sep);

    if (result == NULL)
    {
        printf("Memory Failure.\n");
        return 1;
    }
    for (int i = 0; result[i] != NULL; i++)
    {
        printf("%s\n", result[i]);
        free(result[i]);
    }

    return 0;
}*/
