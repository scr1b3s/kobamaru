/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: k-maru <scribearm@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 21:12:08 by k-maru            #+#    #+#             */
/*   Updated: 2024/09/12 12:37:34 by k-maru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strcapitalize(char *str);
char	*ft_strcpy(char *dest, char *src);
int	is_alphanum(char c);

int	main(void)
{

	char	*t = (char *)malloc(150 * sizeof(char));
	ft_strcpy(t, "sAlut, coMMent tu vAs ? 42mOts quarAAnte-deux; cinquante+et+un");

	printf("%s.\n", t);
	
	ft_strcapitalize(t);

	printf("%s.\n", t);

	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;

	i = 0;
	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] -= 32;
	while (str[++i])
		if ((str[i] >= 'a' && str[i] <= 'z') 
		&&  !(is_alphanum(str[i - 1])))
			str[i] -= 32;

	return (str);
}

int	is_alphanum(char c)
{
	if ((c >= '0' && c <= '9')
	||  (c >= 'A' && c <= 'Z')
	||  (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';

	return (dest);
}
