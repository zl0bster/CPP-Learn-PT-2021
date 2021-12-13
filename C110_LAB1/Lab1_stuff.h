#pragma once
#include <iostream>

const size_t chArLineLen = 40;
const size_t chArLineNum = 20;

void print_array(const int* arr, size_t nLayers, size_t nLines, size_t nCols);
// prints only 3d arrays
void print_array(const float* arr, size_t nLayers, size_t nLines, size_t nCols);
int summ_array(const int* arr, size_t nLayers, size_t nLines, size_t nCols);
void swap_pointers(char** p1, char** p2);
void Swap_p(int* x, int* y);
void print_ch_array(char charArray[][chArLineLen]);
char* get_rnd_str(size_t maxLen);
void get_rnd_str1(char* newStr, size_t maxLen);
