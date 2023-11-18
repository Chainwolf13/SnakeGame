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

void getSnakeSize(int);        //updates snakeSize (snake doesn't grow in this version so we won't actually use this)
void getDirection();           //gets direction (takes in an integer and returns the ascii char)
void showBorder();
void displayTrophy();              // displays Trophy on the screen


int main ()
{
    /* Setup for snake game */
    initscr();                  // initialize the curses Library 
    clear();                    // clear screen 
    curs_set(FALSE);            // hide the cursor
    noecho();                   // do not echo the user input to the screen
    keypad(stdscr, TRUE);       // enables working with the arrow keys
    move(0, 0);                 //Top left of screen
    //addstr("press any key...");

    // Global var 'stdscr' is created by the call to 'initscr()'
    int max_y = 0, max_x = 0;
    getmaxyx(stdscr, max_y, max_x);

    //Snake Movement
    int x = 0 , y= 0;
    int next_x =0;
    int direction = 1;

    while (1) {                 //Game loop (infinite loop until break)
    clear();  // Clear the screen of all previously-printed characters

    //mvprintw(y, x, "o"); //print our ball at the current xy position

    refresh();
    
    usleep(DELAY); // Calls sleep function to display movement at a nice pace (Shorter delay between movements)


        // if next x direction is going to hit the screen border Then You lose !!! and exit program
        if (next_x >= max_x || next_x < 0) {  
        //direction*=-1; //swap directions
        endwin();
        }

    }
}

void getDirection(){
        int ch = getch();
        char buf[100];
        move(0, 0);

        switch (ch) {
        case KEY_UP:
            addstr("You pressed the UP arrow                     ");
            break;
        case KEY_DOWN:
            addstr("You pressed the DOWN arrow                     ");
            break;
        case KEY_LEFT:
            addstr("You pressed the LEFT arrow                     ");
            break;   
        case KEY_RIGHT:
            addstr("You pressed the RIGHT arrow                     ");
            break;       
        case KEY_ENTER:
            addstr("You pressed the ENTER arrow                     ");
            break;
        case 'x':       //pressing 'x' or 'X' will exit the program
        case 'X':      
            endwin();   // close curses
        default:
        sprintf(buf, "You pressed a \"%c\" key, ASCII code %d...", (char)ch, ch);
        addstr(buf);
        break;
    }
}

void showBorder(){

}
