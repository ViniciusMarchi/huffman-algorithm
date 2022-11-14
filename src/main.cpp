#include "../headers/huffman.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char **argv) { 
    string inputText;
    
    if(argc > 1){
        // capture text file from user
        ifstream InputFile(argv[1]);
        // check if file is valid
        if(InputFile){
            // read text file
            std::stringstream buffer;
            buffer << InputFile.rdbuf();
            inputText = buffer.str();
            InputFile.close();
        
            // instance the Huffman structure
            Huffman *huffmanAlgorithm = new Huffman(inputText);
            string encodedText = huffmanAlgorithm->getEncodedString();
            string decodedText = huffmanAlgorithm->getDecodedString();
            

            // create and write output file that will contain the encoded text.
            ofstream EncodedFile("encoded.txt");
            EncodedFile << encodedText;
            EncodedFile.close();

            // create and write output file that will contain the decoded text.
            ofstream DecodedFile("decoded.txt");
            DecodedFile << decodedText;
            DecodedFile.close();

            // Compression ratio
            cout << "Compression Ratio: " << huffmanAlgorithm->getCompressionRatio() << "%\n";
            // Destrói a estrutura
            huffmanAlgorithm->~Huffman();
            return 0;         
        }
    }
    cout << "Error: input file not found.";
	return 0;
} 