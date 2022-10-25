#include <iostream>
using namespace std;
#include <fstream>
#include <sstream> 
#include "Tools.h"
int MultiplyMatris(int** map,int** key,int row,int col,int& keySize){

    int sum = 0; //summation
    int keycol = 0; // column for key matris
    int keyrow = 0; // row for key matris

    for (int i = row; i < (row + keySize); i++)
    {        
        keycol = 0; // have to reset the keycol 
        for (int j = col; j < (col + keySize); j++)
        {
            sum += map[i][j] * key[keyrow][keycol]; //adding to sum
            keycol++;
        }
        keyrow++;
    }
    
    if (sum < 0)return sum + 5; //if sum is negative

    return sum;  //else
} 
void Printer(int expectedDirection,int realDirection, int summation,ofstream &outputFile){
    outputFile << expectedDirection << "," << realDirection << ":" << summation << endl;
}
void printArray(int** arr, int row, int col){
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
}
void assignArray(ifstream &file,int** arr,int row,int col){
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            file >> arr[i][j];
        }
    }
}
void createArray(int** arr,int col) {
    for (int i = 0; i < col; i++){
            arr[i] = new int[col];
        }
}
void deleteArray(int** arr,int row){
    for (int i = 0; i < row; i++){
            delete[] arr[i];
        }
    delete[] arr;
}
void Stroll(int** map,int** key,int row,int col, int mapRow,int mapCol,int keyRow,int keyCol,ofstream &outputFile,int& keySize){

    //center of sub matrix
    int subMatrixRow = row + ((keyRow - 1) / 2); 
    int subMatrixCol = col + ((keyCol - 1) / 2);

    // sum of matris
    int summation = MultiplyMatris(map,key,row,col,keySize);

    //Directions
    int expectedDirection = summation % 5;
    int realDirection;

    Printer(subMatrixRow,subMatrixCol,summation,outputFile); //Writing to output file

    switch (expectedDirection)
    {
    case 0:
        return;
        break;
    
    case 1:
        if (row > 0) realDirection = expectedDirection; // if we can move right, then we will.
        else realDirection = 2;   // if we can't move right, then we will move to left.
        break;
    
    case 2:
        if (row + keyRow < mapRow)realDirection = expectedDirection; // if we can move left, then we will.
        else realDirection = 1; // if we can't move right, then we will move to right.
        break;
    
    case 3:
        if (col + keyCol < mapCol) realDirection = expectedDirection; // if we can move up, then we will.
        else realDirection = 4; // if we can't move up, then we will move to down.
        break;
    
    case 4:
        if (col > 0) realDirection = expectedDirection; // if we can move down, then we will.
        else realDirection = 3; // if we can't move down, then we will move to up.
        break;
    }
    switch (realDirection)
    {
    case 1:
        Stroll(map,key,row - keyRow,col,mapRow,mapCol,keyRow,keyCol,outputFile,keySize);
        break;
    case 2:
        Stroll(map,key,row + keyRow,col,mapRow,mapCol,keyRow,keyCol,outputFile,keySize);
        break;
    case 3:
        Stroll(map,key,row,col + keyCol,mapRow,mapCol,keyRow,keyCol,outputFile,keySize);
        break;
    case 4:
        Stroll(map,key,row,col - keyCol,mapRow,mapCol,keyRow,keyCol,outputFile,keySize);
        break;
    }
}