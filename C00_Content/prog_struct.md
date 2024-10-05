# C00: O que é um Programa?

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