#include "huffman.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char **argv) { 
    // variavel que armazenará o texto lido do arquivo
    string texto;
    
    if(argc > 1){
        // Utilizando um buffer o arquivo é lido
        ifstream ArquivoEntrada(argv[1]);
        // Verificando se é um arquivo válido
        if(ArquivoEntrada){
            std::stringstream buffer;
            buffer << ArquivoEntrada.rdbuf();
            texto = buffer.str();
            ArquivoEntrada.close();
        
            // Instanciando o algoritmo de Huffman
            Huffman * algoritmoHuffman = new Huffman(texto);
            string textoComprimido = algoritmoHuffman->getStringCodificada();
            string textoDescomprimido = algoritmoHuffman->getStringDecodificada();
            

            // Criando e preenchendo os arquivos que conterão os resultados do algoritmo
            ofstream ArquivoComprimido("comprimido.txt");
            ArquivoComprimido << textoComprimido;
            ArquivoComprimido.close();

            ofstream ArquivoDescomprimido("descomprimido.txt");
            ArquivoDescomprimido << textoDescomprimido;
            ArquivoDescomprimido.close();

            // Taxa de compressão obtida
            cout << "TAXA DE COMPRESSAO: " << algoritmoHuffman->getTaxaCompressao() << "%";
            // Destrói a estrutura
            algoritmoHuffman->~Huffman();
            return 0;         
        }
    }
    cout << "Nenhum arquivo de entrada encontrado.";
	return 0;
} 