// Definition of Node strucutre used in MinHeap and Huffman tree structures.
class Node {
  private:
    char info; // character
    int freq;  // character frequency
    Node* left;
    Node* right;

  public:
    Node(char, int);
    Node();
    
    // setters
    void setInfo(char);
    void setFreq(int);
    void setLeft(Node*);
    void setRight(Node*);

    // getters
    char getInfo();
    int getFreq();
    Node* getLeft();
    Node* getRight();
};