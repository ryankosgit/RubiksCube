//rubikscube.cpp
#include <iostream>
#include "RubiksCube.h"
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <set>
using namespace std;

RubiksCube::RubiksCube()
{
    for (int a = 0; a < 3; a++)
    {
        for(int b = 0; b < 3; b++)
        {
            frontface[a][b] = green;
            upface[a][b] = white;
            rightface[a][b] = red;
            leftface[a][b] = orange;
            upface[a][b] = white;
            backface[a][b] = blue;
            downface[a][b] = yellow;
        }
    }
};

void RubiksCube::displayFaces()
{
    cout << "\n";
    for (int a = 0; a < 3; a++)
        {
            for (int x = 0; x < 3; x++)
                cout << " " << " ";

            for(int b = 0; b < 3; b++)
                cout << upface[a][b];
            
            cout << endl;
    }



    for (int a = 0; a < 3; a++)
            {
                for(int b = 0; b < 3; b++)
                    cout << leftface[a][b] ;

                for(int c = 0; c < 3; c++)
                    cout << frontface[a][c] ;

                for(int d = 0; d < 3; d++)
                    cout << rightface[a][d];

                for(int e = 0; e < 3; e++)
                    cout << backface[a][e] ;
                
                cout << endl;
        }


    for (int a = 0; a < 3; a++)
    {
        for (int x = 0; x < 3; x++)
            cout << " " << " ";

        for(int b = 0; b < 3; b++)
            cout << downface[a][b];
        
        cout << endl;

    }



};

void RubiksCube::userInput()
{
    
    set<char> okInput;
    userTrue = true;
    

    okInput.insert('R');
    okInput.insert('L');
    okInput.insert('U');
    okInput.insert('D');
    okInput.insert('F');
    okInput.insert('B');
    okInput.insert('\'');
    okInput.insert('2');

    cout << "Welcome to the Rubik's Cube in C++! ";
    do
    {
        cout << "Type \"scramble\" to scramble, or type some notation \n(ex: R U' F2 B) to move the cube! \nType \"stop\" to quit. \n" << endl;
        cin >> userInputStr;

        for(int i = 0; i < userInputStr.length(); i++)
        {
            userInputStr[i] = toupper(userInputStr[i]);
        }

        if(userInputStr == "STOP")
            userTrue = false;
        else if (userInputStr == "SCRAMBLE")
        {
            const char faces[] = {'R', 'L', 'U', 'D', 'F', 'B'};
            const char modifiers[] = {' ', '\'', '2'};
            scrambleinput = "";
            userInputStr = "";
            generatedScramble = true;


            srand(time(0)); 

            char lastMove = '\0';


    
               for (int i = 0; i < 20; i++) 
            {
                    char face;
                do 
                {
                    face = faces[rand() % 6]; 
                }while (face == lastMove); 

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

                lastMove = face; 
            } 
            

            userInputStr = scrambleinput;    

            RubiksCube::executeScramble();
            cout << "Scramble: " << userInputStr << "\n";
             
        }
        else
        {
            generatedScramble = false;
            RubiksCube::executeScramble();

        }
        

     


    }while(userTrue == true);
    cout << "Thanks for playing!" ;
};

