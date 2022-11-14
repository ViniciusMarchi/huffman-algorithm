#include "../headers/minHeap.h"

// MinHeap Construtor
MinHeap::MinHeap(unordered_map<char, int> freq){
  this->max = freq.size();
  this->pointerArr = new Node*[max];
  int aux = 0;
    
  // Iterate Maps and for each character create a new Node containing your respective frequency
  for(auto item : freq){
    if(aux < max){
      pointerArr[aux] = new Node(item.first, item.second);
      aux++;
    }
  } 
  // The heap will stay full
  this->elementsQty = max;
  buildHeap();
}

// Build the MinHeap
void MinHeap::buildHeap(){
  int lastElement = elementsQty/2-1;

  for(int i = lastElement; i >= 0; i--){
    goDown(i);
  }
}

// Insert a Node
void MinHeap::insert(Node* node){
  if(elementsQty < max){ // heap structure still have space
    pointerArr[elementsQty] = node;
    elementsQty++;
    goUp(elementsQty-1);
  }
}


// Remove the Node with lowest frequency
Node* MinHeap::removeMin(){
  Node* removed = 0;
  if (elementsQty > 0){ // check if the structure has elements
    removed = pointerArr[0];
    pointerArr[0] = pointerArr[elementsQty-1];
    elementsQty--;
    goDown(0);
  }
  return removed;
}

// This function go down one element in heap
void MinHeap::goDown(int index){
  int j; // j represents the child

  // Comput the left child index
  j = (2 * index + 1);

  if (j < elementsQty){
    if (j+1 < elementsQty){
        if (pointerArr[j+1]->getFreq() < pointerArr[j]->getFreq()){
            j++; // noew j is the index of smaller child
        }
    }

    // Check if parent is bigger than the smaller child
    if (pointerArr[index]->getFreq() > pointerArr[j]->getFreq()){
        Node* aux = pointerArr[index];
        pointerArr[index] = pointerArr[j];
        pointerArr[j] = aux;
        goDown(j);
    }
  }
}


// This function go up in heap structure
void MinHeap::goUp(int index){
  int j;

  // Check if is not root, ie I didn't arrived at the top of the structure
  if (index > 0){
    // Compute parent index
    j = (index - 1)/2;
    // Check if the child are bigger than parent. In positive case violates the MinHeap
    // restriction and need swap
    if (pointerArr[index]->getFreq() < pointerArr[j]->getFreq()){
      Node* aux = pointerArr[index];
      pointerArr[index] = pointerArr[j];
      pointerArr[j] = aux;
      goUp(j);
    }
  }
}

// Retorna a bool that represents if a Node is a leaf
bool MinHeap::isLeaf(Node* node){
  bool noFolha = false;
  if(node->getLeft() && node->getRight()){
    noFolha = true;
  }
  return noFolha;
}

// Destructor
MinHeap::~MinHeap(){
  delete[] pointerArr;
}