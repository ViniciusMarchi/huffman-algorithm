#include "node.h"
#include <unordered_map>
using namespace std;

class MinHeap{
  private:
    int elementsQty; // current size (number of elements)
    int max; // max size
    Node** pointerArr; // array of pointers of Node type

  public:
    /*
      * Build a heap receiving the size, the text and the map structure that stores
      * occurrence frequency of each character in text
    */
    MinHeap(unordered_map<char, int>);
    
    // Due dinamic array alocation, exists a destructor to desalocate memory
    ~MinHeap();

    void goUp(int);
    void goDown(int);
    void buildHeap();
    void insert(Node*);
    Node* removeMin();
    bool isLeaf(Node*);
};