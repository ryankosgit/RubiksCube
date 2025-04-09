//rubiks cube .h
#include <string>
using namespace std;

class RubiksCube{
public:
    RubiksCube();
    void counterclockwise(int x);
    void clockwise(int x);
    void display() const;
    void userinput();
    void executeScramble(string x);
    void rotateLayer(int face, bool clockwise);

private:
    string cube[3][3][6];
    bool userinputbool;
    string userInputStr;
    bool generatedScramble;
    string scrambleinput;
    void rotateFace(int x);
    void rotateFacePrime(int x);
    const string red = "\033[41m  \033[0m";
    const string green = "\033[42m  \033[0m";
    const string blue = "\033[44m  \033[0m";
    const string yellow = "\033[48;2;255;255;0m  \033[0m"; 
    const string white = "\033[48;2;255;255;255m  \033[0m"; 
    const string orange = "\033[48;2;255;165;0m  \033[0m"; 
    string colors[6] = {white, yellow, red, orange, blue, green};
};
