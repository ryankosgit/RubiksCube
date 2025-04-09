//rubiks cube cpp
#define whiteface 0
#define yellowface 1
#define redface 2
#define orangeface 3
#define blueface 4
#define greenface 5

#include "RubiksCube.h"
#include <iostream>
#include <ctime>
#include <set>
using namespace std;

RubiksCube::RubiksCube(){
    for(int x = 0; x < 6; x++){
        for(int y = 0; y < 3; y++){
            for(int z = 0; z < 3; z++){
                cube[y][z][x] = colors[x];
            }
        }
    }
};

void RubiksCube::rotateLayer(int face, bool clockwise) {

    if (clockwise) {
        rotateFace(face);
    } 
    else {
        rotateFacePrime(face);
    }

    switch(face) {
        case(0): 
        for(int x = 0; x < 3; x++) {
            if(clockwise) {
                swap(cube[0][x][greenface], cube[0][x][redface]);
                swap(cube[0][x][redface], cube[0][x][blueface]);
                swap(cube[0][x][blueface], cube[0][x][orangeface]);
            } 
            else {
                swap(cube[0][x][blueface], cube[0][x][orangeface]);
                swap(cube[0][x][redface], cube[0][x][blueface]);
                swap(cube[0][x][greenface], cube[0][x][redface]);
            }
        }
        break;
        case(1):
        for(int x = 0; x < 3; x++) {
            if(clockwise) {
                swap(cube[2][x][orangeface], cube[2][x][blueface]);
                swap(cube[2][x][blueface], cube[2][x][redface]);
                swap(cube[2][x][redface], cube[2][x][greenface]);
            } 
            else {
                swap(cube[2][x][redface], cube[2][x][greenface]);
                swap(cube[2][x][blueface], cube[2][x][redface]);
                swap(cube[2][x][orangeface], cube[2][x][blueface]);
            }
        }
        break;
        case(2):
        for(int x = 0; x < 3; x++) {
            if(clockwise) {
                swap(cube[x][2][greenface], cube[x][2][whiteface]);
                swap(cube[x][2][greenface], cube[x][2][yellowface]);
                swap(cube[2-x][0][blueface], cube[x][2][yellowface]);
            } 
            else {
                swap(cube[2-x][0][blueface], cube[x][2][yellowface]);
                swap(cube[x][2][greenface], cube[x][2][yellowface]);
                swap(cube[x][2][greenface], cube[x][2][whiteface]);
            }
        }
        break;
        case(3):
        for(int x = 0; x < 3; x++) {
            if(clockwise) {
                swap(cube[x][0][greenface], cube[x][0][whiteface]);
                swap(cube[x][0][whiteface], cube[2-x][2][blueface]);
                swap(cube[2-x][2][blueface], cube[x][0][yellowface]);
            } 
            else {
                swap(cube[2-x][2][blueface], cube[x][0][yellowface]);
                swap(cube[x][0][whiteface], cube[2-x][2][blueface]);
                swap(cube[x][0][greenface], cube[x][0][whiteface]);
            }
        }
        break;
        case(4):
        for(int x = 0; x < 3; x++) {
            if(clockwise) {
                swap(cube[0][x][whiteface], cube[x][2][redface]);
                swap(cube[x][2][redface], cube[2][2-x][yellowface]);
                swap(cube[2][2-x][yellowface], cube[2-x][0][orangeface]);
            } 
            else {
                swap(cube[2][2-x][yellowface], cube[2-x][0][orangeface]);
                swap(cube[x][2][redface], cube[2][2-x][yellowface]);
                swap(cube[0][x][whiteface], cube[x][2][redface]);
            }
        }
        break;
        case(5): 
    for (int i = 0; i < 3; i++) {
        if (clockwise) {
            swap(cube[2][2 - i][whiteface], cube[i][2][orangeface]);
            swap(cube[i][2][orangeface], cube[0][i][yellowface]);
            swap(cube[0][i][yellowface], cube[2-i][0][redface]);
        } else {
            swap(cube[0][i][yellowface], cube[2-i][0][redface]);
            swap(cube[i][2][orangeface], cube[0][i][yellowface]);
            swap(cube[2][2 - i][whiteface], cube[i][2][orangeface]);
        }
    }
    break;

    }
}

