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

Isso é só verdade: Os exercícios são do mais fácil para o mais difícil, e as listas que você recebe durante a Piscine são temáticas, cada uma segue um conjunto de premissas que deve ser corretamente assimililada e aplicada... Mas **nem todo exercício é criado da mesma forma.**

O que isso quer dizer: Nem todo exercício precisa ser feito, nem toda Lista precisa ser concluída em sua completude. Esse é um aviso: eu não vou fazer todos os exercícios, você está formalmente convidado a submeter seu código **junto com os testes que o validem** para este repositório a partir de um Pull Request, já que eu me recuso a fazer certos exercícios por questões de princípios (eu não sei fazer).

### Você só submeterá uma função main() se pedirmos um programa

Essa instrução é especialmente importante, mas você não sabe disso ainda: Programas podem ser executados com argumentos e executam algo que geralmente vai ser disposto no stdout, e/ou no stderr... Isso também não te diz muita coisa, mas vai logo mais.

Existem diferenças teóricas/conceituais entre Programas e Funções, isso será melhor explorado ao longo das disposições das Listas, mas... Leve isso em consideração.

### Seu código será complicado utilizando as flags: -Wall -Wextra -Werror usando cc.

