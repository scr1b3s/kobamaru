#  C00: Estrutura Básica de uma Função e de um Programa

Dois caras muito inteligentes disseram uma vez que a única forma de se aprender uma linguagem de programação é escrevendo nela, e o primeiro **programa** costuma ser o mesmo para todas as linguagens... Eles falavam do _"Hello World"._

Na École 42 nosso "Hello World" tem uma letra apenas, e se chama **ft_putchar**:

```c
/* Imprime um caractere na Saída Padrão. */
#include <unistd.h>

void	ft_putchar(char c);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
```

Se você já viu um filme muito bom chamado _"Full Metal Jacket"_ ou _"Nascido para Matar"_ em português, que fala sobre a experiência de jovens soldados na Guerra do Vietnã, você deve estar familiarizado com a seguinte frase:

> _This is my rifle. There are many like it, but this one is mine._
> _Esse é meu rifle. Existem muitos como ele, mas esse é meu._

Enfim: Essa é a minha função. Existem muitas como ela, mas essa é minha. Ela imprime um caractere na tela... E ela é boa o suficiente assim.

Lendo de cima para baixo, nós temos algumas coisas importantes a serem levadas em consideração... E uma delas com certeza é aquele **"#include"** flutuando.

1. Resumidamente, o **#include** indica ao Pré-Processador de C que algo deve ser incluído em seu lugar antes do processo de Compilação acontecer.

Tudo bem, agora temos mais algumas perguntas: O que é um *Pré-Processador* e o que é *Processo de Compilação*?

- Pré-Processamento quer dizer que um processo, frequentemente a inclusão de um arquivo de cabeçalho ou a definição de algo como, por exemplo, um Macro, é feita *ANTES* da Compilação.

Já falamos de Compilação antes, mas vale a pena relembrar:

- Compilação, por sua vez, é o processo e se traduzir Código-Fonte, aquilo que nós escrevemos, em Código de Máquina, os binários que um computador (a Unidade de Processamento Central) consegue entender.

Isso dito, logo em seguida o "<unistd.h>" é o indicativo do cabeçalho que precisamos incluir. Nós sabemos disso porque digitando `man 2 write`, ou seja: Manual, Capítulo 2, Write, especificamente a função write, nos indica que ao mesmo tempo:

`write - write to a file descriptor`
`#include <unistd.h>`

Ou seja: A função **_write_** **escreve em um file descriptor... e para usá-la importamos utilizando unistd.h como argumento de include.**

Respondemos algumas perguntas, mas criamos outras, com certeza:

- O que são "File Descriptors"?
- E que significa "escrever" em um?

Essas e outras perguntas que você provavelmente deve ter não serão respondidas agora, mas sim em outro momento.

Se você é uma pessoa atenta, você deve ter percebido que eu disse antes **"programa"**... Mas nós escrevemos o que chamamos de **"função".** Como  ficaria escrito o _Hello World_ por um Estudante da 42, exatamente?

Algo parecido com isso aqui:

```c
#include <unistd.h>

void    ft_putchar(char c);

int     main(void)
{       
        char    *s;

        s = "Hello World\n";
        while (*s)
                ft_putchar(*(s++));

        return (0);
}

void    ft_putchar(char c)
{
        write(1, &c, 1);
}
```

Novamente:
> _Esse é meu programa. Existem muitos como esse, mas esse é meu._

## Funções e Programas - Algoritmos e Coisas no Meio

Funções e Programas são quase a mesma coisa. Tudo bem, eles "claramente" **não são**, até porque se fossem teriam o mesmo nome... Mas o ponto principal (pra esse primeiro momento, claro) é que ambos são a implementação de Conhecimento Declarativo de maneira Imperativa na forma de uma Sucessão de Passos Lógicos para a Realização de uma Tarefa expressos a partir de uma Linguagem Formal.

Beleza. Muita coisa.

- Conhecimento Declarativo é um conhecimento expresso em uma declaração. Ou seja: _"Para trocar uma lâmpada, você deve pegar uma escada, abrí-la, subir na escada, desatarrachar a lâmpada queimada e substituí-la por uma nova"._

Eu estou declarando como algo deve ser feito, algo que eu sei fazer. Isso, é Conhecimento Declarativo.

- De forma Imperativa implica que algo está sendo descrito na forma de Ordens, ou seja: _"1. Pegue a Lâmpada. 2. Pegue a Escada..."._

Ou seja: Estou dando ordens em formas de sentenças para que alguém faça alguma coisa que eu... muito importante: **SEI FAZER.**

- Sucessão de Passos Lógicos para a Realização de uma Tarefa pressupõe que uma tarefa, aquilo que queremos alcançar, tem algo como um Início, um Meio, e um Fim específico: O cumprimento dos requisitos para a transformação de algo, em outra coisa.

Com esses três pontos nós definimos o que um Algoritmo é:

> _Um algoritmo é uma sucessão lógica de tarefas descrita de forma a realizar algo, é a manifestação de Conhecimento em Forma Imperativa. É, normalmente, escrito em uma Linguagem Formal conhecida como Linguagem de Programação._

O bônus é dizer que ele deve ser expresso em uma Linguagem Formal, que nesse caso é a Linguagem de Programação que desejamos utilizar para solucionar um problema.

