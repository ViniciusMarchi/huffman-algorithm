<p align="center">
  <a href="./README_pt-BR.md">Portuguese Version </a>
  <span>:brazil:</span>
</p>

# Table of Contents
  * [Introduction](#Introduction---huffman-algorithm)
  * [Features](#Features)
  * [How to use](#How-to-use)
    * [Compiling files](#Compiling-files) 
    * [Run algorithm](#Run-algorithm)

# Introduction - Huffman Algorithm
Implementation of Compression Huffman Algorithm in C++

Huffman's algorithm uses a file compression method based on the probability of occurrence of characters in text.

# Features
In this implementation the Huffman Algorithm is defined by the concept of digital search, described by Digital Search Tree, which will allow the *compression* and *decompression* of text files (`.txt`).


This code will receive a input file, a `.txt` file which will be compressed, and generates two files as output:
  * `encoded.txt`: represents the compressed file, in binary. This file is the result of running Huffman's algorithm on the **input** file.
  * `decoded.txt`: represents the decoded file. This file is the result of applying Huffman's algorithm on the `encoded.txt` file. In other words, it's decompression. This file works as a validation, because if the algorithm performed the compression/decompression process correctly, this file must be *exactly* equal to the file used as **input** for compression.

# How to use
To run code just compile the files contained in `src` folder. To do this, perform the following simple steps

## Compiling files
* Clone repository
  ```bash
  git clone git@github.com:ViniciusMarchi/huffman-algorithm.git
  ```

* Go to project folder
  ```bash
  cd huffman-algorithm
  ```

* Compile the file contained in `src` directory using `g++` with the following command:
  ```bash
  g++ -o compilled src/*.cpp
  ```

## Run algorithm
After compiling, just run the compiled file, passing as a parameter the `.txt` input file to be compressed, for example.
```bash
./compilled input.txt
```