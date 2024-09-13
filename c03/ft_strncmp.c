/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: k-maru <scribearm@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:25:01 by k-maru            #+#    #+#             */
/*   Updated: 2024/09/12 14:40:38 by k-maru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned char	*c1;
	unsigned char	*c2;

	if (n == 0)
		return (0);

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	i = 0;
	while ((s1[i] && s2[i])
		&& (i < n - 1)
		&& (c1[i] == c2[i]))
		i++;

	return (c1[i] - c2[i]);
}
