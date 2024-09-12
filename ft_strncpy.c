/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: k-maru <scribearm@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:05:58 by k-maru            #+#    #+#             */
/*   Updated: 2024/09/11 10:21:57 by k-maru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// similar to strcpy, but at most n bytes of src are copied. If there's null terminating byte in the first n bytes, dest isn't null terminated. If length of src is less than n, strncpy places additional null bytes at total of n.
char	*ft_strncpy(char *dest, char *src, unsigned int n);

int	main(void)
{
	#include <stdio.h>

	char	dest[20];
	char	dest2[5];
	char	*src = "bundinha";

	ft_strncpy(dest, src, 20);
	printf("%s\n", dest);

	ft_strncpy(dest2, src, 2);
	printf("%s\n", dest2);

	printf("%i\n", (dest2[5] == '\0') ? 1 : 0);

	return (0);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = -1;
	while (src[++i] && i < n)
		dest[i] = src[i];
	i -= 1;
	while (++i < n)
	{
		dest[i] = '\0';
	}

	return dest;
}
