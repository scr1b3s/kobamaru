/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: k-maru <scribearm@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:50:14 by k-maru            #+#    #+#             */
/*   Updated: 2024/10/06 20:47:56 by k-maru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	count_words(char *s);

int	main(int ac, char *av[])
{
	int	count;

	count = 0;
	if (ac == 2)
	{
		count = count_words(av[1]);
		printf("%d.", count);
	}
	printf("\n");
	return (0);
}

int	count_words(char *s)
{
	int	words;
	int	i;
	int	in;

	words = 0;
	i = 0;
	in = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			in = 0;
		else if (!in)
		{
			in = 1;
			words++;
		}
		i++;
	}
	return (words);
}
