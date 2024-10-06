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

## O parâmetro desceu? - Variáveis

Muitas vezes precisamos armazenar informações p/ serem utilizadas mais tarde, no contexto de Programação, guardar informação p/ ser utilizada posteriormente é o propósito daquilo que chamamos de **Variáveis.**

Pensemos em *Variáveis* como rótulos, nós damos nomes p/ elas p/ justamente facilitar nossas vidas, afinal: É muito mais simples manejar um nome bonitinho como `c` do que um espaço na memória delimitado por 1 byte, pelo menos eu *acho.* Vai da preferência de cada um.

## Agora ele recebe um caractere?

O que está à direita de `char	c = ` é o que chamamos de **atribuição,** ou seja: estamos "atribuindo" o valor de `'a'` para a variável de tipo `char` de nome `c`... Isso não te diz absolutamente nada, por isso, vamos extratificar essa explicação:

### O que acontece quando fazemos uma atribuição

Pensemos da seguinte forma:

1. Eu preciso passar um valor tal p/ um espaço pré-definido de memória...
2. Mas esse espaço pré-definido meio que tem um limite espacial p/ a transmissão de informação...
3. Logo, eu preciso que meu valor à direita seja "traduzido" p/ esquerda, atualizando sua estrutura de forma que faça sentido.

É, basicamente, isso que significa atribuir um valor p/ uma variável.
E isso é feito de maneira implícita pelo Compilador, o que é, deveras, genial.

```c
char	c = 'a' - 1;
// [0][1][1][0][0][0][0][0][1]
// precisamos adequar esse 'a'
// ao espaço existente...
```

Isso acontece justamente porque os valores à direita são constantes... Ou seja: de um valor *primitivo*, um número, eles são transmitidos p/ poderem ser armazenados e manipulados a partir de uma *variável.*

Essa é uma coisa muito importante de se ter em mente, porque vai te poupar **muitas dores de cabeça no futuro.**

De maneira semelhante, a operação à direita pode ser reescrita toda em bits... Por exemplo:

```c
char	c = 0b01100001 - 0b00000001;
// essa operação é, de fato, equivalente
// a operação acima.
```

### O que significa diminuir 1 de 'a'?

Vamos voltar à *Tabela ASCII*, se você digitar `man ascii` você vai encontrar uma versão portátil no seu Terminal dela... lá, vamos identificar que o valor decimal de `a` é 97. Show, então nós sabemos que esse número é uma forma de traduzir o valor 97 p/ `a` em uma variável ou constante inteira que esteja dentro do espectro da Tabela.

Então, diminuir `1`, a constante inteira, de `a` resulta no valor `96`. Simples.

Nós conseguimos, então, também realizar operações matemáticas com Linguagens de Programação: Tenha isso em mente.

## O que é esse while?

`While`, "Enquanto" em inglês, é só isso: Enquanto algo for verdadeiro, ou falso, realize o que está abaixo. É um dos Fluxos de Controle, chamados normalmente de *Estruturas de Repetição*. Existem muitos outros, mas esse é o único permitido na École, então é bom acostumar-se com ele.

### Destrinchando a Repetição

Duas linhas muito diretas, mas que guardam muitos segredos... Existem coisas que são puramente estéticas e escolhas pessoais, como todo código que se preze, mas que farei questão de desenvolver agora.

```c
	while (++c <= 'z')
		write(1, &c, 1);
```

1. *enquanto* o incremento de c for menor que `'z'`
2. escreva, utilizando a `write`, o caractere `c`.

Beleza, vamos lá:

A gente sabe que conseguimos realizar operações matemáticas com Linguagens de Programação, c/ `C` nós conseguimos realizar o incremento do valor de uma variável em uma só linha, economizando um pouco de esforço (eu, pessoalmente, adoro isso...) e é exatamente o que é feito aqui e é por isso que eu diminuo 1 de `a` na primeira linha.

Agora vem uma parte mais interessante: Existem duas formas de se incrementar uma variável: `++c` incrementa o valor antes de ser utilizado, enquanto `c++` usa o valor e depois o incrementa. Só que isso também implica uma compreensão um pouco avançada de como um código é executado:

Seu código será lido de cima-para-baixo, e isso também implica as operações que são realizadas. Ou seja: c é incrementado antes de ser comparado c/ `'z'` no exemplo, o que resulta em voltarmos a ter `'a'` como valor de c.

Que é justamente o que é escrito. Se o valor de c fosse `'a'`, incrementaríamos antes de mostrá-lo na tela, nós comparamos `a`, mas acabamos escrevendo `b`. Vale a pena testar.

### Outras formas de se utilizar uma Estrutura de Repetição como While

Beleza, eu admito: **Essa pode não ser a melhor forma para um iniciante utilizar e familiar-se com while.** Mas *existem muitos códigos como esse, mas esse é meu.* Ao mesmo empo que eu consigo assumir isso, te convido a mostrar a sua versão, seria ótimo.

E vou dar uma alternativa possível:

```c
void	ft_print_alphabet(void)
{
	char	c;

	c = 'a';
	while (c <= 'z')
	{
		write(1, &c, 1);
		c++;
	}
}
```

Pronto, acho que você consegue entender melhor essa versão.

A título de curiosidade, nós conseguimos também **decrementar** valores de uma variável, é só usarmos `--` ao invés de `++`, um bom exemplo disso é tentarmos escrever as letras do alfabeto de trás-para-frente:

```c
	char	c = 'z' + 1;

	while (--c >= 'a')
		write(1, &c, 1);
```

No nosso próximo encontro, vamos falar sobre uma coisa muito importante antes de tratarmos de um *Fluxo de Controle* que transmite algo parecido c/ condições... Seu nome é bem auto-explicativo.