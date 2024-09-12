/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: k-maru <scribearm@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 09:48:13 by k-maru            #+#    #+#             */
/*   Updated: 2024/09/11 09:58:06 by k-maru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// func. copies str pointed by src, including terminating null byte (\0) pointed by dest, they must not overlap (what's overlapping?) and dest must be large enough to receive the copy.
char	*ft_strcpy(char *dest, char *src);

int	main(void)
{
	#include <stdio.h>

	char	dest[20];
	char	*src = "bundinha";

	printf("%s\n", dest);
	ft_strcpy(dest, src);
	printf("%s\n", dest);

	return (0);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';

	return	dest;
}

int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		continue ;

	return (i);
}