void RubiksCube::clockwise(int x) {
    rotateLayer(x, true);
}

void RubiksCube::counterclockwise(int x) {
    rotateLayer(x, false);
}

void RubiksCube::rotateFace(int x){
    swap(cube[0][0][x], cube[2][0][x]);
    swap(cube[2][0][x], cube[2][2][x]);
    swap(cube[2][2][x], cube[0][2][x]);
    swap(cube[1][0][x], cube[2][1][x]);
    swap(cube[2][1][x], cube[1][2][x]);
    swap(cube[1][2][x], cube[0][1][x]);
}

void RubiksCube::rotateFacePrime(int x){

    swap(cube[0][0][x], cube[0][2][x]);
    swap(cube[0][2][x], cube[2][2][x]);
    swap(cube[2][2][x], cube[2][0][x]);
    swap(cube[0][1][x], cube[1][2][x]);
    swap(cube[1][2][x], cube[2][1][x]);
    swap(cube[2][1][x], cube[1][0][x]);

};

void RubiksCube::display() const
{
    cout << "\n";
    for (int a = 0; a < 3; a++) {
        cout << "      ";
        for (int b = 0; b < 3; b++)
            cout << cube[a][b][whiteface];
        cout << endl;
    }
    
    for (int a = 0; a < 3; a++) {
        for (int face : {orangeface, greenface, redface, blueface})
            for (int b = 0; b < 3; b++)
                cout << cube[a][b][face];
        cout << endl;
    }
    
    for (int a = 0; a < 3; a++) {
        cout << "      ";
        for (int b = 0; b < 3; b++)
            cout << cube[a][b][yellowface];
        cout << endl;
    }
    
};

void RubiksCube::userinput(){

    userinputbool = true;

    do{
    cout << "Type \"scramble\" to scramble, or type some notation \n(ex: R U' F2 B) to move the cube! \nType \"stop\" to quit. \n" << endl;
    cin >> userInputStr;

    for(int i = 0; i < userInputStr.length(); i++)
    {
        userInputStr[i] = toupper(userInputStr[i]);
    }

    if(userInputStr == "STOP")
        userinputbool = false;
    else if(userInputStr == "SCRAMBLE")
    {
        const char faces[] = {'R', 'L', 'U', 'D', 'F', 'B'};
        const char modifiers[] = {' ', '\'', '2'};
        scrambleinput = "";
        generatedScramble = true;
        srand(time(0)); 

        char lastmove = '\0';

        for(int i = 0; i < 20; i++) 
            {
                char face;
                do 
                {
                    face = faces[rand() % 6]; 
                }while (face == lastmove); 

                char modifier = modifiers[rand() % 3]; 

                scrambleinput += face; 
                if (modifier != ' ') 
                {
                    scrambleinput += modifier;
                }   
                if (i < 19) 
                { 
                    scrambleinput += ' ';
                }
                lastmove = face; 
            } 

        userInputStr = scrambleinput;    

        RubiksCube::executeScramble(userInputStr);
        cout << "Scramble: " << userInputStr << "\n";
             
    }
    else
    {
        generatedScramble = false;
        RubiksCube::executeScramble(userInputStr);
    }
}while(userinputbool == true);
};

void RubiksCube::executeScramble(string x){
    set<char> okInput = {'R', 'L', 'U', 'D', 'F', 'B', '\'', '2'};

    for(size_t i = 0; i < userInputStr.length(); i++) {
        char move = userInputStr[i];
        bool clockwise = true;
        bool twice = false;
        
        if(i + 1 < userInputStr.length()) {
            if(userInputStr[i + 1] == '\'') {
                clockwise = false;
                i++;
            } 
            else if(userInputStr[i + 1] == '2') {
                twice = true;
                i++;
            }
        }

        int face;
        switch(move) {
            case 'U': face = 0; break;
            case 'D': face = 1; break;
            case 'R': face = 2; break;
            case 'L': face = 3; break;
            case 'B': face = 4; break;
            case 'F': face = 5; break;
            case ' ': continue;
            default: continue;
        }

        rotateLayer(face, clockwise);
        if(twice) {
            rotateLayer(face, clockwise);
        }
    }
    
    display();
}
