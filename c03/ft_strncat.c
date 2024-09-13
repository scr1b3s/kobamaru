/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: k-maru <scribearm@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:42:36 by k-maru            #+#    #+#             */
/*   Updated: 2024/09/12 18:51:48 by k-maru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* strncat functions like strcat, but copies at most n bytes of a given str...
 * Important part is: it includes a NULL-Terminatin' byte in the end, dest MUST
 * have enough space for the result.
 */

char	*ft_strncat(char *dest, char *src, unsigned int nb);

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int		i;
	unsigned int	j;
	
	i = -1;
	while (dest[++i])
		continue ;

	j = -1;
	while (++j < nb)
		dest[i++] = src[j];
	dest[i] = '\0';

	return (dest);
}
