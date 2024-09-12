/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: k-maru <scribearm@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:43:49 by k-maru            #+#    #+#             */
/*   Updated: 2024/09/12 13:12:58 by k-maru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* func. copies a given str. designed to be "safer": takes the full size of the buffer
 * (not only the length, it means: strlen + 1) and garantees the null termination. Must
 * have a NUL termination in dst, for strlcpy. They only operate in TRUE C Strings.
 *
 * strlcpy copies up to size - 1, and NULL-terminates.
 * returns the total len of the str. tried to copy.
 */
#include <bsd/string.h>
#include <stdio.h>
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
unsigned int	ft_strlen(char *str);

int	main(void)
{
	char	*src = "bundinha";
	char	t[20];
	char	t2[20];

	unsigned int val = ft_strlcpy(t, src, ft_strlen(src) + 1);
	size_t val2 = strlcpy(t2, src, ft_strlen(src) + 1);
	printf("Return of Strlcpy: %lu.\n", val2);
	printf("Result: %s.\n", t2);
	printf("Return of Ft_strlcpy: %li.\n", val2);
	printf("Result: %s.\n", t);
	
	return (0);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	
	i = ft_strlen(src);	
	j = 0;
	while (j < size - 1)
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';

	return (i);
}

unsigned int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		continue ;

	return ((unsigned int)i);
}
