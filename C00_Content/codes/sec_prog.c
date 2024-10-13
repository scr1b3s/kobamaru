/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sec_prog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: k-maru <scribearm@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:03:55 by k-maru            #+#    #+#             */
/*   Updated: 2024/10/12 20:31:45 by k-maru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	a = 5; /* var. global INICIALIZADA, fica em DATA. */
int	b[20]; /* var. global NÃO-INICIALIZADA, vai p/ BSS */
const char*	hello = "Hello World!\n"; /* const. str. vai p/ RO-DATA. */

int	main(void) /* vai p/ TEXT: texto do programa. */
{
	int	c; /* var. local, vai p/ STACK. */
	
	char	*p = (char *)malloc(sizeof(char) * (strlen(hello) + 1));
	/* seção de memória entregue p/ manipulação: vai p/ HEAP. */


	printf("DATA: 	 	&a 	= 0x%p.\n", &a);
	printf("BSS: 	 	&b[0]   = 0x%p.\n", &b[0]);
	printf("RO-DATA:	hello   = 0x%p.\n", &hello);
	printf("STACK:	 	&c 	= 0x%p.\n", &c);
	printf("HEAP:	 	&p	= 0x%p.\n", p);
	printf("TEXT:	 	main	= 0x%p.\n", &main);

	return (0);
}
