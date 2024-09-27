# Kobayashi Maru
> *Kobayashi Maru is a training exercise in the Star Trek franchise designed to test the character of Starfleet Academy cadets by placing them in a no-win scenario. 
> The nominal goal of the exercise is to rescue the civilian fuel ship Kobayashi Maru, which is damaged and stranded in neutral territory between the Federation and the Klingon Empire. The cadet being evaluated must decide whether to attempt to rescue the Kobayashi Maru—endangering their ship and crew—or leave the Kobayashi Maru to certain destruction.
> If the cadet chooses to attempt a rescue, an insurmountable enemy force attacks their vessel. By reprogramming the test, James T. Kirk became the only cadet to overcome the Kobayashi Maru simulation.*

Como estudante da École 42, o exercício de treinamento "Kobayashi Maru" fala muito comigo, em um nível pessoal. É pressuposto que nós caíremos no Black Hole, e que isso é, de certa forma, inevitável. O que é verdade.

Esse projeto é um esforço individual inicialmente que eu espero poder ser um esforço coletivo no futuro, o objetivo aqui é que o Kobayashi não morra. Nós somos Kobayashi.

A ideia é que nenhum Cadete fique para trás.

## Das Introduções

Todo projeto na École 42 é acompanhado de um *.pdf*, esse arquivo inclui, sempre, um capítulo chamado "Instruções", as Instruções dos Exercícios da Piscine são muito interessantes porque elas indicam um processo de formação pré-suposto, Pré e Suposto separados:

- **Pré**, porque antes de aplicá-los você precisa conhecê-los ou estar familiarizado com.
- **Suposto**, porque você será cobrado/avaliado a partir de algo que é dado. Seja arbitrário (escolhido sem muita consideração por uma decisão pessoal) ou não.

### Você deve seguir os Procedimentos de Submissão em todos os Exercícios

Qualquer exercício, projeto, aplicação, na 42 tem um conjunto de requerimentos específicos que deverá ser seguido, os Exercícios da Piscine têm Procedimentos simples, em geral devem ser incluídos numa pasta própria, não podem conter uma função proibida, que é identificada a partir de uma coisa chamada _**Análise Estática**_.

Em geral os Procedimentos de Submissão servem pra determinar que você vai andar na linha, que sua Entrega será condizente com requisitos de Qualidade e Consistência, ou seja: Que você é capaz de entregar algo seguindo requisitos, sem extrapolar, sem diminuir, você sabe ler.

### Sobre a "Moulinette"

Você pode nunca ter ouvido falar de uma coisa chamada _**Testes Unitários**_ na vida, o que é super válido, e normal. Mas não existe muito no programa "Moulinette" fora um conjunto de Testes Unitários que garante que a sua Submissão condiz com os requisitos do Projeto, de verdade.

Não me entenda mal: Você pode antropoformizar programas de computador, não é atoa que falamos que "O computador tá puto comigo" quando a máquina trava, mas a Moulinette não é nada além disso: Testes Unitários. Se você escreve os seus da forma correta, não existe surpresa.

Não tem uma pessoa lendo seu código, ele provavelmente quebrou porque, ou você não sabe ler, ou você leu errado, ou você não sabe o que está fazendo... E eu simpatizo com isso, em geral não sabemos o que estamos fazendo.

**Via de regra:**

- Seja o mais minucioso possível, ou seja: saiba o que está fazendo quando estiver escrevendo seu código.
- Familiarize-se o mais rápido possível com o Desenvolvimento e Implementação de Testes Unitários e execute-os de forma consitente. Esse guia busca em um Apêndice conseguir introduzir essa questão.

Desse jeito, não haverão surpresas desagradáveis e você não vai precisar argumentar com seu colega de classe que "A Moulinette aceita assim", **porque a Moulinette não aceita nada, você que não sabe o porquê.**

### Os exercícios são distribuídos cuidadosamente levando em consideração ordem de dificuldade. Não consideraremos um exercício difícil realizado corretamente se um fácil não for funcional

Isso é só verdade: Os exercícios são do mais fácil para o mais difícil, e as listas que você recebe durante a Piscine são temáticas, cada uma segue um conjunto de premissas que deve ser corretamente assimilada e aplicada... Mas **nem todo exercício é criado da mesma forma.**

O que isso quer dizer: Nem todo exercício precisa ser feito, nem toda Lista precisa ser concluída em sua completude. Esse é um aviso: eu não vou fazer todos os exercícios, você está formalmente convidado a submeter seu código **junto com os testes que o validem** para este repositório a partir de um Pull Request, já que eu me recuso a fazer certos exercícios por questões de princípios (eu não sei fazer).

### Você só submeterá uma função main() se pedirmos um programa

Essa instrução é especialmente importante, mas você não sabe disso ainda: Programas podem ser executados com argumentos e executam algo que geralmente vai ser disposto no stdout, e/ou no stderr... Isso também não te diz muita coisa, mas vai logo mais.

Existem diferenças teóricas/conceituais entre Programas e Funções, isso será melhor explorado ao longo das disposições das Listas, mas... Leve isso em consideração.

### Seu código será complicado utilizando as flags: -Wall -Wextra -Werror usando cc

Algumas perguntas devem surgir nesse momento, umas, eu consigo responder, outras eu vou desenvolver linhas de racicínio que precisão de referências, cujas quais estarão no final desse "sub-capítulo", ou "sub-tópico."

Bom, vamos lá:

#### O que é "cc"?

