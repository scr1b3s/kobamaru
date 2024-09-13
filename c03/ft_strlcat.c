/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: k-maru <scribearm@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:14:29 by k-maru            #+#    #+#             */
/*   Updated: 2024/09/13 09:43:46 by k-maru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* func. appends the NUL-TERMINATED str. "src" to the END of "dest", appending
 * at most size - strlen("dest") - 1 bytes. NUL-Terminates the result.
 */
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	s_src;

	i = -1;
	while (dest[++i])
		continue ;

	s_src = i;
	j = -1;
	while (++j < (size - s_src))
		dest[i++] = src[j];
	if (src[j] != '\0')
		j = size;
	else
		dest[i] = '\0';

	return (j);
}
