#include "../headers/no.h"

// Constructor
No::No (char info, int freq){
    esq = dir = 0;
    this->freq = freq;
    this->info = info;
}

No::No (){
    esq = dir = 0;
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

void No::setEsq(No* filhoEsq){
    this->esq = filhoEsq;
}

void No::setDir(No * filhoDir){
    this->dir = filhoDir;
}

// Getters
char No::getInfo(){
    return this->info;
}

int No::getFreq(){
    return this->freq;
}

No* No::getEsq(){
    return this->esq;
}

No* No::getDir(){
    return this->dir;
}