#include <graphics.h>
#include <ctime> // REQUIRED FOR GENERATING RANDOM NUMBERS

class bomb
{
private:
     POS bombPos; // POSITION
public:
     void drawb();
     void generateb(int, int);
     bool updateb(int, int);
};

// // DRAW THE BOMB
// void bomb::drawb()
// {
//      setcolor(WHITE);
//      circle(bombPos.x - 15, bombPos.y - 15, 15);
//      setfillstyle(SOLID_FILL, WHITE);                              // Set the fill style and color to white
//      floodfill(bombPos.x - 15, bombPos.y - 15, WHITE);             // Fill the circle with the current fill style and color
// }



// // GENERATE NEW POSITION FOR THE BOMB
// void bomb::generateb(int snakeHeadx, int snakeHeady)
// {
//     srand(time(0));
//     bombPos.x = 30 * (rand() % 16 + 1);
//     srand(time(0));
//     bombPos.y = 30 * (rand() % 16 + 1);
//     if(bombPos.x == 30)
//     {
//         bombPos.x += 30;
//     }
//     if(bombPos.y == 30)
//     {
//         bombPos.y += 30;
//     }
//     if (bombPos.x-30 == snakeHeadx && bombPos.y-30 == snakeHeady)
//         generateb(snakeHeadx, snakeHeady);
    
// }

void bomb::generateb(int snakeHeadx, int snakeHeady)
{
    static int call_count = 0; // static variable to count function calls

    if (call_count < 2) { // execute function twice
        srand(time(0));
        bombPos.x = 30 * (rand() % 16 + 1);
        srand(time(0));
        bombPos.y = 30 * (rand() % 16 + 1);
        if (bombPos.x == 30)
        {
            bombPos.x += 30;
        }
        if (bombPos.y == 30)
        {
            bombPos.y += 30;
        }
        if (bombPos.x-30 == snakeHeadx && bombPos.y-30 == snakeHeady)
            generateb(snakeHeadx, snakeHeady);

        call_count++; // increment call count
    }
}

// TO CHECK IF THE FOOD SHOULD GET UPDATED TO A NEW POSITION
bool bomb::updateb(int snakeHeadx, int snakeHeady)
{
     if (bombPos.x-30 == snakeHeadx && bombPos.y-30 == snakeHeady)
          return true;
     else
          return false;
}
