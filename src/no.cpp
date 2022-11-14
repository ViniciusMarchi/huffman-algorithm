#include "../headers/node.h"

// Constructor
Node::Node (char info, int freq){
  left = right = 0;
  this->freq = freq;
  this->info = info;
}

Node::Node (){
  left = right = 0;
  this->freq = 0;
  this->info = 0;
}

// Setters
void Node::setInfo(char info){
  this->info = info;
}

void Node::setFreq(int freq){
  this->freq = freq;
}

void Node::setLeft(Node* filhoEsq){
  this->left = filhoEsq;
}

void Node::setRight(Node * filhoDir){
  this->right = filhoDir;
}

// Getters
char Node::getInfo(){
  return this->info;
}

int Node::getFreq(){
  return this->freq;
}

Node* Node::getLeft(){
  return this->left;
}

Node* Node::getRight(){
  return this->right;
}