#include "huffman.h"

// Construtor
Huffman::Huffman(string texto) { 
    // Constrói um Map relacionando cada caractere encontrado no texto com sua respectiva frequência de aparições
    unordered_map<char, int> freq = contaFrequencia(texto);

    // Constrói e utiliza a estrutura de Huffman 
    raiz = constroiHuffman(freq);
    stringCodificada = codificaString(texto);
    stringDecodificada = decodificaString(stringCodificada);
    taxaCompressao = calculaTaxa(stringCodificada, stringDecodificada);
} 

// Constrói a Árvore de Huffman de acordo com o pseudo-código exibido durante a aula
No* Huffman::constroiHuffman(unordered_map<char, int> freq){
    // Cria a MinHeap
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

    // Invoca o Destrutor da MinHeap porque a estrutura de Huffman ja está criada
    minheap->~MinHeap();
    return aux;
}

string Huffman::codificaString(string stringInicial){
    // Cria a tabela de Huffman
    unordered_map<char, string> tabelaHuffman;
    criaTabelaDeHuffman(raiz, "", tabelaHuffman);

    // Realiza a codificação utilizando a tabela criada
    string textoCodificado = "";
    for (char caractere: stringInicial) {
        textoCodificado = textoCodificado + tabelaHuffman[caractere];
    }
    return textoCodificado;
}

// Assim como na codificação da string, aqui também se percorre a árvore de Huffman, mas dessa vez utilizando uma  abordagem
// iterativa (não recursiva) para possibilitar percorrer não só a árvore, mas também  a string a ser decodificada.
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


// Para codificar é necessário, dada a árvore construida, conhecer para cada caractere qual será sua codificação em bits.
// Isso é feito nesse algoritmo, percorrendo a árvore de Huffman em pre-ordem e considerando que o filho esquerdo de cada No
// é represetado por "0" e o direito por "1".
// Como resultando tudo é armazenado em um Map, onde a key é um caractere e o valor a sequencia de bits que o representa.
void Huffman::criaTabelaDeHuffman(No* no, string aux, unordered_map<char, string> &tabelaHuffman) {
    // caso base da recursão
    if (no == 0){
        return;
    }
 
    // se o No atual é uma folha
    if (folha(no)) {
        tabelaHuffman[no->getInfo()] = aux;
    }
 
    criaTabelaDeHuffman(no->getEsq(), aux + "0", tabelaHuffman);
    criaTabelaDeHuffman(no->getDir(), aux + "1", tabelaHuffman);
}

// Para cada caractere conta sua frequência no texto.
// Os dados são armazenados em um Map, onde o par chave:valor são caractere:frequência
unordered_map<char, int> Huffman::contaFrequencia(string texto){
    string aux = texto;
    unordered_map<char, int> freq;
    for (char caractere: aux) {
        freq[caractere] = freq[caractere] + 1;
    }
    return freq;
}

// Verifica se o No é uma folha
bool Huffman::folha(No* no) { 
	if(no->getEsq() == 0 && no->getDir() == 0){
        return true;
    }
    return false;
}

float Huffman::calculaTaxa(string codificada, string decodificada){
    float tamCodificada = codificada.size();
    float tamDecodificada = decodificada.size();
    float taxa = (float) tamCodificada/(tamDecodificada * 8) * 100;
    taxa = -taxa + 100;
    return taxa;
}


// Destrutor
Huffman::~Huffman(){
    deletaEstrutura(raiz);
}

// Código que destrói a estrutura de Huffman baseado no código destruro visto na aula de Avl
void Huffman::deletaEstrutura(No* no) {
	if(no != 0){
		deletaEstrutura(no->getEsq());
		deletaEstrutura(no->getDir());
		delete no;
	}
}

// Getters
string Huffman::getStringCodificada(){
    return stringCodificada;
}

string Huffman::getStringDecodificada(){
    return stringDecodificada;
}

float Huffman::getTaxaCompressao(){
    return taxaCompressao;
}