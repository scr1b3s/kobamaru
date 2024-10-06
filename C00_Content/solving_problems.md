# C00: As Muitas Formas de Se Solucionar um Problema

Eu resolvi escrever esse breve preâmbulo por um motivo muito simples: **Problemas não têm jeito certo de serem solucionados, eles só têm como serem... O importante é a solução.** Óbvio, esse é um debate bastante amplo cuja exaustão não será dada em uma postagem simples em um Arquivo Markdown escrito por um Babaca do GitHub, isso é posto.

Porém, é bem possível de se dizer que: **Assim como nem todo problema/exercício é criado igual, nem toda solução é.** O que isso significa é bem simples: Se eu te digo para imprimir todas as letras do alfabeto na tela você **pode** escrever da seguinte forma:

```c
write(1, "abcdefghijklmnopqrstuvwxyz", 26);
```

O resultado vai ser exatamente o mesmo de se escrever algo como o que vimos antes:

```c
char	c;

c = 'a';
while (c <= 'z')
{
    write(1, &c, 1);
    c++;
}
```

Mas no final das contas, um resultado é a **materialização do aprendizado a partir da manifestação de uma solução robusta.** É a aplicação daquilo que foi aprendido. Conhecimento. Existem claras diferenças que no final das contas vão dizer muito sobre o que você sabe e sua noção de solução possível, das fronteiras do seu Conhecimento e de como você consegue aplicá-lo na Resolução de um Problema.

Posso estar romantizando e sendo um pouco apelativo na minha defesa, sim, mas o objetivo final desse projeto é justamente permitir que esse tipo de conhecimento seja consolidado por mim e seja disseminado não apenas p/ dentro, mas também p/ fora:

Não é porque você resolveu um problema que você sabe, o que não invalida sua solução, de forma alguma... **Não existem respostas certas, mas existem respostas que dizem mais do que outras.**