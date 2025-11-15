# Rubik's Cube Simulator

This is a simulation of a 3x3 Rubik's Cube. This project leverages object-oriented programming fundamentals for the cube's design and functionality. Use the terminal to write commands using Rubik's Cube notation that decide the cube's movements, or you can scramble it using an algorithm I built that follows the official World Cube Association scrambling rules. 
**Also, your compiler needs to support C++11 or higher to run.**

# Files
```
RubiksCube.cpp  # Main file that defines all of the functions
RubiksCube.h    # Header file that contains the declarations
driverCube.cpp  # Driver that runs the program
makefile        # makefile for easy running
README.md       # README
```
# Setup + Run

To setup the program, first download the two .cpp files, thet header, and the makefilfe. Then, compile the files together using these functions. You have two options:

## Option 1: With the makefile (recommended)

```bash
make      # Builds the executable 'rubik'
./rubik   # Runs the program
```
## Option 2: Manual compilation

### MacOS/Linux 
```
g++ driverCube.cpp RubiksCube.cpp -o cube
```
```
./cube
```

### Windows
```
g++ driverCube.cpp RubiksCube.cpp -o cube.exe
```
```
cube.exe
```

You should now see the cube and its colored faces.

<img width="635" alt="DemoPic" src="https://github.com/user-attachments/assets/fecc1a66-6326-4527-906d-c8587b8b9985" />

# How to Turn the Cube

Now we can get to the fun part...turning the cube!
First, it's important to understand the notation of the cube. The Rubik's Cube has 6 faces, each represented by a letter
```
R = Right Face 
L = Left Face
F = Front Face 
B = Back Face 
U = Up Face 
D = Down Face 
```
On a physical Rubik's Cube, these notations change relative to how you're holding the cube. In our program, however, since the green side is facing forward and the white face is on top, our notation is fixed to that position. Also note that the program is not case-sensitive, and if you enter an unrecognized character in the terminal, then the program will simply ignore it and carry on with the other executable moves. Using spaces or not doesn't change the cube's movements, but note that if you add spaces in between your notations, the program will print each move that you make individually.

```
R - Turns right face clockwise 
L = Turns left face clockwise
F = Turns front face clockwise 
B = Turns back face clockwise 
U = Turns up face clockwise 
D = Turns down face clockwise 
```

### Move Modifiers
(No symbol) — 90° clockwise
Example: ```F``` means turn the front (green) face 90° clockwise.

<img width="752" alt="Screenshot 2025-06-26 at 11 53 24 AM" src="https://github.com/user-attachments/assets/d3c220bd-1fa0-4973-acd7-c7583063ca73" />

' (Prime) — 90° counterclockwise
Example: ```F'``` means turn the front face 90° counterclockwise.

<img width="605" alt="Screenshot 2025-06-26 at 11 53 58 AM" src="https://github.com/user-attachments/assets/ecb7ca7d-25e5-4e7a-9060-ee503a022f98" />

2 — 180° turn (clockwise or counterclockwise, same result)
Example: ```F2``` means turn the front face 180°.

<img width="600" alt="Screenshot 2025-06-26 at 11 54 21 AM" src="https://github.com/user-attachments/assets/6a965ad5-15c6-4e0c-b1c6-3cc8905ded5a" />

#### Here are some example moves
```RUR'U'```

<img width="601" alt="Screenshot 2025-06-26 at 12 19 16 PM" src="https://github.com/user-attachments/assets/b596c1b3-a407-4275-83df-b35d0d602510" />

```L' B2```

<img width="604" alt="Screenshot 2025-06-26 at 12 24 03 PM" src="https://github.com/user-attachments/assets/f9c0185c-6f9e-49a4-b135-e9e7ad557f0b" />


### Other Tools
You can also scramble the cube using a scrambling algorithm used in official Rubik's Cube Tournaments by simply entering ```scramble``` into the terminal. From here, it tells you the moves executed to scramble the cube. Here's an example:

```scramble```

<img width="717" alt="Screenshot 2025-06-26 at 12 24 59 PM" src="https://github.com/user-attachments/assets/3c4bdc8a-2ed4-4b20-8242-ac1432502835" />


# How to Exit

To stop the program, simply enter ```stop``` into the terminal.







