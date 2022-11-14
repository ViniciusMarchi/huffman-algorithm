#include "../headers/huffman.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char **argv) { 
    // stores the input text
    string texto;
    
    if(argc > 1){
        // capture text file from user
        ifstream ArquivoEntrada(argv[1]);
        // check if file is valid
        if(ArquivoEntrada){
            // read text file
            std::stringstream buffer;
            buffer << ArquivoEntrada.rdbuf();
            texto = buffer.str();
            ArquivoEntrada.close();
        
            // instance the Huffman structure
            Huffman * algoritmoHuffman = new Huffman(texto);
            string textoComprimido = algoritmoHuffman->getStringCodificada();
            string textoDescomprimido = algoritmoHuffman->getStringDecodificada();
            

            // create and write output file that will contain the encoded text.
            ofstream ArquivoComprimido("comprimido.txt");
            ArquivoComprimido << textoComprimido;
            ArquivoComprimido.close();

            // create and write output file that will contain the decoded text.
            ofstream ArquivoDescomprimido("descomprimido.txt");
            ArquivoDescomprimido << textoDescomprimido;
            ArquivoDescomprimido.close();

            // Compression ratio
            cout << "TAXA DE COMPRESSAO: " << algoritmoHuffman->getTaxaCompressao() << "%";
            // Destrói a estrutura
            algoritmoHuffman->~Huffman();
            return 0;         
        }
    }
    cout << "Nenhum arquivo de entrada encontrado.";
	return 0;
} 