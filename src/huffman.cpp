#include "../headers/huffman.h"

// Huffman Costructor
Huffman::Huffman(string texto) { 
    // Create a Map relating each character found in the text to its respective appearance frequency
    unordered_map<char, int> freq = contaFrequencia(texto);

    // Build huffman structure
    raiz = constroiHuffman(freq);
    stringCodificada = codificaString(texto);
    stringDecodificada = decodificaString(stringCodificada);
    taxaCompressao = calculaTaxa(stringCodificada, stringDecodificada);
} 

// This function build a Huffman Tree
No* Huffman::constroiHuffman(unordered_map<char, int> freq){
    // build a minheap
    MinHeap * minheap = new MinHeap(freq);
    int tamanho = freq.size() - 1;
    for(int i = 0; i < tamanho; i++){
        No* z = new No();
        z->setEsq(minheap->remover());
        z->setDir(minheap->remover());
        int x = z->getEsq()->getFreq();
        int y = z->getDir()->getFreq();        
        z->setFreq(x+y);
        minheap->inserir(z);
    }
    No * aux = minheap->remover();

    // Call destructor of MinHeap because the Huffman structure always been created
    minheap->~MinHeap();
    return aux;
}

// This function encode the string using the Huffman table
string Huffman::codificaString(string stringInicial){
    // Create Huffman table
    unordered_map<char, string> tabelaHuffman;
    criaTabelaDeHuffman(raiz, "", tabelaHuffman);

    // Encode string
    string textoCodificado = "";
    for (char caractere: stringInicial) {
        textoCodificado = textoCodificado + tabelaHuffman[caractere];
    }
    return textoCodificado;
}


// Decode string function
string Huffman::decodificaString(string stringCodificada) {
    string stringDecodificada = "";
    No* aux = raiz;
    int tam = (int) stringCodificada.size() + 1;
    for(int i = 0; i < tam; i++){   
        if (folha(aux)){
            stringDecodificada = stringDecodificada + aux->getInfo();
            aux = raiz;
        }
    
        if (stringCodificada[i] =='0'){
            aux = aux->getEsq();
        } else {
            aux = aux->getDir();
        }
    }
    return stringDecodificada;
}


/*
 * This function create the Huffman table.

 * To encode string is necessary, given the constructed huffman tree, to know to each character
 * which will be your encoding in bits. This is done traversing the Huffman tree in preorder and
 * considering that the left child of each Node is represented by "0" and the right child by "1".

 * As a result everything is stored in a Map structure, where the key is a character and the value
 * are the bit sequence that represents this.
*/
void Huffman::criaTabelaDeHuffman(No* no, string aux, unordered_map<char, string> &tabelaHuffman) {
    // recursion base case
    if (no == 0){
        return;
    }
 
    // if the current Node is a leaf
    if (folha(no)) {
        tabelaHuffman[no->getInfo()] = aux;
    }
 
    criaTabelaDeHuffman(no->getEsq(), aux + "0", tabelaHuffman);
    criaTabelaDeHuffman(no->getDir(), aux + "1", tabelaHuffman);
}


/*
 * This function count each character occurrence in text and store data
 * in Map structure where the pair key:value are represented by character:occurence
*/
unordered_map<char, int> Huffman::contaFrequencia(string texto){
    string aux = texto;
    unordered_map<char, int> freq;
    for (char caractere: aux) {
        freq[caractere] = freq[caractere] + 1;
    }
    return freq;
}

// Check if a Node is a leaf
bool Huffman::folha(No* no) { 
	if(no->getEsq() == 0 && no->getDir() == 0){
        return true;
    }
    return false;
}

// This functions compute the compression ratio.
float Huffman::calculaTaxa(string codificada, string decodificada){
    float tamCodificada = codificada.size();
    float tamDecodificada = decodificada.size();
    float taxa = (float) tamCodificada/(tamDecodificada * 8) * 100;
    taxa = -taxa + 100;
    return taxa;
}


// Huffman Destructor
Huffman::~Huffman(){
    deletaEstrutura(raiz);
}

// Desctruc the Huffman structure
void Huffman::deletaEstrutura(No* no) {
	if(no != 0){
		deletaEstrutura(no->getEsq());
		deletaEstrutura(no->getDir());
		delete no;
	}
}

// Getters functions
string Huffman::getStringCodificada(){
    return stringCodificada;
}

string Huffman::getStringDecodificada(){
    return stringDecodificada;
}

float Huffman::getTaxaCompressao(){
    return taxaCompressao;
}