ChronoForge
Welcome to ChronoForge, a unique 2D adventure game that blends puzzle-solving and survival mechanics with an innovative time-manipulation system. In this game, you play as a time-weaver trapped in a distorted dimension, tasked with collecting Chrono Shards to repair a broken time machine while avoiding teleporting enemies and navigating dynamic obstacles.
Features

Time-Weaving Mechanic: Slow down time to outsmart enemies and solve puzzles.
Dynamic Gameplay: Enemies teleport randomly when time is altered, adding unpredictability.
Collectible Chrono Shards: Gather shards to increase your score and progress.
Minimalist Design: Built with SFML for smooth 2D graphics, ready for expansion.

Getting Started
Prerequisites

C++ compiler (e.g., g++ or Visual Studio) with C++11 support or later.
SFML 2.6 or later installed and configured.
A font file (arial.ttf) placed in the same directory as the executable.

Installation

Clone the repository:git clone https://github.com/your-username/ChronoForge.git
cd ChronoForge


Install SFML:
Follow the SFML setup guide for your platform.


Compile the game:g++ -c main.cpp -I/path/to/sfml/include
g++ main.o -o ChronoForge -L/path/to/sfml/lib -lsfml-graphics -lsfml-window -lsfml-system


Place arial.ttf in the project directory.
Run the game:./ChronoForge



How to Play

Controls:
WASD: Move the player (green circle).
SPACE: Toggle slow-motion time.


Objective:
Collect Chrono Shards (yellow circles) to increase your score.
Avoid the enemy (red circle), which chases you and teleports randomly when time is slowed.


Tips:
Use slow-motion to dodge enemies or collect shards in tight situations.
Stay within the game window to avoid getting stuck.



Future Development
This is a prototype version of ChronoForge with core mechanics implemented. Planned features include:

Larger maps with multiple rooms and obstacles.
Time-based puzzles (e.g., traps that activate only in normal time).
Enhanced graphics with custom sprites and animations.
Sound effects and background music.
Save/load system for progress tracking.

Contributing
Contributions are welcome! Feel free to submit pull requests or open issues for bugs, suggestions, or new features. Check the issues page for tasks you can help with.
Support the Project
Love ChronoForge and want to see it grow? Consider supporting me via GitHub Sponsors! Your contributions will help fund new features, improved graphics, and more exciting gameplay mechanics.
License
This project is licensed under the MIT License - see the LICENSE file for details.
Acknowledgments

Built with SFML, a fantastic library for 2D game development.
Inspired by time-bending games and creative puzzle mechanics.


Happy time-weaving!
