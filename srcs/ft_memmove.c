/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgorin <cgorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 19:13:54 by cgorin            #+#    #+#             */
/*   Updated: 2024/04/24 17:39:52 by cgorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	void	*ptr;

	ptr = dst;
	if ((!src && !dst) || dst == src)
		return (dst);
	if (dst > src)
	{
		while (n--)
			((char *)dst)[n] = ((char *)src)[n];
	}
	else
	{
		while (n--)
			*(char *)dst++ = *(char *)src++;
	}
	return (ptr);
}

/* #include <string.h>
#include <stdio.h>
#define SIZE    21
char target[SIZE] = "a shiny white sphere";
char target2[SIZE] = "a shiny white sphere";

int	main()
{
	char * p = target + 8;  // p points at the starting character
                          of the word we want to replace //
  	char * source = target + 2; / start of "shiny" /
	printf( "Before memmove, target is \"%s\"\n", target );
	memmove( p, source, 5 );
	printf( "After memmove, target becomes \"%s\"\n", target );

	char * p2 = target2 + 8;  / p points at the starting character
                          of the word we want to replace /
  	char * source2 = target2 + 2; / start of "shiny" /
	printf( "Before memmove, target is \"%s\"\n", target2 );
	memmove( p2, source2, 5 );
	printf( "After memmove, target becomes \"%s\"\n", target2 );
} */
/* 
DESCRIPTION
     The memmove() function copies len bytes from string src to string dst.
     The two strings may overlap; the copy is always done in a non-
     destructive manner.

RETURN VALUES
     The memmove() function returns the original value of dst. 
*/