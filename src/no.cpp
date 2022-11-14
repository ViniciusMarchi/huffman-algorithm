#include "../headers/no.h"

// Constructor
No::No (char info, int freq){
    left = right = 0;
    this->freq = freq;
    this->info = info;
}

No::No (){
    left = right = 0;
    this->freq = 0;
    this->info = 0;
}

// Setters
void No::setInfo(char info){
    this->info = info;
}

void No::setFreq(int freq){
    this->freq = freq;
}

void No::setLeft(No* filhoEsq){
    this->left = filhoEsq;
}

void No::setRight(No * filhoDir){
    this->right = filhoDir;
}

// Getters
char No::getInfo(){
    return this->info;
}

int No::getFreq(){
    return this->freq;
}

No* No::getLeft(){
    return this->left;
}

No* No::getRight(){
    return this->right;
}