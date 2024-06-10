// #include <graphics.h>
// #include <ctime>                       

// class food
// {
//      private:
//           POS foodPos;                    // position
//      public :
//           void draw();                    
//           void generate(int, int);        
//           bool update(int, int);          
// };

// void food::draw()                       // DRAW THE FOOD
// {
//      setcolor(RED);
//      rectangle(foodPos.x, foodPos.y, foodPos.x+30, foodPos.y+30);
//      setfillstyle(INTERLEAVE_FILL, RED);
//      floodfill(foodPos.x+15, foodPos.y+15, RED);
//      readimagefile("Apple.png",foodPos.x, foodPos.y, foodPos.x+30, foodPos.y+30);
// }

// void food::generate(int snakeHeadx, int snakeHeady)     // GENERATE NEW POSITION FOR THE PARTICLE
// {
//      srand(time(0));
//      foodPos.x = 30*(rand()%15 + 1);
//      srand(time(0));
//      foodPos.y = 30*(rand()%15 + 1);
//      if (foodPos.x == snakeHeadx && foodPos.y == snakeHeady)
//           generate(snakeHeadx, snakeHeady);
// }

// bool food::update(int snakeHeadx, int snakeHeady)       // STATUS OF FOOD
// {
//      if (foodPos.x == snakeHeadx && foodPos.y == snakeHeady)
//           return true;
//      else
//           return false;
// }


#include <graphics.h>
#include <ctime> // REQUIRED FOR GENERATING RANDOM NUMBERS

class food
{
private:
     POS foodPos; // POSITION
public:
     void draw();
     void generate(int, int);
     bool update(int, int);
};

// DRAW THE FOOD
// void food::draw()
// {
//      setcolor(RED);
//      // rectangle(foodPos.x, foodPos.y, foodPos.x + 30, foodPos.y + 30);
//      // foodPos.x = 30;
//      circle(foodPos.x - 15, foodPos.y - 15, 15);
//      printf("%d %d\n", foodPos.x, foodPos.y);
//      setfillstyle(INTERLEAVE_FILL, RED);
//      floodfill(foodPos.x, foodPos.y, RED);
// }

// DRAW THE FOOD
void food::draw()
{
     setcolor(RED);
     circle(foodPos.x - 15, foodPos.y - 15, 15);
     setfillstyle(SOLID_FILL, RED);                              // Set the fill style and color to red
     floodfill(foodPos.x - 15, foodPos.y - 15, RED);             // Fill the circle with the current fill style and color
}



// GENERATE NEW POSITION FOR THE PARTICLE
void food::generate(int snakeHeadx, int snakeHeady)
{
     // printf("%d %d", snakeHeadx, snakeHeady);
     srand(time(0));
     foodPos.x = 30 * (rand() % 16 + 1);
     srand(time(0));
     foodPos.y = 30 * (rand() % 16 + 1);
     if(foodPos.x == 30)
     {
          foodPos.x += 30;
     }
     if(foodPos.y == 30)
     {
          foodPos.y += 30;
     }
     if (foodPos.x-30 == snakeHeadx && foodPos.y-30 == snakeHeady)
          generate(snakeHeadx, snakeHeady);
}

// void food::generate(int snakeHeadx, int snakeHeady, int bombx, int bomby)
// {
//      srand(time(0));
//      while (1) {
//           foodPos.x = 30 * (rand() % 16 + 1);
//           foodPos.y = 30 * (rand() % 16 + 1);

//           if (foodPos.x == bombx && foodPos.y == bomby) {
//                continue; // if food is at the same position as bomb, try again
//           }
//           if (foodPos.x == 30) {
//                foodPos.x += 30;
//           }
//           if (foodPos.y == 30) {
//                foodPos.y += 30;
//           }
//           if (foodPos.x-30 == snakeHeadx && foodPos.y-30 == snakeHeady) {
//                continue; // if food is at the same position as snake, try again
//           }
//           break; // a valid position for food has been found
//      }
// }

// TO CHECK IF THE FOOD SHOULD GET UPDATED TO A NEW POSITION
bool food::update(int snakeHeadx, int snakeHeady)
{
     if (foodPos.x-30 == snakeHeadx && foodPos.y-30 == snakeHeady)
          return true;
     else
          return false;
}
