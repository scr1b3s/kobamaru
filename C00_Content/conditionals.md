# C00: Condicionais, ou E Se?

Bom, mantendo a linha de raciocínio dos Fluxos de Controle: Quando pensamos, nós temos algumas condicionais... **Se tal coisa acontecer, eu vou agir de tal maneira.** Tudo bem que nem sempre conseguimos agir da forma que esperamos, porém, em Computação nós conseguimos essa proeza porque quem age é o Computador!

E essa tradução é bem direta: Se, ou `if`, é exatamente o que usamos, por exemplo: Se eu quiser identificar que um número é par, ou ímpar, eu vou escrever algo parecido com isso:

```c
#include <unistd.h>

void    ft_odd_even(int n)
{
    if (n % 2 == 0)
        write(1, "Par", 3);
    else
        write(1, "Ímpar", 5);    
}
```

Basicamente:

1. **Se módulo da divisão do número por 2 for 0**, ele é Par.
2. **Se não,** ele só póde ser Ímpar.

Algo bem direto, e nos introduz uma nova forma de obter dados a partir de operações matemática: o Módulo `%`, que nos dá o resto da divisão de um número por outro. Logo, temos a divisão, que é expressa por `/`, simples. Multiplicação também: `*`.

Um bom apontamento: Existe uma diferença entre realizar a atribuição, ou seja: `=` e utilizar um Operador de Comparação como por exemplo o **Igual a**, `==`, o primeiro diz respeito a algo ser atribuído da Esquerda p/ Direita, enquanto o segundo é comparar e perguntar se algo é igual a outra coisa.

### Existem outros operadores de comparação?

Claro que sim, mas os principais, os que vamos manter em mente agora são:

- Igual a: `==`.
- Diferente de: `!=`.

Esse retorno é dado por algo chamado **"Booleano"** que vem de *George Boole*, um Matemático Inglês que criou o que ficou conhecido como *Lógica Booleana.* Algo que você vai, provavelmente, ver na Universidade/Faculdade, e não aqui (pelo menos não por enquanto, talvez eu precise/escreva algo sobre quando entrarmos em operações bit-a-bit... Não me pergunte sobre isso ainda).

É suficiente saber que, assim como na nossa cabeça louca e sem-limites, existe em `C` o conceito de **Verdadeiro** e **Falso**... Só que eles são expressos em `1` e `0`, respectivamente. O que quer dizer que o retorno disso aqui: `n % 2 == 0` se `n == 2` é 1. Enquanto, se `n == 1`, vai ser 0.

## Beleza, você consegue aplicar esses dois conceitos?

Uma boa forma de conseguirmos entender um pouco melhor essa parada toda é... Com a implementação de um algoritmo que nos permita algo assim, certo? Então vamos lá:

O código abaixo é um algoritmo que conta palavras, palavras são sucessões de caracteres alfanuméricos separados por espaços e pelo começo e fim de uma sucessão de caracteres:

```c
#include <stdio.h>

int     count_words(char *s);

int     main(int ac, char *av[])
{
        int     count = 0;

        if (ac == 2)
        {
                count = count_words(av[1]);
                printf("%d.", count);
        }
        printf("\n");

        return (0);
}

int     count_words(char *s)
{
        int     words = 0, i = 0, in = 0;

        i = 0;
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
```

Beleza, vamos por partes...

A gente utiliza primeiro dois dos argumentos "nativos" da função main(): `argc`, e `argv`. Respectivamente: *Argument Count* e *Argument Value*... O que é auto-explicativo, acho que o maior problema que as pessoas têm com esses dois argumentos é justamente sua natureza e ela pode ser explicada c/ seus nomes: **um conta quantos argumentos são passados na execução desse programa**, e **o outro armazena seus valores**.

Agora, a parte difícil do segundo, se "como ele armazena?" eventualmente vamos falar disso, mas basta saber que o `argv` é um ponteiro de ponteiros. Sim.

Então, nós declaramos uma variável chamada `count` de tipo inteiro, p/ justamente armazenar a quantidade de palavras passada... E condicionamos a contagem à segunda entrada de `argc`, já que a primeira é o nome do programa.

Aí, sim, atribuímos o valor da execução da função que queremos, `count_words`, p/ `count`.

### A Count_Words

Escolhi utilizar 3 variáveis, todas do tipo `int`, uma é o nosso retorno, o número de palavras (`words`), outra é o iterador que utilizaremos p/ percorrer o que chamamos de `string`, que é a palavra passada... eventualmente vai fazer mais sentido, eu juro, e por fim, uma que será utilizada como `boolean` p/ determinarmos se estamos em uma palavra, ou não...

É um pouco engraçado de pensar, mas:

1. Pensemos no argumento "palavra":
   1. Vamos percorrê-lo de maneira consistente, já que uma vez identificando a letra "p", `in` será dada por 1, e vamos atualizando nossa posição até o fim da palavra.
2. Agora, se o argumento for " ", ou seja: **nada, vazio:**
   1. O valor de `in` de fato será `0`, mas nunca entraremos na condição `!in` porque ela depende de não termos entrado na primeira condição: `s[i] == ' '`, ou seja: nossa letra não ser um espaço.

Com essa função e programa ainda conseguimos introduzir alguns outros conceitos... como por exemplo: `else if`, que é uma peça-chave p/ condicionais mais interessantes e multi-facetadas: `else if` será executado apenas como condição adicional de `if`, uma segunda, terceira... verificação.

`Else if` não é executado se `if` tiver.