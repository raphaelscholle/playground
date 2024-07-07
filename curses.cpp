#include <ncurses.h>
#include <cstring>

int main() {
    // Initialize the ncurses screen
    initscr();
    // Do not display characters as they are typed
    noecho();
    // Hide the cursor
    curs_set(0);
    
    int row, col;
    // Get the number of rows and columns in the terminal
    getmaxyx(stdscr, row, col);

    const char *text[] = {
        
"     OOOOOOOOO                                                               HHHHHHHHH     HHHHHHHHHDDDDDDDDDDDDD        ",        
"   OO:::::::::OO                                                             H:::::::H     H:::::::HD::::::::::::DDD     ",  
" OO:::::::::::::OO                                                           H:::::::H     H:::::::HD:::::::::::::::DD   ",  
"O:::::::OOO:::::::O                                                          HH::::::H     H::::::HHDDD:::::DDDDD:::::D  ",  
"O::::::O   O::::::Oppppp   ppppppppp       eeeeeeeeeeee    nnnn  nnnnnnnn      H:::::H     H:::::H    D:::::D    D:::::D ",
"O:::::O     O:::::Op::::ppp:::::::::p    ee::::::::::::ee  n:::nn::::::::nn    H:::::H     H:::::H    D:::::D     D:::::D",
"O:::::O     O:::::Op:::::::::::::::::p  e::::::eeeee:::::een::::::::::::::nn   H::::::HHHHH::::::H    D:::::D     D:::::D",
"O:::::O     O:::::Opp::::::ppppp::::::pe::::::e     e:::::enn:::::::::::::::n  H:::::::::::::::::H    D:::::D     D:::::D",
"O:::::O     O:::::O p:::::p     p:::::pe:::::::eeeee::::::e  n:::::nnnn:::::n  H:::::::::::::::::H    D:::::D     D:::::D",
"O:::::O     O:::::O p:::::p     p:::::pe:::::::::::::::::e   n::::n    n::::n  H::::::HHHHH::::::H    D:::::D     D:::::D",
"O:::::O     O:::::O p:::::p     p:::::pe::::::eeeeeeeeeee    n::::n    n::::n  H:::::H     H:::::H    D:::::D     D:::::D",
"O::::::O   O::::::O p:::::p    p::::::pe:::::::e             n::::n    n::::n  H:::::H     H:::::H    D:::::D    D:::::D ",
"O:::::::OOO:::::::O p:::::ppppp:::::::pe::::::::e            n::::n    n::::nHH::::::H     H::::::HHDDD:::::DDDDD:::::D  ",
" OO:::::::::::::OO  p::::::::::::::::p  e::::::::eeeeeeee    n::::n    n::::nH:::::::H     H:::::::HD:::::::::::::::DD   ",
"   OO:::::::::OO    p::::::::::::::pp    ee:::::::::::::e    n::::n    n::::nH:::::::H     H:::::::HD::::::::::::DDD     ",
"     OOOOOOOOO      p::::::pppppppp        eeeeeeeeeeeeee    nnnnnn    nnnnnnHHHHHHHHH     HHHHHHHHHDDDDDDDDDDDDD        ",
"                    p:::::p                                                                                              ",
"                    p:::::p                                                                                              ",
"                   p:::::::p                                                                                             ",
"                   p:::::::p                                                                                             ",
"                   p:::::::p                                                                                             ",
"                   ppppppppp                                                                                             "
                                                                                                      
                                                                                    
    };

    int num_lines = sizeof(text) / sizeof(text[0]);
    int start_row = (row - num_lines) / 2;
    for (int i = 0; i < num_lines; ++i) {
        int len = strlen(text[i]);
        int start_col = (col - len) / 2;
        mvprintw(start_row + i, start_col, "%s", text[i]);
    }

    // Refresh the screen to show the message
    refresh();

    // Wait for a key press before exiting
    getch();

    // End ncurses mode
    endwin();

    return 0;
}
