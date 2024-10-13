# C00: O que é um Programa?

Alguém muito mais inteligente que eu descreveu um programa da seguinte forma:

> _Um programa é um tipo especial de arquivo que contém todas as informações necessárias ao carregamento de uma aplicação em memória para execução..._

Aí a gente pode se perguntar: Quais são essas **_informações necessárias?_**

## Das Informações, e Estrutura de Memória

Beleza, agora vamos falar sobre algumas coisas bem interessantes que você pode ter ouvido falar antes, mas que são muito importantes e deverão ser pelo menos entendidas (não precisa compreender ainda, tem diferença): Sabemos que computadores só entendem 1s e 0s, e isso se chama Binário. Importante: 1 byte é composto por 8 bits, ou seja: Em um byte temos 8 binary digits...

O programa não sabe "exatamente onde" está. Logo, pro programa a memória é só isso: Um grande filete gigantesco de endereços que vai de "zero" até o hoizonte incrível com o por do Sol no fundo. Isso é o que chamamos de **_Espaço de Endereçamento, ou Address Space._**

Enfim, tudo em memória é representado em bytes... Programas dão significado a esse conjunto louco de espaços utilizando recursos como **Tipos de Dados,** que nada mais são que conjuntos arbitrários (às vezes por motivos de implementação e arquitetura de um sistema) de bytes... Os Tipos permitem que tragamos significado aos endereços e conjuntos de endereço. É por isso que escrevemos Programas: Para conseguir realizar manipulação de Informação armazenada/gerada em um ambiente virtualmente infinito de possibilidades.

Falamos um pouco mais sobre tipos de dados anteriormente, você deve (ou deveria) estar familiarizado c/ o que isso significa.

Só pra esclarecer: o acesso à uma seção de memória que não esteja necessariamente mapeada com memória física é um dos motivos de recebermos um **SEGV (Segmentation Violation, ou Violação de Segmento).**

### Da Violação de Segmento

Um exemplo de Violação de Segmento pode ser vista no código abaixo, que eu não vou adicionar na Seção de Códigos porque está deliberadamente errado:

```c
void    change_in(char *s, int i)
{
        s[i] = 'C';
}

int     main(void)
{
        char    *t = "Hello!\n";

        change_in(t, 0);
}
```

Se você executar o código no **GDB - GNU Debugger** você vai ver o seguinte retorno:

```bash
Starting program: /nfs/homes/kobamaru/main 
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".

Breakpoint 1, main () at seg_t.c:20
20		char	*t = "Hello!\n";
(gdb) n
22		change_in(t, 0);
(gdb) n

Program received signal SIGSEGV, Segmentation fault.
change_in (s=0x555555556004 "Hello!\n", i=0) at seg_t.c:15
15		s[i] = 'C';
```

Basicamente, o que aconteceu foi: Eu tentei a partir da função `change_in` fazer a alteração de valor do índice 0 do ponteiro `t`... Beleza, muita coisa, mas basta entender que o `character pointer t` guarda uma `string constante`...uma **String Literal.**

### As Seções de Memória

Expandindo um pouco essa ideia: quando um Programa é "gerado" ele cataloga/organiza os dados nele dispostos em **Seções da Memória**, algumas delas são:

- **Text:** As intruções do programa, o código em si.
- **ROData:** Read-Only Data, ou seja: Constantes e Literais (como Strings).
- **Data:** Onde Variáveis Globais Inicializadas ficam.
- **BSS:** Onde Variáveis Globais Não-Inicializadas estão, seu valor é automaticamente definido p/ zero.
- **Heap:** Memória ocupada pela execução de malloc (Memory Allocation) ou new, no caso de C++. **Cresce p/ Cima.**
- **Stack:** Variáveis Locais e Retornos de Função. **Cresce p/ Baixo.**

Nesse contexto, ainda temos uma Seção que é específica p/ **Bibliotecas Compartilhadas**, ou seja: Bibliotecas que são divididas entre vários processos.

A partir disso, toda Seção tem permissões diferentes, seja de leitura/escrita/execução... ou uma Combinação disso. Importante salientar: **Bibliotecas Compartilhadas em si também possuem suas próprias Seções de Memória.**

### Explorando um pouco as regiões

