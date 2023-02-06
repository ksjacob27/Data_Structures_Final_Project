#include <string>
#include <iostream>

using namespace std;

int main(){

    addFileName = "test.txt";

    string tempFileVersion = "00";

    stoi(tempFileVersion);

    tempFileVersion++;

    itos(tempFileVersion);

    string outfileName = tempFileVersion + "_" + addFileName;

    cout << outfileName << endl;



}