#include "minHeap.h"
#include <unordered_map>
#include <string>

/*
 * This class define Huffman Tree structure using MinHeap and functions to use it.
 * After creation, the Huffman Structure are used to encode and decode a text.
*/
class Huffman {
    private:
        No* root; // Node that stores the root of Huffman Structure
        string encodedString;
        string decodedString;
        float compressionRatio;

    public:
        Huffman(string);
        ~Huffman();
        
        // Build the structure
        No* buildHuffman(unordered_map<char, int>);
        unordered_map<char, int> contaFrequencia(string);

        // Encode string
        string encodeString(string);
        void createHuffmanTable(No*, string, unordered_map<char, string>&);
       
        // Decode string
        string decodeString(string);
        
        // Compute compression ratio
        float computeCompressionRatio(string, string);
        
        bool isLeaf(No*);
        void deleteHuffman(No*);

        // getters
        string getEncodedString();
        string getDecodedString();
        float getCompressionRatio();
};