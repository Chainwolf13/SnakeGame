/* Snake1.c
*           purpose: Write a C program snake that implements the classic snake game.
*           1st Deliverable 
*
*           The game starts with the snake of size 5 moving right;
*           Snake movement can be controlled in all directions;
*           Snake does not grow;
*           Snake pit border is visible;
*           No trophies.
*
*           //Good feature is if program can save high score (write it to a file)
*           another function reads the file to retrieve it
*
*           Jahmaro Gordon 11/17/2023
*/

#include <stdio.h>
#include <curses.h>
#include <unistd.h>

#define DELAY 30000

char* getSnakeSize (int num);        //updates snakeSize (snake doesn't grow in this version so we won't actually use this)
void getDirection(int Currentx , int Currenty);           //gets direction (takes in an integer and returns the ascii char)
void showBorder();
void displayTrophy();              // displays Trophy on the screen


int main ()
{
    /* Setup for snake game */
    initscr();                  // initialize the curses Library 
   // clear();                    // clear screen 
    curs_set(FALSE);            // hide the cursor
    noecho();                   // do not echo the user input to the screen
    keypad(stdscr, TRUE);       // enables working with the arrow keys
  //  move(0, 0);                 //Top left of screen
    //addstr("press any key...");

    // Global var 'stdscr' is created by the call to 'initscr()'
    int max_y = 100, max_x =  100;
    getmaxyx(stdscr, max_y, max_x);

    //Snake Movement
    static int CurrentX = 0 , CurrentY= 0;
    // int next_x =0;
    // int next_y =0;
    // int direction = 1;

    while (1) {                 //Game loop (infinite loop until break)
    clear();  // Clear the screen of all previously-printed characters

    getDirection(CurrentX,CurrentY);
    refresh();
    
    usleep(DELAY); // Calls sleep function to display movement at a nice pace (Shorter delay between movements)


        // // if next x direction is going to hit the screen border Then You lose !!! and exit program
        // if (next_x >= max_x || next_x < 0) {  
        // //direction*=-1; //swap directions
        // endwin();
        // }

    }
    endwin();
}

//Gets the arrow direction of snake
void getDirection(int CurrentX, int CurrentY){
        // Global var 'stdscr' is created by the call to 'initscr()'
    // int max_y = 100, max_x = 100;
    // getmaxyx(stdscr, max_y, max_x);
    
        //Snake Movement
   //default values for direction
   int next_x = CurrentX; 
   int next_y = CurrentY;   
   //positive for going up or right , negative for going left or down
   int directionX = 1;
   int directionY = 1;
    
    
        int ch = getch();
        char buf[100];
      //  move(0, 0);

        switch (ch) {
        case KEY_UP:
        if (directionY == -1) { //if snake is already going DOWN we swap directions
            directionY*=-1;
        }else {
            directionY = 1;     //else we continue going UP
        }break; //BREAK
        case KEY_DOWN:
        if (directionY == 1) { //if snake is already going UP we swap directions
            directionY *= -1;
        }else {
            directionY = -1;     //else we continue going DOWN
        }break; //BREAK
        case KEY_LEFT:
        if (directionX == 1) { //if snake is already going RIGHT we swap directions
            directionY *= -1;
        }else {
            directionY = -1;     //else we continue going LEFT
        }break; // BREAK
        case KEY_RIGHT:
        if (directionX == -1) { //if snake is already going LEFT we swap directions
            directionX *= -1;
        }else {
            directionX = 1;     //else we continue going RIGHT
        }break; // BREAK       
        case KEY_ENTER:
            addstr("You pressed the ENTER arrow                     ");
            break;
        case 'x':       //pressing 'x' or 'X' will exit the program
        case 'X':      
            endwin();   // close curses
        default:
        // sprintf(buf, "You pressed a \"%c\" key, ASCII code %d...", (char)ch, ch);
        // addstr(buf);
        break;
    }
    /* MOVES THE SNAKE*/
    // next_x = CurrentX + direction;
    // next_y = CurrentY + direction;
    
    CurrentX += directionX;
    CurrentY += directionY;
    mvprintw(CurrentY, CurrentX, "o"); //prints our snake at the current xy position

}

void showBorder(){

}

char* getSnakeSize(int size){
    // size = 5;
    // char snakeBody[size];

    // //loop size amount of times
     char* snake;
    // char head = 'X';
    // char body = 'o';
    // char tail = 'Z';

    // if (condition) {
    // statements
    // }    

    return snake;
}
