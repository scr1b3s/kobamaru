# C00: Intro. a Linguagem C

Dois caras muito inteligentes disseram uma vez que a única forma de se aprender uma linguagem de programação é escrevendo nela, e o primeiro programa costuma ser o mesmo para todas as linguagens... Eles falavam do "Hello World".

Na École 42 nosso "Hello World" tem uma letra apenas, e se chama **ft_putchar**:

```c
/* Imprime um caractere na Saída padrão. */
#include <unistd.h>

void	ft_putchar(char c);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
```

Lendo de cima para baixo, nós temos algumas coisas importantes a serem levadas em consideração... E uma delas com certeza é aquele **"#include"** flutuando.

1. Resumidamente, o **#include** indica ao Pré-Processador de C que algo deve ser incluído em seu lugar antes do processo de Compilação acontecer.

Tudo bem, agora temos mais algumas perguntas: O que é um *Pré-Processador* e o que é *Processo de Compilação*?

- Pré-Processamento quer dizer que um processo, frequentemente a inclusão de um arquivo de cabeçalho ou a definição de algo como, por exemplo, um Macro, é feita *ANTES* da Compilação.
- Compilação, por sua vez, é o processo e se traduzir Código-Fonte, aquilo que nós escrevemos, em Código de Máquina, os binários que um computador (a Unidade de Processamento Central) consegue entender.

Isso dito, logo em seguida o "<unistd.h>" é o indicativo do cabeçalho que precisamos incluir. Nós sabemos disso porque digitando `man 2 write`, ou seja: Manual, Capítulo 2, Write, especificamente a função write, nos indica que ao mesmo tempo:

`write - write to a file descriptor`
`#include <unistd.h>`

Ou seja: A função **_write_** **escreve em um file descriptor... e para usá-la importamos utilizando unistd.h como argumento de include.**

Respondemos algumas perguntas, mas criamos outras, com certeza:

- O que são "File Descriptors"?
- E que significa "escrever" em um?



Se você é uma pessoa atenta, você deve ter percebido que eu disse antes **"programa"**... Mas nós escrevemos o que chamamos de **"função".**