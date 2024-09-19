/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: k-maru <scribearm@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 21:55:10 by k-maru            #+#    #+#             */
/*   Updated: 2024/09/10 22:36:27 by k-maru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size);

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;
	int	swap;

	i = -1;
	while (++i < size)
	{
		tmp = tab[i];
		j = i + 1;
		while (j < size)
		{
			if (tmp > tab[j])
			{
				swap = tmp;
				tmp = tab[j];
				tab[j] = swap;
			}
			j++;
		}
		tab[i] = tmp;
	}
}
