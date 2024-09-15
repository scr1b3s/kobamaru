/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: k-maru <scribearm@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 22:24:57 by k-maru            #+#    #+#             */
/*   Updated: 2024/09/09 22:24:58 by k-maru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void);

/*
int	main(void)
{
	ft_print_alphabet();
}
*/

void	ft_print_alphabet(void)
{
	char	c = 'a' - 1;
	
	while (++c <= 'z')
		write(1, &c, 1);
}
