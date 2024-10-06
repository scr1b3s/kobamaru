# C00: Fluxos de Controle, Condicionais... Desvios

Às vezes, quando pensamos, é comum que nossa linha de raciocínio tenha algumas variações: "Se tal coisa acontecer, eu vou agir dessa forma", "Enquanto eu espero o ônibus, vou ler um livro"... Todas essas coisas são o que nós podemos definir como *"Fluxos de Controle"*.

O mesmo acontece em Linguagens de Programação, por incrível que pareça, podemos dizer que isso acontece justamente porque elas são, como já vimos, "linguagens formais que nós utilizamos para provar alguma coisa", ou por qualquer outro motivo arbitrário.

Vamos usar alguns exemplos de como isso normalmente funciona em Funções utilizando algumas das funções com as quais trabalhamos:

```c
/* Imprime as letras do alfabeto, em ASCII */
#include <unistd.h>

void	ft_print_alphabet(void);

void	ft_print_alphabet(void)
{
	char	c = 'a' - 1;
	
	while (++c <= 'z')
		write(1, &c, 1);
}
```

Algumas coisas vão saltar aos seus olhos, se tivermos `ft_putchar` como referência inicial:

1. Essa função não tem parâmetros.
2. Ela ainda não retorna nada.
3. Espera, o parâmetro... desceu?
4. Agora ele recebe um caractere?
5. O que significa diminuir 1 de `'a'`?
6. O que é esse `while`?

Vamos, por partes, sanar cada uma dessas dúvidas, antes de irmos p/ a próxima questão, beleza? Algumas podem ser brevemente respondidas: Não, **a função não tem parâmetros porque eles não são necessários**; Sim, **funções**, assim como a main como vimos antes, **podem não ter parâmetros**; Sim, ela não retorna valor algum, vide o *void*.

## O parâmetro desceu?

Muitas vezes precisamos armazenar informações p/ serem utilizadas mais tarde, no contexto de Programação, guardar informação p/ ser utilizada posteriormente é o propósito daquilo que chamamos de **Variáveis.**

Pensemos em *Variáveis* como rótulos, nós damos nomes p/ elas 