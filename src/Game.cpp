#include "Tools.h"
int main(int argc, char** argv)
{
    // Getting map size    
    stringstream ss(argv[1]);
    string token;
    int mapSize[2];
    int i = 0;
    while(getline(ss, token, 'x')) {
        stringstream sas; 
        sas << token;
        sas >> mapSize[i];
        i++;
    }

    //creating map pointer   
    int mapRow = mapSize[0];
    int mapCol = mapSize[1];
    int **map = new int*[mapRow];
    createArray(map,mapCol);
    

    //creating key pointer
    int keyRow;
    stringstream converter;
    converter << argv[2];
    converter >> keyRow;
    int keyCol = keyRow;
    int **key = new int*[keyRow];
    createArray(key,keyCol);  

    
    ifstream mapFile(argv[3]); //open the map file to perform read operation using file object
    ifstream keyFile(argv[4]); //open the key file to perform read operation using file object
    ofstream outputFile(argv[5]); //open the output file to perform write operation using file object

    //Assigning data into arrays
    assignArray(mapFile,map,18,18);
    assignArray(keyFile,key,3,3);

    //Starting the game
    Stroll(map,key,0,0,mapRow,mapCol,keyRow,keyCol,outputFile,keyRow);

    //Deleting all the arrays
    deleteArray(map,18);
    deleteArray(key,3);
    return 0;
}