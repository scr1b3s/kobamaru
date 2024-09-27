/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: k-maru <scribearm@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:05:58 by k-maru            #+#    #+#             */
/*   Updated: 2024/09/18 21:03:21 by k-maru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// similar to strcpy, but at most n bytes of src are copied. If there's null terminating byte in the first n bytes, dest isn't null terminated. If length of src is less than n, strncpy places additional null bytes at total of n.
char	*ft_strncpy(char *dest, char *src, unsigned int n);

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
