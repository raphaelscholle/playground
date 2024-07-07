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
        
        "  #######  ########  ######## ##    ## ##     ## ######## ",
        " ##     ## ##     ## ##       ###   ## ##     ## ##     ##",
        " ##     ## ##     ## ##       ####  ## ##     ## ##     ##",
        " ##     ## ########  ######   ## ## ## ######### ##     ##",
        " ##     ## ##        ##       ##  #### ##     ## ##     ##",
        " ##     ## ##        ##       ##   ### ##     ## ##     ##",
        "  #######  ##        ######## ##    ## ##     ## ######## ",                                                                                                      
        "",
        ""                                                                            
    };

    int num_lines = sizeof(text) / sizeof(text[0]);
    int start_row = (row - num_lines) / 10;
    for (int i = 0; i < num_lines; ++i) {
        int len = strlen(text[i]);
        int start_col = (col - len) / 2;
        mvprintw(start_row + i, start_col, "%s", text[i]);
    }

     // Seperator
    for (int i = 0; i < col; ++i) {
        mvaddch(start_row + num_lines, i, '=');
    }

    // Add a table with three rows and three columns
    const char *table[3][3] = {
        {"Column 1", "Column 2", "Column 3"},
        {"Row 1, Col 1", "Row 1, Col 2", "Row 1, Col 3"},
        {"Row 2, Col 1", "Row 2, Col 2", "Row 2, Col 3"}
    };

    int table_start_row = start_row + num_lines + 1 + 1; // Position below separator line
    for (int i = 0; i < 3; ++i) {
        int total_len = 0;
        for (int j = 0; j < 3; ++j) {
            total_len += strlen(table[i][j]) + 2; // Add space for spacing
        }
        int start_col = (col - total_len) / 2;

        int current_col = start_col;
        for (int j = 0; j < 3; ++j) {
            mvprintw(table_start_row + i, current_col, "%s", table[i][j]);
            current_col += strlen(table[i][j]) + 2; // Move to next column position
        }
    }

    // Refresh the screen to show the message
    refresh();

    int ch;
    // Wait for the Esc key before exiting
    while ((ch = getch()) != 27) {
        // Do nothing, just loop until Esc is pressed
    }
    // End ncurses mode
    endwin();

    return 0;
}
