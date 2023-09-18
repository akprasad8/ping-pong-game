# Pong Game Replica

This repository contains a C++ implementation of a Pong game replica using the Simple and Fast Multimedia Library (SFML). The game adheres to a specific assignment with various features and requirements.

## Assignment Overview

### Features and Requirements

1. **Main Menu Screen**: The game starts with a Main Menu Screen featuring:
   - A background image stretched according to the size of the window.
   - Play Button
   - Quit Button

2. **Player Controls**:
   - Player 1: Arrow keys (⬆️ for up, ⬇️ for down)
   - Player 2: 'W' and 'S' keys

3. **Game Rules**:
   - The game is a best-of-5 matches.
   - The first player to score 5 points wins.

4. **Game Over Screen**: When the game ends, a basic game over screen displays the winner and loser.

5. **Code Quality**:
   - Code adheres to Object-Oriented Programming (OOP) and SOLID principles.
   - Code is well-documented with clear naming conventions.
   - Emphasis on code readability.

6. **Core Elements**:
   - Player movements are framerate-independent and smooth.
   - Ball movement is framerate-independent and smooth.
   - Score logic and game win/lose conditions are implemented.

7. **Audio**:
   - Background music plays when the game starts.
   - Sound effects for ball collisions and button clicks are implemented.

8. **Player Names**:
   - Player names are not required; players are referred to as P1 and P2.

## Running the Game

To run the game, follow these steps:

1. Clone this repository to your local machine:

   ```bash
   git clone https://github.com/your-username/pong-game-replica.git
Install SFML if you haven't already. You can download it from SFML's official website or use your package manager.

Compile the game using a C++ compiler, ensuring you link against the SFML libraries.

bash
Copy code
g++ -o pong main.cpp -lsfml-graphics -lsfml-window -lsfml-system
Run the compiled executable:

bash
Copy code
./pong
Game Controls
Player 1 (P1):

Up: Arrow Up (⬆️)
Down: Arrow Down (⬇️)
Player 2 (P2):

Up: 'W' key
Down: 'S' key
Gameplay Instructions
Use the controls to move your paddle and bounce the ball.
Score points by getting the ball past your opponent's paddle.
The first player to score 5 points wins the match.
Code Structure
The code for this game is organized into different files and classes to maintain clarity and adhere to OOP principles. Here's an overview of the code structure:

main.cpp: Contains the game's main function, window setup, and game loop.
Game.hpp and Game.cpp: Defines the Game class responsible for handling game logic.
Player.hpp and Player.cpp: Defines the Player class for managing player-specific attributes and controls.
Ball.hpp and Ball.cpp: Implements the Ball class for ball behavior.
Button.hpp and Button.cpp: Handles button creation and interactions.
License
This project is licensed under the MIT License - see the LICENSE file for details.

Acknowledgments
Thanks to the creators of SFML for providing a fantastic library for game development.

Author
Sagar Parmar
Feel free to reach out with any questions or suggestions!
