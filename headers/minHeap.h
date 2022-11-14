#include "no.h"
#include <unordered_map>
using namespace std;

class MinHeap{
    private:
        int numElementos; // current size
        int max; // max size
        No** vetorPonteiros; // array of pointers of Node type

    public:

        /*
         * Build a heap receiving the size, the text and the map structure that stores
         * occurrence frequency of each character in text
        */
        MinHeap(unordered_map<char, int>);
        
        // Due dinamic array alocation, exists a destructor to desalocate memory
        ~MinHeap();

        void subir(int);
        void descer(int);
        void construirHeap();
        void inserir(No*);
        No* remover();
        bool folha(No*);
};