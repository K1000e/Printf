/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgorin <cgorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 21:14:19 by cgorin            #+#    #+#             */
/*   Updated: 2024/04/24 17:39:52 by cgorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	search_tab_size(const char *s, int c)
{
	int	tab_size;

	if (!s)
		return (0);
	tab_size = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			break ;
		tab_size++;
		while (*s && *s != c)
			s++;
	}
	return (tab_size);
}

int	search_string_size(const char *s, int c)
{
	int	string_size;

	if (!s)
		return (0);
	string_size = 0;
	while (*s && *s != c)
	{
		string_size++;
		s++;
	}
	return (string_size);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		tab_size;
	int		i;
	int		x;

	tab_size = search_tab_size(s, c);
	res = (char **)malloc(sizeof(char *) * (tab_size + 1));
	if (!res || !s)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c && *s++)
			;
		if (!*s)
			break ;
		x = 0;
		res[i] = malloc(sizeof(char) * (search_string_size(s, c) + 1));
		while (*s != c && *s)
			res[i][x++] = *s++;
		res[i++][x] = '\0';
	}
	res[tab_size] = NULL;
	return (res);
}

/* int main(void)
{
	char *s = "salut, comment tu vas?";
	char c = ',';
	char **tab = ft_split(s, c);
	int i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return (0);
} */