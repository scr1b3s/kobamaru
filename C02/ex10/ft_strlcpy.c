/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: k-maru <scribearm@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:43:49 by k-maru            #+#    #+#             */
/*   Updated: 2024/09/18 21:13:11 by k-maru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* func. copies a given str. designed to be "safer": takes the full size of the buffer
 * (not only the length, it means: strlen + 1) and garantees the null termination. Must
 * have a NUL termination in dst, for strlcpy. They only operate in TRUE C Strings.
 *
 * strlcpy copies up to size - 1, and NULL-terminates.
 * returns the total len of the str. tried to copy.
 */
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
unsigned int	ft_strlen(char *str);

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	
	i = ft_strlen(src);	
	j = 0;
	while (src[j] && j < size - 1)
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';

	if (j - 1 == i)
		return (i);
	else
		return (j);
}

unsigned int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		continue ;

	return ((unsigned int)i);
}