void RubiksCube::executeScramble()
{
    set<char> okInput;
    userTrue = true;


    okInput.insert('R');
    okInput.insert('L');
    okInput.insert('U');
    okInput.insert('D');
    okInput.insert('F');
    okInput.insert('B');
    okInput.insert('\'');
    okInput.insert('2');




for(int i = 0; i < userInputStr.length(); i++)
            {
                userInputStr[i] = toupper(userInputStr[i]);
            }
            

            for(int i = 0; i < userInputStr.length(); i++)
                    {
                        userInputStr[i] = toupper(userInputStr[i]);
                    }


                if(generatedScramble == false)
                {
                    for(int k = 0; k < userInputStr.length(); k++)
                {
                    if (okInput.find(userInputStr[k]) == okInput.end())
                    {
                        cout << "There is an unidentified character in the input: " << userInputStr[k] << "! \n";
                    }            

                }  

                }
                

                    
                for (int x = 0; x < userInputStr.length(); x++)
                {
                    if (userInputStr.length() == 1)
                    {
                        if (userInputStr[x] == 'R')
                        RubiksCube::turnRight();
                        
                        else if (userInputStr[x] == 'L')
                        RubiksCube::turnLeft();

                        else if(userInputStr[x] == 'U')
                        RubiksCube::turnUp();

                        else if(userInputStr[x] == 'F')
                        RubiksCube::turnFront();

                        else if(userInputStr[x] == 'D')
                        RubiksCube::turnDown();

                        else if(userInputStr[x] == 'B')
                        RubiksCube::turnBack();

                        else cout << "There is an unidentified character in the input: " << userInputStr[0];
                    }
                    else
                    {
                        
                        if (userInputStr[x] == 'R' && userInputStr[x + 1] == '2') 
                        {
                        RubiksCube::turnRight();
                        RubiksCube::turnRight();
                        }
                        else if (userInputStr[x] == 'R' && userInputStr[x + 1] == '\'') 
                        {
                            RubiksCube::turnRightP();
                        } 
                        else if (userInputStr[x] == 'R' && userInputStr[x + 1] != '\'' && userInputStr[x + 1] != '2') 
                        {
                            RubiksCube::turnRight();
                        }
                        else if (userInputStr[x] == 'L' && userInputStr[x + 1] == '2') 
                        {
                            RubiksCube::turnLeft();
                            RubiksCube::turnLeft();
                        } 
                        else if (userInputStr[x] == 'L' && userInputStr[x + 1] == '\'') 
                        {
                            RubiksCube::turnLeftP();
                        } 
                        else if (userInputStr[x] == 'L' && userInputStr[x + 1] != '\'' && userInputStr[x + 1] != '2') 
                        {
                            RubiksCube::turnLeft();
                        } 
                        else if (userInputStr[x] == 'U' && userInputStr[x + 1] == '2') 
                        {
                            RubiksCube::turnUp();
                            RubiksCube::turnUp();
                        } 
                        else if (userInputStr[x] == 'U' && userInputStr[x + 1] == '\'') 
                        {
                            RubiksCube::turnUpP();
                        } 
                        else if (userInputStr[x] == 'U' && userInputStr[x + 1] != '\'' && userInputStr[x + 1] != '2') 
                        {
                            RubiksCube::turnUp();
                        } 
                        else if (userInputStr[x] == 'D' && userInputStr[x + 1] == '2') 
                        {
                            RubiksCube::turnDown();
                            RubiksCube::turnDown();
                        } 
                        else if (userInputStr[x] == 'D' && userInputStr[x + 1] == '\'') 
                        {
                            RubiksCube::turnDownP();
                        } 
                        else if (userInputStr[x] == 'D' && userInputStr[x + 1] != '\'' && userInputStr[x + 1] != '2') 
                        {
                            RubiksCube::turnDown();
                        } 
                        else if (userInputStr[x] == 'F' && userInputStr[x + 1] == '2') 
                        {
                            RubiksCube::turnFront();
                            RubiksCube::turnFront();
                        } 
                        else if (userInputStr[x] == 'F' && userInputStr[x + 1] == '\'') 
                        {
                            RubiksCube::turnFrontP();
                        } 
                        else if (userInputStr[x] == 'F' && userInputStr[x + 1] != '\'' && userInputStr[x + 1] != '2') 
                        {
                            RubiksCube::turnFront();
                        } 
                        else if (userInputStr[x] == 'B' && userInputStr[x + 1] == '2') 
                        {
                            RubiksCube::turnBack();
                            RubiksCube::turnBack();
                        } 
                        else if (userInputStr[x] == 'B' && userInputStr[x + 1] == '\'') 
                        {
                            RubiksCube::turnBackP();
                        } 
                        else if (userInputStr[x] == 'B' && userInputStr[x + 1] != '\'' && userInputStr[x + 1] != '2') 
                        {
                            RubiksCube::turnBack();
                        }
                        if(userInputStr[x] == '\'')
                            cout << "";
                        else if(userInputStr[x] == ' ')
                            cout << "";
                    
                    }
        }

        RubiksCube::displayFaces();
};

void RubiksCube::turnRight()
{
    //frontface temp var
    string temparray[3];
    for(int x = 0; x < 3; x++)
    {
        temparray[x] = frontface[x][2];  //temp
        frontface[x][2] = downface[x][2]; //yellow on green
        downface[x][2] = backface[2 - x][0]; //blue on yellow
        backface[2 - x][0] = upface[x][2]; //white on blue
        upface[x][2] = temparray[x]; //green on white
    }



    //sideface redface turn 
    string cornertemp = rightface[0][0]; //left corner stash in temp
    string edgetemp = rightface[0][1]; //edge temp

    rightface[0][0] = rightface[2][0];
    rightface[0][1] = rightface[1][0];

    rightface[2][0] = rightface[2][2];
    rightface[1][0] = rightface[2][1];

    rightface[2][1] = rightface[1][2];
    rightface[2][2] = rightface[0][2];

    rightface[1][2] = edgetemp;
    rightface[0][2] = cornertemp;

};

