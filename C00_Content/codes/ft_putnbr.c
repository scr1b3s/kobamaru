/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: k-maru <scribearm@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 22:26:49 by k-maru            #+#    #+#             */
/*   Updated: 2024/09/09 22:37:21 by k-maru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);
void	ft_putchar(char c);

/*
int	main(void)
{
	ft_putnbr(2147483647);
	ft_putchar('\n');
}
*/

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else
	{
		if (nb < 0)
			ft_putchar('-');
		else
		{
			if (nb > 9)
			{
				ft_putnbr(nb / 10);
				ft_putnbr(nb % 10);
			}
			else
				ft_putchar('0' + nb);
		}
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
