/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgorin <cgorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 19:13:26 by cgorin            #+#    #+#             */
/*   Updated: 2024/04/24 17:39:52 by cgorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"


char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (len > len_s - start)
		len = len_s - start;
	if (start > len_s)
	{
		res = (char *)malloc(sizeof(char) * (1));
		res[0] = 0;
		return (res);
	}
	else
		res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s + start, len + 1);
	return (res);
}

/* int main()
{
	printf("ft_substr : %s\n", ft_substr("Test 1234", 's', 5));
	printf("ft_substr : %s\n", ft_substr("Test de test", 's', 5));
	printf("ft_substr : %s\n", ft_substr("Hello World", 's', 5));
	printf("ft_substr : %s\n", ft_substr("Test", 's', 1));
	printf("ft_substr : %s\n", ft_substr("Test 1234", 's', -15));
	printf("ft_substr : %s\n", ft_substr("Test de test", 's', 25));
	printf("ft_substr : %s\n", ft_substr("Hello World", 's', 1));
	printf("ft_substr : %s\n", ft_substr("Test", 's', 1));
	return (0);
} */

/*
Valeur de retour
La nouvelle chaîne de caractères.
NULL si l’allocation échoue.
*/

/*
Description
Alloue (avec malloc(3)) et retourne une chaîne de
caractères issue  de la chaîne ’s’.
Cette nouvelle chaîne commence à l’index ’start’
et a pour taille maximale ’len’.
*/