void RubiksCube::turnRightP()
{
    //frontface temp var
    string temparray[3];
    for(int x = 0; x < 3; x++)
    {
        temparray[x] = frontface[x][2];
        frontface[x][2] = upface[x][2]; //white on green
        upface[x][2] = backface[2 - x][0];    //blue on white
        backface[2 - x][0] = downface[x][2]; //yellow on blue
        downface[x][2] = temparray[x];   //green on yellow
    }

    //sideface redface turn counter clockwise
    string cornertemp = rightface[0][0]; //left corner stash in temp
    string edgetemp = rightface[0][1]; //edge temp

    rightface[0][0] = rightface[0][2];
    rightface[0][1] = rightface[1][2];

    rightface[0][2] = rightface[2][2];
    rightface[1][2] = rightface[2][1];

    rightface[2][2] = rightface[2][0];
    rightface[2][1] = rightface[1][0];

    rightface[1][0] = edgetemp;
    rightface[2][0] = cornertemp;
};

void RubiksCube::turnLeft()
{
        
    string temparray[3];
    for(int x = 0; x < 3; x++)
    {
        temparray[x] = frontface[x][0];  //frontface temp var
        frontface[x][0] = upface[x][0];  //white on green
        upface[x][0] = backface[2-x][2];  //blue on white
        backface[2-x][2] = downface[x][0]; //yellow on blue
        downface[x][0] = temparray[x]; //green on yellow
    }

    string cornertemp = leftface[0][0]; //left corner stash in temp
    string edgetemp = leftface[0][1]; //edge temp

    leftface[0][0] = leftface[2][0];
    leftface[0][1] = leftface[1][0];

    leftface[2][0] = leftface[2][2];
    leftface[1][0] = leftface[2][1];

    leftface[2][1] = leftface[1][2];
    leftface[2][2] = leftface[0][2];

    leftface[1][2] = edgetemp;
    leftface[0][2] = cornertemp;


   

};

void RubiksCube::turnLeftP()
{
//leftprime

 //frontface temp var
    string temparray[3];
    for(int x = 0; x < 3; x++)
    {
        temparray[x] = frontface[x][0]; //front temp
        frontface[x][0] = downface[x][0]; //yellow on green
        downface[x][0] = backface[2-x][2]; //blue on yellow
        backface[2-x][2] = upface[x][0]; //white on blue
        upface[x][0] = temparray[x]; //green on white
    }

    string cornertemp = leftface[0][0]; 
    string edgetemp = leftface[0][1]; 
    leftface[0][0] = leftface[0][2];
    leftface[0][1] = leftface[1][2];

    leftface[0][2] = leftface[2][2];
    leftface[1][2] = leftface[2][1];

    leftface[2][2] = leftface[2][0];
    leftface[2][1] = leftface[1][0];

    leftface[1][0] = edgetemp;
    leftface[2][0] = cornertemp;
};

void RubiksCube::turnUp()
{

    string temparray[3];

    for(int x = 0; x < 3; x++)
    {
        temparray[x] = frontface[0][x];  //frontface temp var
        frontface[0][x] = rightface[0][x];  //white on green
        rightface[0][x] = backface[0][x];  //blue on white
        backface[0][x] = leftface[0][x]; //yellow on blue
        leftface[0][x] = temparray[x]; //green on yellow
    }

    string cornertemp = upface[0][0]; //left corner stash in temp
    string edgetemp = upface[0][1]; //edge temp

    upface[0][0] = upface[2][0];
    upface[0][1] = upface[1][0];

    upface[2][0] = upface[2][2];
    upface[1][0] = upface[2][1];

    upface[2][1] = upface[1][2];
    upface[2][2] = upface[0][2];

    upface[1][2] = edgetemp;
    upface[0][2] = cornertemp;
};

void RubiksCube::turnUpP()
{
    string temparray[3];

    for(int x = 0; x < 3; x++)
    {
        temparray[x] = frontface[0][x];  //frontface temp var
        frontface[0][x] = leftface[0][x]; 
        leftface[0][x] = backface[0][x];  
        backface[0][x] = rightface[0][x]; 
        rightface[0][x] = temparray[x];
    }

   string cornertemp = upface[0][0]; 
    string edgetemp = upface[0][1]; 
    upface[0][0] = upface[0][2];
    upface[0][1] = upface[1][2];

    upface[0][2] = upface[2][2];
    upface[1][2] = upface[2][1];

    upface[2][2] = upface[2][0];
    upface[2][1] = upface[1][0];

    upface[1][0] = edgetemp;
    upface[2][0] = cornertemp;





};

