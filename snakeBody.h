#include <graphics.h>

enum DIR {LEFT , UP , RIGHT , DOWN};        

// POSITION STRUCTURE 
struct POS
{
       int x,y;
       POS()
       {
            x = -50;
            y = 0;
       }
};

class snakeBody
{
        private:
                POS arr[61];            // POSITION ARRAY
                int direction;          // ENUM
                int length;             // LENGTH
        public :
                snakeBody()
                {
                        arr[0].x = 30;        
                        arr[0].y = 30;        
                        length = 2;           // INITILAL LENGTH = 2
                        direction = RIGHT;    // GOING IN RIGHT DIRECTION DEFAULT
                }
                void drawSnake();
                void appendSnake();         //INCREMENT IN SNAKE'S LENGTH
                void changeDirTo(int);
                int update();
                int getPosx();              
                int getPosy();              
                int getlength();            

};

void snakeBody::drawSnake()  
{
        for(int i=0; i<length ; i++)
        {
                setcolor(BLUE);
                rectangle(arr[i].x , arr[i].y , arr[i].x+30 , arr[i].y+30);
                if(i==0)                                                                 // HEAD GREEN COLOUR
                        setfillstyle(SOLID_FILL , GREEN);
                else                                                                     // BODY COLOUR
                        setfillstyle(SOLID_FILL , LIGHTGREEN);
                        floodfill(arr[i].x+15 , arr[i].y+15 , BLUE);
        }
}

void snakeBody::appendSnake()
{
        if(length < 60)                            // PREVENTS THE LENGTH FROM GOING GREATER THAN 60
                length++;
}

void snakeBody::changeDirTo(int newdir)
{
        if(newdir == LEFT || newdir == RIGHT)
        {
                if(direction == UP || direction == DOWN)
                        direction = newdir;
        }
        else if(newdir == UP || newdir == DOWN)
        {
                if(direction == LEFT || direction == RIGHT)
                        direction = newdir;
        }
}

int snakeBody::update()                                                    
{           
        //if(bombPos.x)                                                               
        for(int i=1 ; i<length ; ++i)                                         
        {                                                                     
                if(arr[0].x == arr[i].x && arr[0].y == arr[i].y)           
                {                                                          
                        return 0;                                          
                }
        }
        for(int i=length ; i>=0 ; --i)
        {
                if(i==0)
                {
                     arr[1].x = arr[0].x;
                     arr[1].y = arr[0].y;
                }
                else
                {
                        arr[i].x = arr[i-1].x;
                        arr[i].y = arr[i-1].y;
                }
        }
        if(direction == LEFT)
        {
                arr[0].x -= 30;
                if(arr[0].x == 0)
                {
                        arr[0].x = 450;
                }
        }
        else if(direction == RIGHT)
        {
                arr[0].x += 30;
                if(arr[0].x == 480)
                {
                        arr[0].x = 30;
                }
        }
        else if(direction == UP)
        {
                arr[0].y -= 30;
                if(arr[0].y == 0)
                {
                        arr[0].y = 450;
                }
        }
        else if(direction == DOWN)
        {
                arr[0].y += 30;
                if(arr[0].y == 480)
                {
                        arr[0].y = 30;
                }
        }
        return 1;
}

int snakeBody::getPosx()
{
        return arr[0].x;
}

int snakeBody::getPosy()
{
        return arr[0].y;
}

int snakeBody::getlength()
{
        return length;
}
