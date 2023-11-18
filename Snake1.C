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

#define DELAY 300000


char* getSnakeSize (int num);        //updates snakeSize (snake doesn't grow in this version so we won't actually use this)
void getDirection(int *directionX , int *directionY);           //Want to use pointers so we can modify data in the address of memory
void showBorder(int oldX, int oldY,int CurrentX,int CurrentY);
void displayTrophy();              // displays Trophy on the screen


int main ()
{
    /* Setup for snake game */



    // Global var 'stdscr' is created by the call to 'initscr()'
    int max_y = 100, max_x =  100;
    int ch;

    //Snake Movement
    int CurrentX = 1 , CurrentY = 1; 
    int directionX = 1 , directionY = 0;

    initscr();                  // initialize the curses Library 
    curs_set(FALSE);            // hide the cursor
    noecho();                   // do not echo the user input to the screen
    keypad(stdscr, TRUE);       // enables working with the arrow keys
    nodelay(stdscr, TRUE);      // Sets getch() to non-blocking (we don't wait for user input)

    // Draw Border
    showBorder(-1,-1,CurrentX,CurrentY);

    while (1) {                 //Game loop (infinite loop until break)
     //clear();                   // Clearing screen will cause shaking effect so instead we'll clear the snake with empty string " "

                                 /* MOVES THE SNAKE'S POSITION */
    int oldX = CurrentX;
    int oldY = CurrentY;
    getDirection(&directionX , &directionY);     // Pass in the value of pointers
    CurrentX += directionX;
    CurrentY += directionY;

                                /* Redraw Snake and Border  */
  //  mvprintw(CurrentY, CurrentX, "XoooZ"); //prints our snake at the current xy position
    showBorder(oldX,oldY,CurrentX,CurrentY);

    refresh();
    usleep(DELAY); // Calls sleep function to display movement at a nice pace (Shorter delay between movements)

    }
    endwin();
    return 0;
}

//Gets the arrow direction of snake
void getDirection( int *directionX , int *directionY){
        int ch = getch();

        switch (ch) {
        case KEY_UP:            //to go up decrease y
            *directionY = -1;
            *directionX = 0;
        break;
        case KEY_DOWN:         //to go down increase y
            *directionY = 1;
            *directionX = 0; 
        break;
        case KEY_LEFT:
            *directionY = 0;
            *directionX = -1; 
        break; 
        case KEY_RIGHT:
            *directionY = 0;
            *directionX = 1; 
        break;    
        case KEY_ENTER:
            addstr("You pressed the ENTER arrow                     ");
            break;
        case 'x':       //pressing 'x' or 'X' will exit the program
        case 'X':      
            endwin();   // close curses
            break;
        default:
        break;
    }

}

void showBorder(int oldX, int oldY,int CurrentX,int CurrentY ){
    int max_y = LINES - 1, max_x =  COLS -1;

    // Clear the old position of the snake
    if (oldX != -1 && oldY != -1) {
        mvprintw(oldY, oldX, " ");  //go to that position and erase the snake
    }

    //TOP BORDER
        mvprintw(0, 1, "+");
    for(int i = 2; i < max_x - 2; i++){     //Start at 1 so we can see visible border from terminal (could start at 0 if we want) and place "+" there
        mvprintw(0, i, "-");                    //Every COL we place a wall "-" 
    }   mvprintw(0, max_x - 1, "+");            //Last COL add "+" border

    //SIDE BORDER
    for(int i = 1; i< max_y - 1; i++){
        mvprintw(i, 0, "|");                    //Every row we place a wall "|" on left side
        mvprintw(i, max_x - 1, "|");            //Every row we place a wall "|" on right side
    }

    //Bottom BORDER
        mvprintw(max_y -1,0, "+");
    for(int i = 2; i < max_x - 2; i++){     //Start at 1 so we can see visible border from terminal (could start at 0 if we want) and place "+" there
        mvprintw(max_y, i, "-");                    //Every COL we place a wall "-" 
    }   mvprintw(max_y, max_x - 1, "+");            //Last COL add "+" border

    mvprintw(CurrentY, CurrentX, "X"); //prints our snake at the current xy position
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
