#include <graphics.h>
#include "snakeBody.h"
#include "food.h"
#include "bomb.h"
#include <fstream>

int main()
{
     initwindow(800, 510, "SNAKE GAME"); // CREATES GAMING WINDOW OF 800 x 510 PIXELS
     snakeBody body;
     bomb bom;
     food fruit;
     int length, count = 0;
     bool playing = true;
     char lengtharr[3];
     fruit.generate(body.getPosx(), body.getPosy());
     bom.generateb(body.getPosx(), body.getPosy());
     int page = 0;

     // // Read highscore from file
     // std::ifstream highscore_file("highscore.txt");
     // int highscore = 0;
     // if (highscore_file.is_open()) {
     //      highscore_file >> highscore;
     //      highscore_file.close();
     // }

     while (1)
     {
          setactivepage(page);
          setvisualpage(1 - page);
          cleardevice();
          setcolor(BLUE);

          setfillstyle(SOLID_FILL, BLUE);
          // FOR KEY INPUT
          if (GetAsyncKeyState(VK_LEFT))
          {
               body.changeDirTo(LEFT);
          }
          if (GetAsyncKeyState(VK_UP))
          {
               body.changeDirTo(UP);
          }
          if (GetAsyncKeyState(VK_RIGHT))
          {
               body.changeDirTo(RIGHT);
          }
          if (GetAsyncKeyState(VK_DOWN))
          {
               body.changeDirTo(DOWN);
          }
          if (GetAsyncKeyState(VK_ESCAPE))
               break;

          if (playing == true && !body.update())
          {
               playing = false;
          }
          body.drawSnake();

          if (fruit.update(body.getPosx(), body.getPosy()))
          {
                fruit.generate(body.getPosx(), body.getPosy());
               // fruit.generate(body.getPosx(), body.getPosy(), bom.bombPos.x, bom.bombPos.y);
               body.appendSnake();
          }

          // BOXES
          setcolor(YELLOW);
          rectangle(0, 0, 30, 510);
          rectangle(30, 0, 480, 30);
          rectangle(480, 0, 510, 510);
          rectangle(30, 480, 480, 510);
          rectangle(510, 0, 800, 20);
          rectangle(510, 250, 800, 270);
          rectangle(780, 20, 800, 250);
          rectangle(510, 490, 800, 510);
          rectangle(780, 270, 800, 490);
          setfillstyle(SOLID_FILL, YELLOW);
          floodfill(15, 250, YELLOW);
          floodfill(250, 15, YELLOW);
          floodfill(495, 250, YELLOW);
          floodfill(250, 495, YELLOW);
          floodfill(550, 260, YELLOW);
          floodfill(550, 10, YELLOW);
          floodfill(790, 150, YELLOW);
          floodfill(550, 500, YELLOW);
          floodfill(790, 300, YELLOW);

          // SCORE
          settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 5);
          setcolor(WHITE);
          outtextxy(550, 20, "LENGTH");
          outtextxy(520, 60, "ACHIEVED");
          length = body.getlength();
          lengtharr[0] = char(48 + length / 10); // 6
          lengtharr[1] = char(48 + length % 10); // 0
          lengtharr[2] = '\0';
          outtextxy(620, 100, lengtharr);

          settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 4);
          outtextxy(530, 160, "HIGHSCORE");

          char highchar[3];
          int score = 45;
          
          highchar[0] = char(48 + score / 10);
          highchar[1] = char(48 + score % 10);
          highchar[2] = '\0';
          outtextxy(620, 190, highchar);

          // STATUS
          settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 4);
          outtextxy(520, 300, "STATUS :-");
          if (body.getlength() == 60)
          {
               outtextxy(520, 350, "YOU WON !");
               playing = false;
          }
          else if (playing)
          {
               outtextxy(520, 350, "PLAYING");
          }
          else
          {
               outtextxy(520, 350, "GAME OVER");
          }
          settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
          outtextxy(520, 400, "PRESS 'ESC' to EXIT");

          fruit.draw();
          // bom.drawb();
          page = 1 - page;
          delay(100);
     }

     getch();
     closegraph();
}