void RubiksCube::turnFront()
{

    string temparray[3];

for(int x = 0; x < 3; x++)
    {
        temparray[x] = upface[2][x];  //frontface temp var
        upface[2][x] = leftface[2 - x][2];  
        leftface[2 - x][2] = downface[0][2-x];  
        downface[0][2-x] = rightface[x][0]; 
        rightface[x][0] = temparray[x]; 
    }


  string cornertemp = frontface[0][0]; //left corner stash in temp
    string edgetemp = frontface[0][1]; //edge temp

    frontface[0][0] = frontface[2][0];
    frontface[0][1] = frontface[1][0];

    frontface[2][0] = frontface[2][2];
    frontface[1][0] = frontface[2][1];

    frontface[2][1] = frontface[1][2];
    frontface[2][2] = frontface[0][2];

    frontface[1][2] = edgetemp;
    frontface[0][2] = cornertemp;

};

void RubiksCube::turnFrontP()
{
string temparray[3];

for(int x = 0; x < 3; x++)
    {
        temparray[x] = upface[2][x];  
        upface[2][x] = rightface[x][0];  
        rightface[x][0] = downface[0][2-x]; 
        downface[0][2-x] = leftface[2-x][2]; 
        leftface[2 - x][2] = temparray[x]; 
    }

    string cornertemp = frontface[0][0]; 
    string edgetemp = frontface[0][1]; 
    frontface[0][0] = frontface[0][2];
    frontface[0][1] = frontface[1][2];

    frontface[0][2] = frontface[2][2];
    frontface[1][2] = frontface[2][1];

    frontface[2][2] = frontface[2][0];
    frontface[2][1] = frontface[1][0];

    frontface[1][0] = edgetemp;
    frontface[2][0] = cornertemp;
};

void RubiksCube::turnDown()
{
    string temparray[3];

for(int x = 0; x < 3; x++)
    {
        temparray[x] = frontface[2][x];  //frontface temp var
        frontface[2][x] = leftface[2][x];  
        leftface[2][x] = backface[2][x];  
        backface[2][x] = rightface[2][x]; 
        rightface[2][x] = temparray[x]; 
    }



 

    string cornertemp = downface[0][0]; //left corner stash in temp
    string edgetemp = downface[0][1]; //edge temp

    downface[0][0] = downface[2][0];
    downface[0][1] = downface[1][0];

    downface[2][0] = downface[2][2];
    downface[1][0] = downface[2][1];

    downface[2][1] = downface[1][2];
    downface[2][2] = downface[0][2];

    downface[1][2] = edgetemp;
    downface[0][2] = cornertemp;
};

void RubiksCube::turnDownP()
{
string temparray[3];

       for(int x = 0; x < 3; x++)
    {
        temparray[x] = frontface[2][x];  
        frontface[2][x] = rightface[2][x];  
        rightface[2][x] = backface[2][x];  
        backface[2][x] = leftface[2][x]; 
        leftface[2][x] = temparray[x]; 
    }

    string cornertemp = downface[0][0]; 
    string edgetemp = downface[0][1]; 
    downface[0][0] = downface[0][2];
    downface[0][1] = downface[1][2];

    downface[0][2] = downface[2][2];
    downface[1][2] = downface[2][1];

    downface[2][2] = downface[2][0];
    downface[2][1] = downface[1][0];

    downface[1][0] = edgetemp;
    downface[2][0] = cornertemp;

};

void RubiksCube::turnBack()
{

string temparray[3];

for(int x = 0; x < 3; x++)
    {
        temparray[x] = upface[0][x];  
        upface[0][x] = rightface[x][2];  
        rightface[x][2] = downface[2][2-x]; 
        downface[2][2-x] = leftface[2-x][0]; 
        leftface[2 - x][0] = temparray[x]; 
    }



  string cornertemp = backface[0][0]; //left corner stash in temp
    string edgetemp = backface[0][1]; //edge temp

    backface[0][0] = backface[2][0];
    backface[0][1] = backface[1][0];

    backface[2][0] = backface[2][2];
    backface[1][0] = backface[2][1];

    backface[2][1] = backface[1][2];
    backface[2][2] = backface[0][2];

    backface[1][2] = edgetemp;
    backface[0][2] = cornertemp;

};

void RubiksCube::turnBackP()
{

string temparray[3];

for(int x = 0; x < 3; x++)
    {
        temparray[x] = upface[0][x];  //frontface temp var
        upface[0][x] = leftface[2 - x][0];  
        leftface[2 - x][0] = downface[2][2-x];  
        downface[2][2-x] = rightface[x][2]; 
        rightface[x][2] = temparray[x]; 
    }


    string cornertemp = backface[0][0]; 
    string edgetemp = backface[0][1]; 
    backface[0][0] = backface[0][2];
    backface[0][1] = backface[1][2];

    backface[0][2] = backface[2][2];
    backface[1][2] = backface[2][1];

    backface[2][2] = backface[2][0];
    backface[2][1] = backface[1][0];

    backface[1][0] = edgetemp;
    backface[2][0] = cornertemp;



};

