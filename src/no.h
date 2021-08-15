// Definição da classe Nó utilizado nas estruturas: MinHeap e Árvore de Huffman. 
class No{
    private:
        char info; // informação armazenada
        int freq;  // frequência do caractere
        No* esq;
        No* dir;

    public:
        No(char, int);
        No();
        
        // setters
        void setInfo(char);
        void setFreq(int);
        void setEsq(No*);
        void setDir(No*);

        // getters
        char getInfo();
        int getFreq();
        No* getEsq();
        No* getDir();
};