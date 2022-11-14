#include "minHeap.h"
#include <unordered_map>
#include <string>

/*
 * This class define Huffman Tree structure using MinHeap and functions to use it.
 * After creation, the Huffman Structure are used to encode and decode a text.
*/
class Huffman {
    private:
        No* raiz; // Node that stores the root of Huffman Structure
        string stringCodificada;
        string stringDecodificada;
        float taxaCompressao;

    public:
        Huffman(string);
        ~Huffman();
        
        // Build the structure
        No* constroiHuffman(unordered_map<char, int>);
        unordered_map<char, int> contaFrequencia(string);

        // Encode string
        string codificaString(string);
        void criaTabelaDeHuffman(No*, string, unordered_map<char, string>&);
       
        // Decode string
        string decodificaString(string);
        
        // Compute compression ratio
        float calculaTaxa(string, string);
        
        bool folha(No*);
        void deletaEstrutura(No*);

        // getters
        string getStringCodificada();
        string getStringDecodificada();
        float getTaxaCompressao();
};