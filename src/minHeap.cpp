#include "../headers/minHeap.h"

// MinHeap Construtor
MinHeap::MinHeap(unordered_map<char, int> freq){
    this->max = freq.size();
    this->vetorPonteiros = new No*[max];
    int aux = 0;
    
    // Iterate Maps and for each character create a new Node containing your respective frequency
    for(auto item : freq){
            if(aux < max){
                vetorPonteiros[aux] = new No(item.first, item.second);
                aux++;
            }
    } 
    // The heap will stay full
    this->numElementos = max;
    construirHeap();
}

// Build the MinHeap
void MinHeap::construirHeap(){
    int ultimo = numElementos/2-1;

    for(int i = ultimo; i >= 0; i--){
        descer(i);
    }
}

// Insert a Node
void MinHeap::inserir(No* no){
 if(numElementos < max){ // tem espaço na heap
        vetorPonteiros[numElementos] = no;
        numElementos++;
        subir(numElementos-1);
    }
}


// Remove the Node with lowest frequency
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

// This function go down one element in heap
void MinHeap::descer(int indice){
    int j; // j represents the child

    // Comput the left child index
    j = (2 * indice + 1);

    if (j < numElementos){
        if (j+1 < numElementos){
            if (vetorPonteiros[j+1]->getFreq() < vetorPonteiros[j]->getFreq()){
                j++; // noew j is the index of smaller child
            }
        }

        // Check if parent is bigger than the smaller child
        if (vetorPonteiros[indice]->getFreq() > vetorPonteiros[j]->getFreq()){
            No* aux = vetorPonteiros[indice];
            vetorPonteiros[indice] = vetorPonteiros[j];
            vetorPonteiros[j] = aux;
            descer(j);
        }
    }
}


// This function go up in heap structure
void MinHeap::subir(int indice){
     int j;

    // Check if is not root, ie I didn't arrived at the top of the structure
    if (indice > 0){
        // Compute parent index
        j = (indice - 1)/2;
        // Check if the child are bigger than parent. In positive case violates the MinHeap
        // restriction and need swap
        if (vetorPonteiros[indice]->getFreq() < vetorPonteiros[j]->getFreq()){
            No* aux = vetorPonteiros[indice];
            vetorPonteiros[indice] = vetorPonteiros[j];
            vetorPonteiros[j] = aux;
            subir(j);
        }
    }
}

// Retorna a bool that represents if a Node is a leaf
bool MinHeap::folha(No* no){
    bool noFolha = false;
    if(no->getEsq() && no->getDir()){
        noFolha = true;
    }
    return noFolha;
}

// Destructor
MinHeap::~MinHeap(){
    delete[] vetorPonteiros;
}