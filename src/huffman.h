#include "minHeap.h"
#include <unordered_map>
#include <string>

// Definição da classe responsável por construir a Árvore de Huffman com auxílio da MinHeap.
// Após sua criação a árvore é utilizada para codificar e decodificar um texto.
class Huffman {
    private:
        No* raiz; // No que armazena a raiz da estrutura de Huffman
        string stringCodificada;
        string stringDecodificada;
        float taxaCompressao;

    public:
        Huffman(string);
        ~Huffman();
        
        // Constrói a estrutura
        No* constroiHuffman(unordered_map<char, int>);
        unordered_map<char, int> contaFrequencia(string);

        // Codifica a string que representa o texto
        string codificaString(string);
        void criaTabelaDeHuffman(No*, string, unordered_map<char, string>&);
       
        // Decodifica a string
        string decodificaString(string);
        
        // Calcula a taxa de compressão
        float calculaTaxa(string, string);
        
        bool folha(No*);
        void deletaEstrutura(No*);

        // getters
        string getStringCodificada();
        string getStringDecodificada();
        float getTaxaCompressao();
};