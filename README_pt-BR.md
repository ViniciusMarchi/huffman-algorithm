<p align="center">
  <a href="./README.md">Versão em Inglês </a>
  <span>:us:</span>
</p>



# Tabela de conteúdos
   * [Introdução](#Introdução---algoritmo-de-Huffman)
   * [Funcionalidades](#Funcionalidades)
   * [Como utilizar](#Como-utilizar)
      * [Compilando arquivos](#Compilando-arquivos) 
      * [Executando o algoritmo](#Executando-o-algoritmo)


# Introdução - Algoritmo De Huffman
Implementação do Algoritmo de compressão Huffman em C++

Algoritmo de Huffman utiliza um método de compressão de arquivos baseado na probabilidade de ocorrencia dos caracteres.

# Funcionalidades
Nessa implementação o algoritmo de Huffman é regido pelo conceito de busca digital, descrito por uma árvore digital (Digital Search Tree), oque permitirá a compressão e descompressão de arquivos de texto (`.txt`).

Tal implementação recebe um arquivo como entrada, um arquivo `.txt` que será comprimido, e gera dois arquivos como saída:
* `comprimido.txt`: representa o arquivo comprimido, em binário. Esse arquivo é resultante da execução do algoritmo de Huffman sobre o arquivo de **entrada**.
* `descomprimido.txt`: representa o arquivo descomprimido. Esse arquivo é o resultado da aplicação do algortimo de Huffmam sobre o arquivo `comprimido.txt`. Ou seja, é a descompressão. Esse arquivo funciona como validação, pois, se o algoritmo executou o processo corretamente de compressão/descompressão tal arquivo deve ser *exatamente* igual ao arquivo utilizado como **entrada** para compressão.


# Como utilizar
Para executar o código basta compilar os arquivos contidos na pasta `src`. Para isso, execute os seguintes passos

## Compilando arquivos
* Clone o repositório
  ~~~bash
  git clone https://github.com/ViniciusMarchi/algoritmo-huffman.git
  ~~~


* navegue até a pasta do projeto
  ~~~bash
  cd algoritmo-huffman
  ~~~

* compile os arquivos contidos no diretório `src` utilizando g++ com o seguinte comando:
  ~~~bash
  g++ -o compilado src/*.cpp
  ~~~

## Executando o algoritmo
Após a compilação basta executar o arquivo compilado passando como parâmetro o diretório onde se encontra o arquivo `.txt` que será compactado, por exemplo.
  ~~~bash
  ./compilado input.txt
  ~~~