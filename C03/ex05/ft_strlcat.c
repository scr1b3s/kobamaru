/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: k-maru <scribearm@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:14:29 by k-maru            #+#    #+#             */
/*   Updated: 2024/09/17 22:25:39 by k-maru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* func. appends the NUL-TERMINATED str. "src" to the END of "dest", appending
 * at most size - strlen("dest") - 1 bytes. NUL-Terminates the result.
 */
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
unsigned int	ft_strlen(char *s);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	s_dest;

	i = -1;
	while (dest[++i])
		continue ;

	s_dest = ft_strlen(dest);
	j = -1;
	while (++j < size - s_dest - 1)
		dest[i++] = src[j];
	if (src[j] != '\0')
		j = size;
	else
	{
		dest[i] = '\0';
		j += s_dest;
	}

	return (j);
}

unsigned int	ft_strlen(char *s)
{
	unsigned int	i;

	i = -1;
	while(s[++i])
		continue ;

	return (i);
}
