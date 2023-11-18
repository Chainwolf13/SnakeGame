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

#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include <curses.h>
#include <ncurses.h>
#include <unistd.h>

#define DELAY 300000


char* getSnakeSize (int num);        //updates snakeSize (snake doesn't grow in this version so we won't actually use this)
void getDirection(int *directionX , int *directionY,int ch);           //Want to use pointers so we can modify data in the address of memory
void showBorder();
void drawBorder();
void displayTrophy();              // displays Trophy on the screen
void updateSnake(int* snakeX, int* snakeY, int snakeSize, int directionX, int directionY);
void drawSnake(int* snakeX, int* snakeY, int snakeSize);
 
int main ()
{
                                                                        /* Setup for snake game */

    // Global var 'stdscr' is created by the call to 'initscr()'
    int max_y = 100, max_x =  100;
    int ch;

    // Snake properties
    int snakeSize = 5;
    int* snakeX = (int*)malloc(snakeSize * sizeof(int));
    int* snakeY = (int*)malloc(snakeSize * sizeof(int));

        // Initialize snake position
    for (int i = 0; i < snakeSize; i++) {
        snakeX[i] = 5 + i;  // Initial X position   all snake segments moves to the right
        snakeY[i] = 5;      // Initial Y position
    }


    //Snake Movement
    int CurrentX = 1 , CurrentY = 1; 
    int directionX = 1 , directionY = 0;

    //Snake and Background Color
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);   //Green Snake, black background

    initscr();                  // initialize the curses Library 
    curs_set(FALSE);            // hide the cursor
    noecho();                   // do not echo the user input to the screen
    keypad(stdscr, TRUE);       // enables working with the arrow keys
    nodelay(stdscr, TRUE);      // Sets getch() to non-blocking (we don't wait for user input)


    while (1) {                 //Game loop (infinite loop until break)
   //  clear();                   // Clearing screen will cause shaking effect so instead we'll clear the snake with empty string " "

    timeout(DELAY / 1000);  // Set a timeout for wgetch in milliseconds
    int ch = wgetch(stdscr);

    if (ch != ERR) {
        // Handle input
        getDirection(&directionX, &directionY, ch);
    }
    
            // Update snake position
        updateSnake(snakeX, snakeY, snakeSize, directionX, directionY);

        //Set Colors
        attron(COLOR_PAIR(1));

        // Draw snake and Border
        erase();
        drawSnake(snakeX, snakeY, snakeSize);
       // drawBorder();
        showBorder();


    refresh();
    //     //Turn off color pair
    // attroff(COLOR_PAIR(1));

    }
    endwin();
    return 0;
}

//Gets the arrow direction of snake
void getDirection( int *directionX , int *directionY , int ch){

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

void showBorder(){
    int max_y = LINES - 1, max_x =  COLS -1;


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
}

void drawBorder() {
    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);

    // Draw the border
    for (int i = 0; i < max_y; i++) {
        for (int j = 0; j < max_x; j++) {
            if (i == 0 || i == max_y - 1 || j == 0 || j == max_x - 1) {
                mvprintw(i, j, "+");
            }
        }
    }
}

// Function to update snake position
void updateSnake(int* snakeX, int* snakeY, int snakeSize, int directionX, int directionY) {
    // Update the tail
    for (int i = snakeSize - 1; i > 0; i--) {   //Makes the tail follow the head
        snakeX[i] = snakeX[i - 1];  //from last segment to 2nd segement copies the position of segment before it to get closer to the head
        snakeY[i] = snakeY[i - 1];
    }

    // Update the head
    snakeX[0] += directionX;        //head is updated based on current movement, if snake moves right then direction is (directionX=1 , directionY =0);
    snakeY[0] += directionY;
}

// Function to draw the snake
void drawSnake(int* snakeX, int* snakeY, int snakeSize) {
    //Set color for snake
    attron(COLOR_PAIR(1));

    // Draw the head
    mvprintw(snakeY[0], snakeX[0], "@");

    // Draw the body
    for (int i = 1; i < snakeSize; i++) {
        mvprintw(snakeY[i], snakeX[i], "x");
    }

    //Turn off color pair
    attroff(COLOR_PAIR(1));
}
