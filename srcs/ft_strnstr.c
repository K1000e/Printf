/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgorin <cgorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 19:14:33 by cgorin            #+#    #+#             */
/*   Updated: 2024/04/24 17:39:52 by cgorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	search_needle(const char *haystack, const char *needle)
{
	size_t	i;

	i = 0;
	while (needle[i])
	{
		if (needle[i] != haystack[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (!needle[i])
		return ((char *)(haystack));
	while (*haystack && i < len)
	{
		if (*haystack == needle[0] && ft_strlen(needle) <= len - i)
			if (search_needle(haystack, needle))
				return ((char *)(haystack));
		haystack++;
		i++;
	}
	return (NULL);
}

/* int main()
{
	printf("%s\n", ft_strnstr("abcdefghijklmnopqrstuvwxyz", "jkl", 10));
} */
/* The strnstr() function locates the first occurrence of the null-
     terminated string needle in the string haystack, where not more than
     len characters are searched.  Characters that appear after a ‘\0’
     character are not searched.  Since the strnstr() function is a FreeBSD
     specific API, it should only be used when portability is not a concern.

     While the strcasestr() function uses the current locale, the
     strcasestr_l() function may be passed a locale directly. See xlocale(3)
     for more information.

RETURN VALUES
     If needle is an empty string, haystack is returned; if needle occurs
     nowhere in haystack, NULL is returned; otherwise a pointer to the first
     character of the first occurrence of needle is returned. */