A resposta mais simples é: Um **_Compilador._** Mas ela, obviamente, não nos diz muito... Para conseguirmos avançar, é preciso dizer, brevemente, que no processo de formação lidamos primariamente com uma linguagem de programação antiga (não a mais antiga, nem a primeira, nem "não mais utilizada") chamada C.

C é uma Linguagem Compilada, o que significa que, para conseguirmos executar um programa em C precisamos passar pelo **_Processo de Compilação..._**

Vamos fechar o raciocínio: Para executar um programa em C, eu preciso compilar meu código... Compilar é, então, transformar o código que eu escrevo (código-fonte, a fonte do que está sendo transformado) em algo diferente.

Computadores só entendem 0s e 1s. Pelo fato de só conseguirmos expressar coisas em dois dígitos, nós dizemos que computadores só entendem _Binário_ (binary digit - binary).

Então, Compilação é transformar código-fonte em um binário que pode ser executado. Um Compilador, por sua vez, é um programa que consegue, foi escrito, exatamente com esse propósito.

#### Incrível, mas isso não explica o que cc é

Sim, de fato, não explica. CC, ou "C Compiler", costuma ser uma forma genérica de nos referirmos ao Compilador Nativo de um Sistema Operacional, comum em Sistemas Operacionais Baseados em UNIX (o GNU/Linux, ou macOS).

No final das contas, seu Terminal (a tela preta que você usa para escrever seus códigos, manipular arquivos e dificultar a própria vida) tem um "link simbólico", tipo específico de arquivo que é um **_ponteiro,_ uma referência**, para um outro arquivo ou diretório, para um Compilador nativo, que é determinado pela implementação do seu sistema... A gente consegue confirmar isso da seguinte forma:

```shell
ls -l /usr/bin/cc
# isso permite que listemos o link simbólico em /usr/bin/cc.
# você deve ver algo parecido com isso:
lrwxrwxrwx 1 root root 20 Jun 20 22:10 /usr/bin/cc -> /etc/alternatives/cc
# que basicamente quer dizer que /usr/bin/cc "aponta" p/ /etc/alternatives/cc
ls -l /etc/alternatives/cc
# vai, provavelmente, te mostrar algo parecido com isso:
lrwxrwxrwx 1 root root 12 Jun 20 22:10 /etc/alternatives/cc -> /usr/bin/gcc
# parabéns, seu Terminal traduz cc p/ gcc.
```

#### Caramba, e o que isso significa?

Não muita coisa, a não ser que você identifique alguma particularidade entre os Compiladores mais comuns (clang e gcc) que seja importante ser levada em consideração, mas é importante saber o que se está fazendo.

Não é interessante tentar trocar o Compilador Nativo, então eu não vou explorar essa possibilidade. Para saber a versão do gcc ou clang da sua máquina você pode digitar: `<compiler> --version` a Flag `--version` permite que verifiquemos a versão de um programa, normalmente.

#### Sobre -Wall, -Wextra, -Werror

O que essas flags fazem é, basicamente, "Endurecer", "Hardening" de fato, o processo de Compilação... Vamos desenvolver um pouco mais o que significa Compilar um código:

O Compilador precisa fazer o processamento do seu código, isso é feito "de cima para baixo", por isso nós fazemos algumas coisas antes de escrevermos nosso código, e o que isso significa é que:

1. O compilador entende de maneira gramatical se seu código está escrito de maneira que "faça sentido em C.

Então, há um jeito certo de escrever C... isso deveria ser pressuposto, já que **_Linguagens de Programação são Linguagens Formais utilizadas na prova de Problemas Computacionais._**

Além disso:

2. O compilador consegue inferir error semânticos, erros de sentido de construção frasal.

A primeira é básica: O que você escreve tem que fazer sentido em uma Linguagem, agora a segunda é **variável.** E é nesse ponto que as Flags e o conceito de Hardening entram:

> *The objective of compiler options hardening is to produce application binaries (executables) with security mechanisms against potential attacks and/or misbehavior. — OpenSSF*

C é uma linguagem bastante aberta, bem livre, bem Punk Rock... Isso causa problemas, alguns deles envolvem a relação expansiva que a linguagem tem com o manejo de memória de maneira direta: Espera-se que você saiba, minimamente, o que está fazendo. E isso é péssimo, porque **somos, todos, meio burros.**

A solução para isso é relativamente simples: Hardening significa condicionar seu código à verificações especificamente desenvolvidas para conseguir detectar erros "simbólicos", na construção das suas frases, nas linhas de raciocínio que seu código gera.

Pense que com Hardening nós temos um Professor de Redação muito rigoroso do nosso lado analisando basicamente qualquer declaração que fizermos:

- Por que essa variável foi declarada, mas nunca inicializada?
- Você precisa apagar essa variável se não for usar...

Nós temos outros vários programas que fazem coisas parecidas, e eu os introduzirei a medida que a necessidade for surgindo... Mas basta dizer isso, inicialmente.

Agora, usamos o `-Werror` justamente porque assim tornamos **qualquer aviso que as outras flags nos dêem em um erro de compilação, porque eles simbolizam falhas lógicas/de implementação na construção do nosso código.**

**Referências:**
- [CPP/C++ Compiler Flags and Options - caiorss](https://caiorss.github.io/C-Cpp-Notes/compiler-flags-options.html) - Sobre Flags e Compilação.
- [Compiler Options Hardening Guide for C and C++ - Open Source Security Foundation (OpenSSF)](https://best.openssf.org/Compiler-Hardening-Guides/Compiler-Options-Hardening-Guide-for-C-and-C++.html) - Sobre Compilação, o que Hardening no contexto de Compilação Significa... E algumas coisas que eu não lembro agora.