No programa abaixo, conseguimos ter uma ideia geral sobre o endereçamento das seções, esclarecendo um ponto: Endereços de Memória são escritos em Hexadecimal (outra base numérica).

```c
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
```

Quando você compilar esse programa utilizando seu CC, você vai ter algo parecido, não idêntico, a isso aqui:

```bash
DATA:           &a      = 0x0x55d76ce6d010.
BSS:            &b[0]   = 0x0x55d76ce6d040.
RO-DATA:        hello   = 0x0x55d76ce6d018.
STACK:          &c      = 0x0x7ffc307b5edc.
HEAP:           &p      = 0x0x55d76e7a42a0.
TEXT:           main    = 0x0x55d76ce6a1a9.
```

Pronto, você sabe o endereço "mais ou menos" próximo de todas as Seções envolvidas na execução do seu programa, incluindo a do próprio **Texto** do programa, a _TEXT_.

Mas por que isso é importante? Porque assim nós conseguimos ter uma visão mais clara de como o programa "enxerga" sua estrutura de organização de recursos.

O Espaço de Endereçamento é próprio de cada processo executado na máquina, logo a alteração dele é própria: Um processo não altera dados no Espaço de Endereçamento de outro.

### Mas e o tal do Programa?

Desenvolvendo um pouco o entedimento: O programa é, justamente, isso: _um arquivo especial contendo as informações necessárias à sua execução._ O arquivo de um programa vai conter, então: As instruções dadas ao Computador, na seção de TEXT; os Dados Inicializados, ou seja: Variáveis e Constantes que estarão alocadas em DATA e RODATA; A relação de Bibliotecas Compartilhadas que o programa precisa p/ executar...

Além de seções inicializadas em Zero, até terem valores alocados lá, ou seja: BSS, HEAP, STACK... tudo isso que deve ser organizado antes da lista de Símbolos Definidos e Indefinidos, que são suas variáveis e nomes de função que terão significado após o processo de Linkagem/Ligação.

O processo de compilação é um "fluxo" multifacetado de vários passos cujo primeiro deles é o Pré-Processamento. Quando a gente digita esse tal gcc -Wall -Wextra -Werror, o processo todo é feito de uma vez só, cuspindo o "a.out" no final.

### Explorando a Compilação

De maneira geral, o processo de *"Compilação"* é algo parecido com isso:

1. Um arquivo `.c` entra.
2. O Pré-Processador vai varrer as `define` e `include`.
3. Depois, gerando um `.i`, ele vai jogar p/ o Compilador.
4. O Compilador entregará um `.s` com as instruções de `Assembly`... Junto c/ algo chamado Otimizador (que em geral faz parte do Compilador), que é quem vai consertar nossos códigos horríveis.
5. Cuspindo, no final, algo chamado `Object File` quando geramos um `.o`... Isso é **bem importante** por motivos que veremos bem lá na frente.

Existem coisas no meio, como por exemplo:

- Conseguimos criar um arquivo de arquivos, chamado *archive file*, que é uma coleção de `.o` com algo parecido com um **índice remissivo** p/ as definições que fizemos no decorrer do desenvolvimento de nossas soluções... Essa é uma das tarefas que temos aqui na École. **Essas são as Libs que chamamos de Estáticas.**

- Existem em nossos computadores coisas chamadas de *Bibliotecas Dinâmicas, ou Compartilhadas.* São os `.so, .sl, .dll`, que são compartilhados de maneira ampla pelo Sistema, e são compiladas uma só vez na inicialização do Sistema. Elas são interessantes porque **são utilizadas por todos os processos do Sistema de forma compartilhada.**

### Beleza, vamos fazer diferente

Temos um programa:

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

Se nós pegarmos esse programa e compilarmos ele da seguinte forma:

```bash
gcc -Wall -Wextra -Werror -E ft_hello_world.c > hello.i
```

Nós temos algo parecido com isso aqui:

