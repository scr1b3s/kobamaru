/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hello_world.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: k-maru <scribearm@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 22:12:25 by k-maru            #+#    #+#             */
/*   Updated: 2024/10/12 22:12:28 by k-maru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int	main(void)
{
	char	*s;

	s = "Hello World\n";
	while (*s)
		ft_putchar(*(s++));
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
