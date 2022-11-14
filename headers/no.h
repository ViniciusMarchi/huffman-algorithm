// Definition of Node strucutre used in MinHeap and Huffman tree structures.
class No {
    private:
        char info; // character
        int freq;  // character frequency
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