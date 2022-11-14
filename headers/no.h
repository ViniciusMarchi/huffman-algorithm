// Definition of Node strucutre used in MinHeap and Huffman tree structures.
class No {
    private:
        char info; // character
        int freq;  // character frequency
        No* left;
        No* right;

    public:
        No(char, int);
        No();
        
        // setters
        void setInfo(char);
        void setFreq(int);
        void setLeft(No*);
        void setRight(No*);

        // getters
        char getInfo();
        int getFreq();
        No* getLeft();
        No* getRight();
};