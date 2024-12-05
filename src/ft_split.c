/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtewelde <mtewelde@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:43:21 by mtewelde          #+#    #+#             */
/*   Updated: 2024/10/23 00:04:48 by mtewelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_str(char *str, char sep)
{
	int		result;
	int		flag;

	result = 0;
	while (*str)
	{
		flag = 0;
		while (*str == sep && *str)
			str++;
		while (*str != sep && *str)
		{
			if (!flag)
			{
				result++;
				flag = 1;
			}
			str++;
		}
	}
	return (result);
}

static char	*get_word(char *str, char sep)
{
	static int	index = 0;
	char		*result;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[index] == sep)
		index++;
	while ((str[index + len] != sep) && str[index + len])
		len++;
	result = malloc((size_t)len * sizeof(char) + 1);
	if (result == NULL)
		return (NULL);
	while ((str[index] != sep) && str[index])
		result[i++] = str[index++];
	result[i] = '\0';
	return (result);
}

char	**ft_split(char *str, char sep)
{
	int		i;
	int		words;
	char	**result;

	i = 0;
	words = count_str(str, sep);
	result = malloc(sizeof(char *) * (size_t)(words + 1));
	if (!words)
	{
		free(result);
		ft_error();
	}
	if (result == NULL)
		return (NULL);
	while (words-- > 0)
		result[i++] = get_word(str, sep);
	result[i] = NULL;
	return (result);
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

    printf("Split Result:\n");
    for (int i = 0; result[i] != NULL; i++)
    {
        printf("%s\n", result[i]);
        free(result[i]);
    }

    return 0;
}*/
