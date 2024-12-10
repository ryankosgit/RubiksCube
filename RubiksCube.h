//rubikscube.h
#include <iostream>
using namespace std;

class RubiksCube
{
public:
    // Face color constants
    const string red = "\033[41m  \033[0m";
    const string green = "\033[42m  \033[0m";
    const string blue = "\033[44m  \033[0m";
    const string yellow = "\033[48;2;255;255;0m  \033[0m"; 
    const string white = "\033[48;2;255;255;255m  \033[0m"; 
    const string orange = "\033[48;2;255;165;0m  \033[0m"; 


    // Public methods
    void setCube(); // Initialize the cube
    void displayFaces();
    void userInput();
    void executeScramble();

    // Movements
    void turnRight();
    void turnRightP();
    void turnLeft();
    void turnLeftP();
    void turnUp();
    void turnUpP();
    void turnDown();
    void turnDownP();
    void turnBack();
    void turnBackP();
    void turnFront();
    void turnFrontP();

private:
    // Cube faces
    bool userTrue;
    bool generatedScramble;
    string userInputStr;
    string frontface[3][3];
    string upface[3][3];
    string rightface[3][3];
    string leftface[3][3];
    string downface[3][3];
    string backface[3][3];
    string scrambleinput;
};