Funções recebem parâmetros, ou argumentos, dependendo da forma que ela está sendo descrita/utilizada: Quando declarada, a função tem parâmetros, quando utilizada, argumentos. Simples.

De maneira semelhante, quando queremos escrever um programa nós buscamos fazer exatamente a mesma coisa, porém, normalmente emendando Funções (Sub-Rotinas, ou Rotinas) umas nas outras, porque quando *Modularizamos* uma Rotina em uma Função estamos detectando Padrões que podem ser reutilizados, reaproveitados.

Programas claramente têm particularidades muito importantes e serão exploradas, também, em outro momento, mas para o início de uma compreensão essa é explicação o suficiente.

## Destrinchando essas Porqueiras

Para alguém que nunca viu C antes, isso pode parecer ridículo, apesar de ter "semelhança" com a língua inglesa:

```c
/* Imprime um caractere na Saída Padrão. */
#include <unistd.h>

void	ft_putchar(char c);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
```

Sabemos que vamos "incluir" algo de algum lugar... E que em algum momento estamos escrevendo algo, esse "c". Beleza.

Essa é uma vantagem das chamadas Linguagens de Programação, quando estamos escrevendo um código estamos, com disse antes: Utilizando uma Linguagem Formal p/ solucionar um problema, nosso problema nesse caso é simples: *"Imprimir um caractere na Saída Padrão."*

Quando falei que o "include" vai dizer ao Pré-Processador que algo será incluído no lugar dele eu falei sério: Nós vamos substituir toda aquela linha com um gigantesco bloco de indicativos que vai nos trazer outra coisa.

Essa outra coisa, ou uma coisa específica que queremos, é a função **write**, que recebe como argumento três coisas:

- um File Descriptor, representado por um Número Inteiro.
- um Ponteiro Nulo chamado "Buf".
- e uma Contagem, representado por um número, size_t (não me pergunte o que é isso ainda), chamado "Count".

E esse tal **void** do lado de **ft_putchar**? Include, e esse tal ft_putchar, aliás?

De cima pra baixo, e da esquerda para a direita, temos:

1. **a especificação do retorno da Função**, essa é a declaração do protótipo de uma função: Funções às vezes retornam alguma coisa, também possuem efeitos colaterais (como é o caso da que estamos falando sobre).
2. seu Nome, ou seja, sua rotulagem: ft_putchar, ou seja: Forty-Two, Put Char. 42 Bota Caractere, literalmente.
3. seu (ou seus) Argumento, que nesse caso é "c", de caractere.

Utilizamos uma Função que "importamos", a write, e não temos o uso de uma palavra reservada chamada return porque utilizamos *void.*

## Aprofundamento - Tipos de Dados

Caso você não saiba, seu Computador não sabe muita coisa. É importante que isso seja dito porque, apesar de Programação ser a Linguagem Mágica que submete as Máquinas à sua vontade, nossos servos são extremamente burros.

Eles, Computadores, não entendem muita coisa, na verdade eles só entendem duas: 0, ou 1. Isso, por serem valores binários, dois, são chamados criativamente de Dígitos Binários, ou Binary Digit, ou Bits. O conjunto de Oito bits é o que chamamos de Byte.

Show, então... o que isso significa?

Isso significa que tudo que escrevemos em pode, e de fato é, traduzido em Bytes. Existem estruturas primitivas, pequenos arremedos de significado, chamadas de Tipos de Dados... que nada mais são do que uma forma específica de darmos significado a esse conjunto de espaços compostos de 0s e 1s.

Tipos são isso: Espaços que, por motivos Arquiteturais, têm um significado quando lidos especificamente.

O menor de todos é o que chamamos de `char`, que é o que utilizamos para representar caracteres na Tabela ASCII... Mas isso é um pouco avançado, vamos falar um pouco mais sobre Binário.

Tudo, ou grande parte, pode ser representado por uma variação de 2 elevado a alguma coisa, ou seja: Power of 2...

O número `2` é, então, representado, de certa forma, por:
`00000010`, em 8 bits, 1 byte. Porque nosso Sistema Numérico é tipicamente posicional. Óbvio que nós não utilizamos 1 byte p/ números, temos muitos números... Nós usamos 4, para números inteiros.

`int` então tem 4 bytes... Mas pensemos da seguinte forma: Números podem ser positivos, mas também podem ser... negativos, logo nós utilizamos uma sacada um tanto quanto genial p/ representarmos números:

Em C, possuímos modificadores chamados `unsigned` que tornam todos os bits de um conjunto de bytes em espaços possíveis de representação numérica positiva, porque **metade dos valores de um conjunto numérico sinalado são especficiamente separados p/ valores negativos.**

A representação negativa de um número é seu complemento, ou seja, enquanto `2` é `00000010`, `-2` será `11111110`... O que pode não fazer sentido, mas é o que chamamos de **Complemento por Dois.**

O escopo de valores que um Tipo pode representar, portanto, vai ser justamente 2 elevado pelo seu número em bits, se `unsigned` e sem a possibilidade de representarmos números negativos, e `seu número em bits - 1` se `signed`.

Falamos de `int` e `char`, que são respectivamente 4, e 1. Mas também temos os tipos 