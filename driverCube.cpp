#include <iostream>
#include "RubiksCube.h"
using namespace std;

int main()
{
    
    RubiksCube a1; // Constructor initializes the cube
    a1.setCube();
    a1.displayFaces();
    cout << endl;
    a1.userInput();

    return 0;
}