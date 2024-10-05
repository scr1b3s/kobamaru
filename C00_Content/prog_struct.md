# C00: Intro. a Linguagem C

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

Essas e outras perguntas que você provavelmente deve ter não serão respondidas agora. Ao invés disso eu levantarei mais questões! Acostumar-se com a completa desesperança intelectual é um aspecto fundamental da formação.

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

## Sobre Compilação, Algoritmos, e as coisas no meio

Com um programa em mãos, conseguimos ter uma visão um pouco mais clara sobre não só o que é o Pré-Processamento, mas também o que significa o Include nesse contexto... Mas antes, como sempre, a gente consegue voltar um pouco atrás:

Funções e Programas são quase a mesma coisa. Tudo bem, eles "claramente" **não são**, até porque se fossem teriam o mesmo nome... Mas o ponto principal é que ambos são a implementação de Conhecimento Declarativo de maneira Imperativa na forma de uma Sucessão de Passos Lógicos para a Realização de uma Tarefa expressos a partir de uma Linguagem Formal.

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

## E qual a diferença disso para um Programa? Ou... o que é um Programa?

Alguém muito mais inteligente que eu descreveu um programa da seguinte forma:

> _Um programa é um tipo especial de arquivo que contém todas as informações necessárias ao carregamento de uma aplicação em memória para execução..._

Aí a gente pode se perguntar: Quais são essas **_informações necessárias?_**

### Das Informações, e Estrutura de Memória

Beleza, agora vamos falar sobre algumas coisas bem interessantes que você pode ter ouvido falar antes, mas que são muito importantes e deverão ser pelo menos entendidas (não precisa compreender ainda, tem diferença): Sabemos que computadores só entendem 1s e 0s, e isso se chama Binário. Importante: 1 byte é composto por 8 bits, ou seja: Em um byte temos 8 binary digits...

O programa não sabe "exatamente onde" está. Logo, pro programa a memória é só isso: Um grande filete gigantesco de endereços que vai de "zero" até o hoizonte incrível com o por do Sol no fundo. Isso é o que chamamos de **_Espaço de Endereçamento, ou Address Space._**

Enfim, tudo em memória é representado em bytes... Programas dão significado a esse conjunto louco de espaços utilizando recursos como **Tipos de Dados,** que nada mais são que conjuntos arbitrários (às vezes por motivos de implementação e arquitetura de um sistema) de bytes... Os Tipos permitem que tragamos significado aos endereços e conjuntos de endereço. É por isso que escrevemos Programas: Para conseguir realizar manipulação de Informação armazenada/gerada em um ambiente virtualmente infinito de possibilidades.

Só pra esclarecer: o acesso à uma seção de memória que não esteja necessariamente mapeada com memória física é um dos motivos de recebermos um SEGV (Segmentation Violation).

Expandindo um pouco nossa ideia, quando um Programa é "gerado" ele cataloga/organiza os dados nele dispostos em **Seções da Memória**, algumas delas são:

- **Text:** As intruções do programa, o código em si.
- **ROData:** Read-Only Data, ou seja: Constantes e Literais (como Strings).
- **Data:** Onde Variáveis Globais Inicializadas ficam.
- **BSS:** Onde Variáveis Globais Não-Inicializadas estão, seu valor é automaticamente definido p/ zero.
- **Heap:** Memória ocupada pela execução de malloc (Memory Allocation) ou new, no caso de C++. **Cresce p/ Cima.**
- **Stack:** Variáveis Locais e Retornos de Função. **Cresce p/ Baixo.**

Mas por que isso é importante? Porque assim nós conseguimos ter uma visão mais clara de como o programa "enxerga" sua estrutura de organização de recursos. O Espaço de Endereçamento é próprio de cada processo executado na máquina, logo a alteração dele é própria: Um processo não altera dados no Espaço de Endereçamento de outro.

### Mas e o tal do Programa?

Desenvolvendo um pouco o entedimento: O programa é, justamente, isso: um arquivo especial contendo as informações necessárias à sua execução. O arquivo de um programa vai conter, então: As instruções dadas ao Computador, na seção de TEXT; os Dados Inicializados, ou seja: Variáveis e Constantes que estarão alocadas em DATA e RODATA; A relação de Bibliotecas Compartilhadas que o programa precisa p/ executar...

Além de seções inicializadas em Zero, até terem valores alocados lá, ou seja: BSS, HEAP, STACK... tudo isso que deve ser organizado antes da lista de Símbolos Definidos e Indefinidos, que são suas variáveis e nomes de função que terão significado após o processo de Linkagem/Ligação.

O processo de compilação é um "fluxo" multifacetado de vários passos cujo primeiro deles é o Pré-Processamento. Quando a gente digita esse tal gcc -Wall -Wextra -Werror, o processo todo é feito de uma vez só, cuspindo o "a.out" no final.

Mas, se nós ao invés disso, fizermos: 

## Referências

- **_[Introduction to Systems Programming](https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/)_** — Gustavo A. Junipero: Sobre programas, memória, pré-processamento e algumas outras coisas.
- **_[The C Programming Language](https://www.amazon.com/Programming-Language-2nd-Brian-Kernighan/dp/0131103628)_** — Brian Kernighan & Dennis Ritchie: Pra tudo, essa é a Bíblia de C.
- **_[CS50, Week 01, C](https://cs50.harvard.edu/x/2024/weeks/1/)_** — Harvard & David Malan: Para alguns conceitos específicos.