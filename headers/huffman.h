#include "minHeap.h"
#include <unordered_map>
#include <string>

/*
 * This class define Huffman Tree structure using MinHeap and functions to use it.
 * After creation, the Huffman Structure are used to encode and decode a text.
*/
class Huffman {
  private:
    Node* root; // Node that stores the root of Huffman Structure
    string encodedString;
    string decodedString;
    float compressionRatio;

  public:
    Huffman(string);
    ~Huffman();
    
    // Build the structure
    Node* buildHuffman(unordered_map<char, int>);
    unordered_map<char, int> frequencyCount(string);

    // Encode string
    string encodeString(string);
    void createHuffmanTable(Node*, string, unordered_map<char, string>&);
    
    // Decode string
    string decodeString(string);
    
    // Compute compression ratio
    float computeCompressionRatio(string, string);
    
    bool isLeaf(Node*);
    void deleteHuffman(Node*);

    // getters
    string getEncodedString();
    string getDecodedString();
    float getCompressionRatio();
};