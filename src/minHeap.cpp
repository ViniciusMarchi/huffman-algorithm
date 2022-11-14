#include "../headers/minHeap.h"

// MinHeap Construtor
MinHeap::MinHeap(unordered_map<char, int> freq){
    this->max = freq.size();
    this->pointerArr = new No*[max];
    int aux = 0;
    
    // Iterate Maps and for each character create a new Node containing your respective frequency
    for(auto item : freq){
            if(aux < max){
                pointerArr[aux] = new No(item.first, item.second);
                aux++;
            }
    } 
    // The heap will stay full
    this->elementsQty = max;
    buildHeap();
}

// Build the MinHeap
void MinHeap::buildHeap(){
    int ultimo = elementsQty/2-1;

    for(int i = ultimo; i >= 0; i--){
        goDown(i);
    }
}

// Insert a Node
void MinHeap::insert(No* no){
 if(elementsQty < max){ // tem espaço na heap
        pointerArr[elementsQty] = no;
        elementsQty++;
        goUp(elementsQty-1);
    }
}


// Remove the Node with lowest frequency
No* MinHeap::removeMin(){
    No* removido = 0;
    if (elementsQty > 0){ // check if the structure has elements
        removido = pointerArr[0];
        pointerArr[0] = pointerArr[elementsQty-1];
        elementsQty--;
        goDown(0);
    }
    return removido;
}

// This function go down one element in heap
void MinHeap::goDown(int indice){
    int j; // j represents the child

    // Comput the left child index
    j = (2 * indice + 1);

    if (j < elementsQty){
        if (j+1 < elementsQty){
            if (pointerArr[j+1]->getFreq() < pointerArr[j]->getFreq()){
                j++; // noew j is the index of smaller child
            }
        }

        // Check if parent is bigger than the smaller child
        if (pointerArr[indice]->getFreq() > pointerArr[j]->getFreq()){
            No* aux = pointerArr[indice];
            pointerArr[indice] = pointerArr[j];
            pointerArr[j] = aux;
            goDown(j);
        }
    }
}


// This function go up in heap structure
void MinHeap::goUp(int indice){
     int j;

    // Check if is not root, ie I didn't arrived at the top of the structure
    if (indice > 0){
        // Compute parent index
        j = (indice - 1)/2;
        // Check if the child are bigger than parent. In positive case violates the MinHeap
        // restriction and need swap
        if (pointerArr[indice]->getFreq() < pointerArr[j]->getFreq()){
            No* aux = pointerArr[indice];
            pointerArr[indice] = pointerArr[j];
            pointerArr[j] = aux;
            goUp(j);
        }
    }
}

// Retorna a bool that represents if a Node is a leaf
bool MinHeap::isLeaf(No* no){
    bool noFolha = false;
    if(no->getLeft() && no->getRight()){
        noFolha = true;
    }
    return noFolha;
}

// Destructor
MinHeap::~MinHeap(){
    delete[] pointerArr;
}