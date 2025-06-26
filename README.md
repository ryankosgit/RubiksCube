# Rubik's Cube Simulator

This is a simulation built in C++ of a 3x3 Rubik's Cube. The user can utilize the terminal to write commands using Rubik's Cube notation that  decide the cube's move, or can scramble it using an algorithm I built that follows the official World Cube Association scrambling rules.

# Files
```
RubiksCube.cpp  # Main file that defines all of the functions
RubiksCube.h    # Header file that contains the declarations
driverCube.cpp  # Driver that runs the program
README.md       # README
```
# Setup + Run

To setup the program, first download the two .cpp files and the header. Then, compile the files together using these functions

## Mac - Use these if you're on a Macbook
```g++ driverCube.cpp RubiksCube.cpp -o cube```
```./cube```

## Windows - Use these if you're on a Windows computer
```g++ driverCube.cpp RubiksCube.cpp -o cube.exe```
```cube.exe```

You should now see the cube and its colored faces.

