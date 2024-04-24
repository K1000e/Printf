/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgorin <cgorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 19:13:19 by cgorin            #+#    #+#             */
/*   Updated: 2024/04/24 17:39:52 by cgorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		size;

	size = 0;
	if (s1)
		size += ft_strlen(s1);
	if (s2)
		size += ft_strlen(s2);
	res = ft_calloc(sizeof(char), (size + 1));
	if (!res)
		return (NULL);
	i = 0;
	if (s1)
	{
		while (s1[i])
		{
			res[i] = s1[i];
			i++;
		}
	}
	if (s2)
		while (*s2)
			res[i++] = *s2++;
	return (res);
}

/* int main(int argc, char **argv)
{
	if (argc == 2)
		printf("%s\n", ft_strjoin(argv[1], NULL));
	else
		printf("%s\n", ft_strjoin(argv[1], argv[2]));
	return (0);
} */