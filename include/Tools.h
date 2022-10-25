#pragma once
#include <iostream>
using namespace std;
#include <fstream>
#include <sstream> 
int MultiplyMatris(int** map,int** key,int row,int col,int &keySize);
void Printer(int expectedDirection,int realDirection, int summation,ofstream &outputFile);
void printArray(int** arr, int row, int col);
void assignArray(ifstream &file,int** arr,int row,int col);
void createArray(int** arr,int col);
void deleteArray(int** arr,int row);
void Stroll(int** map,int** key,int row,int col, int mapRow,int mapCol,int keyRow,int keyCol,ofstream &outputFile,int &keySize);