```c
# 1 "ft_hello_world.c"
...
# 26 "/usr/include/unistd.h" 2 3 4
...
# 358 "/usr/include/unistd.h" 3 4
extern int close (int __fd);

extern ssize_t write (int __fd, const void *__buf, size_t __n)
    __attribute__ ((__access__ (__read_only__, 2, 3)));
...
# 14 "ft_hello_world.c" 2


# 15 "ft_hello_world.c"
void ft_putchar(char c);

int main(void)
{
        char *s;

        s = "Hello World\n";
        while (*s)
                ft_putchar(*(s++));

        return (0);
}

void ft_putchar(char c)
{
        write(1, &c, 1);
}

```

Existe muito mais coisa aqui? Existe, com certeza, você pode ver em [ft_hello_world.i](/C00_Content/codes/ft_hello_world.i) se te for importante. Mas o ponto principal aqui é:

**Quando nós realizamos o pré-processamento, o que acontece é a inclusão de uma referência à uma Biblioteca Pré-Existente, essa é a linkagem que a gente se refere.**

É por isso, por exemplo, que é uma prática ruim a inclusão de Bibliotecas Não-Utilizadas...

Se travarmos no processo de Compilação, quando geramos um `Assembly Code`, temos algo assim:

```assembly
	.file	"ft_hello_world.c"
	.text
	.section	.rodata
.LC0:
	.string	"Hello World\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	leaq	.LC0(%rip), %rax
	movq	%rax, -8(%rbp)
	jmp	.L2
.L3:
	movq	-8(%rbp), %rax
	leaq	1(%rax), %rdx
	movq	%rdx, -8(%rbp)
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	movl	%eax, %edi
	call	ft_putchar
.L2:
	movq	-8(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L3
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.globl	ft_putchar
	.type	ft_putchar, @function
ft_putchar:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, %eax
	movb	%al, -4(%rbp)
	leaq	-4(%rbp), %rax
	movl	$1, %edx
	movq	%rax, %rsi
	movl	$1, %edi
	call	write@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	ft_putchar, .-ft_putchar
	.ident	"GCC: (Ubuntu 10.5.0-1ubuntu1~22.04) 10.5.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
```

Parabéns, você provavelmente acaba de ler seu primeiro código em Assembly. É então, depois desse `.s` gerado, que o Assembler vai gerar um `.o`, que **não é um executável ainda,** porque vai ser ainda ligado a outras bibliotecas como a `libc.a`, ou melhor dizendo `libc.so`.

### Carregando um Programa em Memória

> *Tudo bem, no final das contas alguma coisa acontece p/ o que*
> *eu tenho escrito, e depois traduzido, na forma de uma coisa*
> *mágica chamada **Programa** ser "entregue" p/ **Memória**, certo?*

Isso é o que você deve estar pensando! Ou talvez você esteja pensando em buscar alternativas mais frutíferas de carreira, talvez no Setor de Construção Civil, o ofício de pedreiro, afinal, sempre será necessário mesmo com o advento das Inteligẽncias Artificiais...

**A respota é: Existe uma coisa chamada Loader...** ele é um programa que vai conseguir realizar justamente a *ligação do que o seu programa precisa c/ as bibliotecas dinâmicas necessárias p/ sua ligação aos Processos em Execução.*

1. Ele vai alocar espaço de memória p/ todas as Seções necessárias.
2. Carrega na memória o Executável e as Bibliotecas Compartilhadas.
3. E também vai resolver qualquer valor p/ apontar para as funções e variáveis corretas nas Bibliotecas Compartilhadas...

O ponto de entrada do programa é o que é chamado de `_start`, que vai, então, chamar `init()` em todas as bibliotecas, inicializando os construtores estáticos... Aí sim, nosso programa entrará em `main()`.

É, então, tecnicamente incorreto dizer que o primeiro ponto de entrada do programa é `main()` já que na verdade a entrada acontece em `_start`, que é o **ponto de entrada do programa.**

## Referências

- **_[Introduction to Systems Programming](https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/)_** — Gustavo A. Junipero: Sobre programas, memória, pré-processamento e algumas outras coisas.
- **_[The C Programming Language](https://www.amazon.com/Programming-Language-2nd-Brian-Kernighan/dp/0131103628)_** — Brian Kernighan & Dennis Ritchie: Pra tudo, essa é a Bíblia de C.
- **_[CS50, Week 01, C](https://cs50.harvard.edu/x/2024/weeks/1/)_** — Harvard & David Malan: Para alguns conceitos específicos.