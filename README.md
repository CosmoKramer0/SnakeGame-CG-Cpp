# SnakeGame-CG-Cpp
A classic Snake Game implemented with Computer Graphics using C/C++. The game features smooth animations, keyboard controls, increasing difficulty levels, and a simple bomb mechanic that is still being tested. Explore the source code, contribute, or use it as a learning resource!

## Features

- **Smooth Animations**: Enjoy a seamless gaming experience with smooth animations.
- **Keyboard Controls**: Use the arrow keys to control the snake.
- **Increasing Difficulty**: The game becomes more challenging as the snake grows.
- **Bomb Mechanic**: Avoid randomly placed bombs that end the game if touched.
- **Simple Graphics**: Basic yet effective graphics to keep the game lightweight and fun.

## Getting Started

### Prerequisites

- A C/C++ compiler (e.g., GCC, Clang)
- Basic knowledge of C/C++ and computer graphics
- The `graphics.h` library (e.g., WinBGIm for Windows)

### Installation

1. **Clone the repository**:
   ```bash
   git clone https://github.com/CosmoKramer0/SnakeGame-CG-Cpp.git
   cd SnakeGame-CG-Cpp
2. **Compile the game**:
    ```bash
   g++ main.cpp -o snakegame -lgraph
3. **Run the game:**
   ```bash
   ./snakegame

### How to Play: 
- Use the arrow keys to navigate the snake.
- Eat the food items to grow longer.
- Avoid running into the walls, the snake's own body, or bombs.
- Press 'ESC' to exit the game.

**Code Overview:**

_food.h_
Defines the food class responsible for generating and drawing food items on the screen.

_snakeBody.h_
Defines the snakeBody class which manages the snake's position, movement, and growth.

_bomb.h_
Defines the bomb class for generating and drawing bombs that act as obstacles in the game.

_main.cpp_
The main entry point of the game, which initializes the game window, handles user input, and manages the game loop.

**Screenshots**
![image](https://github.com/CosmoKramer0/SnakeGame-CG-Cpp/assets/122899893/7681b76b-fd65-4661-ace9-7f4871cba5a6)

**Contact:**
For any inquiries, please reach out to fahadbaig247@gmail.com
