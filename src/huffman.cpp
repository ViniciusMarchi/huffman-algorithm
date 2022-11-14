#include "../headers/huffman.h"

// Huffman Costructor
Huffman::Huffman(string texto) { 
    // Create a Map relating each character found in the text to its respective appearance frequency
    unordered_map<char, int> freq = contaFrequencia(texto);

    // Build huffman structure
    root = buildHuffman(freq);
    encodedString = encodeString(texto);
    decodedString = decodeString(encodedString);
    compressionRatio = computeCompressionRatio(encodedString, decodedString);
} 

// This function build a Huffman Tree
No* Huffman::buildHuffman(unordered_map<char, int> freq){
    // build a minheap
    MinHeap * minheap = new MinHeap(freq);
    int tamanho = freq.size() - 1;
    for(int i = 0; i < tamanho; i++){
        No* z = new No();
        z->setLeft(minheap->removeMin());
        z->setRight(minheap->removeMin());
        int x = z->getLeft()->getFreq();
        int y = z->getRight()->getFreq();        
        z->setFreq(x+y);
        minheap->insert(z);
    }
    No * aux = minheap->removeMin();

    // Call destructor of MinHeap because the Huffman structure always been created
    minheap->~MinHeap();
    return aux;
}

// This function encode the string using the Huffman table
string Huffman::encodeString(string stringInicial){
    // Create Huffman table
    unordered_map<char, string> tabelaHuffman;
    createHuffmanTable(root, "", tabelaHuffman);

    // Encode string
    string textoCodificado = "";
    for (char caractere: stringInicial) {
        textoCodificado = textoCodificado + tabelaHuffman[caractere];
    }
    return textoCodificado;
}


// Decode string function
string Huffman::decodeString(string encodedString) {
    string decodedString = "";
    No* aux = root;
    int tam = (int) encodedString.size() + 1;
    for(int i = 0; i < tam; i++){   
        if (isLeaf(aux)){
            decodedString = decodedString + aux->getInfo();
            aux = root;
        }
    
        if (encodedString[i] =='0'){
            aux = aux->getLeft();
        } else {
            aux = aux->getRight();
        }
    }
    return decodedString;
}


/*
 * This function create the Huffman table.

 * To encode string is necessary, given the constructed huffman tree, to know to each character
 * which will be your encoding in bits. This is done traversing the Huffman tree in preorder and
 * considering that the left child of each Node is represented by "0" and the right child by "1".

 * As a result everything is stored in a Map structure, where the key is a character and the value
 * are the bit sequence that represents this.
*/
void Huffman::createHuffmanTable(No* no, string aux, unordered_map<char, string> &tabelaHuffman) {
    // recursion base case
    if (no == 0){
        return;
    }
 
    // if the current Node is a leaf
    if (isLeaf(no)) {
        tabelaHuffman[no->getInfo()] = aux;
    }
 
    createHuffmanTable(no->getLeft(), aux + "0", tabelaHuffman);
    createHuffmanTable(no->getRight(), aux + "1", tabelaHuffman);
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
bool Huffman::isLeaf(No* no) { 
	if(no->getLeft() == 0 && no->getRight() == 0){
        return true;
    }
    return false;
}

// This functions compute the compression ratio.
float Huffman::computeCompressionRatio(string codificada, string decodificada){
    float tamCodificada = codificada.size();
    float tamDecodificada = decodificada.size();
    float taxa = (float) tamCodificada/(tamDecodificada * 8) * 100;
    taxa = -taxa + 100;
    return taxa;
}


// Huffman Destructor
Huffman::~Huffman(){
    deleteHuffman(root);
}

// Desctruc the Huffman structure
void Huffman::deleteHuffman(No* no) {
	if(no != 0){
		deleteHuffman(no->getLeft());
		deleteHuffman(no->getRight());
		delete no;
	}
}

// Getters functions
string Huffman::getEncodedString(){
    return encodedString;
}

string Huffman::getDecodedString(){
    return decodedString;
}

float Huffman::getCompressionRatio(){
    return compressionRatio;
}