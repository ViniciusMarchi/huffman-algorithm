#include "../headers/huffman.h"

// Huffman Costructor
Huffman::Huffman(string text) { 
  // Create a Map relating each character found in the text to its respective appearance frequency
  unordered_map<char, int> freq = frequencyCount(text);

  // Build huffman structure
  root = buildHuffman(freq);
  encodedString = encodeString(text);
  decodedString = decodeString(encodedString);
  compressionRatio = computeCompressionRatio(encodedString, decodedString);
} 

// This function build a Huffman Tree
Node* Huffman::buildHuffman(unordered_map<char, int> freq){
  // build a minheap
  MinHeap * minheap = new MinHeap(freq);
  int size = freq.size() - 1;
  for(int i = 0; i < size; i++){
    Node *z = new Node();
    z->setLeft(minheap->removeMin());
    z->setRight(minheap->removeMin());
    int x = z->getLeft()->getFreq();
    int y = z->getRight()->getFreq();        
    z->setFreq(x+y);
    minheap->insert(z);
  }
  Node *aux = minheap->removeMin();

  // Call destructor of MinHeap because the Huffman structure always been created
  minheap->~MinHeap();
  return aux;
}

// This function encode the string using the Huffman table
string Huffman::encodeString(string initialString){
  // Create Huffman table
  unordered_map<char, string> huffmanTable;
  createHuffmanTable(root, "", huffmanTable);

  // Encode string
  string encodedText = "";
  for (char character: initialString) {
    encodedText = encodedText + huffmanTable[character];
  }
  return encodedText;
}


// Decode string function
string Huffman::decodeString(string encodedString) {
  string decodedString = "";
  Node* aux = root;
  int size = (int) encodedString.size() + 1;
  for(int i = 0; i < size; i++){   
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
void Huffman::createHuffmanTable(Node* node, string aux, unordered_map<char, string> &huffmanTable) {
  // recursion base case
  if (node == 0){
      return;
  }

  // if the current Node is a leaf
  if (isLeaf(node)) {
      huffmanTable[node->getInfo()] = aux;
  }

  createHuffmanTable(node->getLeft(), aux + "0", huffmanTable);
  createHuffmanTable(node->getRight(), aux + "1", huffmanTable);
}


/*
 * This function count each character occurrence in text and store data
 * in Map structure where the pair key:value are represented by character:occurence
*/
unordered_map<char, int> Huffman::frequencyCount(string text){
  string aux = text;
  unordered_map<char, int> freq;
  for (char character: aux) {
    freq[character] = freq[character] + 1;
  }
  return freq;
}

// Check if a Node is a leaf
bool Huffman::isLeaf(Node* node) { 
	if(node->getLeft() == 0 && node->getRight() == 0){
      return true;
  }
  return false;
}

// This functions compute the compression ratio.
float Huffman::computeCompressionRatio(string encodedString, string decodedString){
  float encodedSize = encodedString.size();
  float decodedSize = decodedString.size();
  float ratio = (float) encodedSize/(decodedSize * 8) * 100;
  float percentRatio = -ratio + 100;
  return percentRatio;
}


// Huffman Destructor
Huffman::~Huffman(){
  deleteHuffman(root);
}

// Desctruc the Huffman structure
void Huffman::deleteHuffman(Node* node) {
	if(node != 0){
		deleteHuffman(node->getLeft());
		deleteHuffman(node->getRight());
		delete node;
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