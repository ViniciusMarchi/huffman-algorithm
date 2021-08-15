#include "minHeap.h"

// Construtor
MinHeap::MinHeap(unordered_map<char, int> freq){
    this->max = freq.size();
    this->vetorPonteiros = new No*[max];
    int aux = 0;
    // Itera o Map e para cada caractere cria um No com sua respectiva frequência
    for(auto item : freq){
            if(aux < max){
                vetorPonteiros[aux] = new No(item.first, item.second);
                aux++;
            }
    } 
    // A heap ficará cheia
    this->numElementos = max;
    construirHeap();
}

// Constrói a Heap
void MinHeap::construirHeap(){
    int ultimo = numElementos/2-1;

    for(int i = ultimo; i >= 0; i--){
        descer(i);
    }
}

// Insere um Nó na MinHeap
void MinHeap::inserir(No* no){
 if(numElementos < max){ // tem espaço na heap
        vetorPonteiros[numElementos] = no;
        numElementos++;
        subir(numElementos-1);
    }
}

// Remove o Nó com menor frequência da MinHeap
No* MinHeap::remover(){
    No* removido = 0;
    if (numElementos > 0){ // tem alguém para remover
        removido = vetorPonteiros[0];
        vetorPonteiros[0] = vetorPonteiros[numElementos-1];
        numElementos--;
        descer(0);
    }
    return removido;
}


// Método que desce um elemento no heap, algoritmo como o apresentado em aula
void MinHeap::descer(int indice){

    int j; // j representa o filho

    // Calcula o indice do filho da esquerda
    j = (2 * indice + 1);

    if (j < numElementos){
        if (j+1 < numElementos){
            if (vetorPonteiros[j+1]->getFreq() < vetorPonteiros[j]->getFreq()){
                j++; // agora j é o indice do menor filho
            }
        }
        // Verifica se o pai é maior que o menor dos filhos
        if (vetorPonteiros[indice]->getFreq() > vetorPonteiros[j]->getFreq()){
            No* aux = vetorPonteiros[indice];
            vetorPonteiros[indice] = vetorPonteiros[j];
            vetorPonteiros[j] = aux;
            descer(j);
        }
    }
}


// Método subir como apresentado em aula
void MinHeap::subir(int indice){
     int j;

    // Verifico se não cheguei na raiz
    if (indice > 0){
        // Calculo o indice do pai
        j = (indice - 1)/2;
        // Verifico se o filho é maior que o pai, se for viola a restrição e preciso trocar
        if (vetorPonteiros[indice]->getFreq() < vetorPonteiros[j]->getFreq()){
            No* aux = vetorPonteiros[indice];
            vetorPonteiros[indice] = vetorPonteiros[j];
            vetorPonteiros[j] = aux;
            subir(j);
        }
    }
}

// Retorna se um no é folha
bool MinHeap::folha(No* no){
    bool noFolha = false;
    if(no->getEsq() && no->getDir()){
        noFolha = true;
    }
    return noFolha;
}

MinHeap::~MinHeap(){
    delete[] vetorPonteiros;
}