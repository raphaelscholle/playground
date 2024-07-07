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
        "██████╗ ██████╗ ███████╗ ███╗   ██╗   ██╗  ██╗██████╗",
        "██╔═══██╗██╔══██╗██╔═══╝ ████╗  ██║   ██║  ██║██╔══██╗",
        "██║   ██║██████╔╝█████╗  ██╔██╗ ██║   ███████║██║  ██║",
        "██║   ██║██╔═══╝ ██╔══╝  ██║╚██╗██║   ██╔══██║██║  ██║",
        "╚██████╔╝██║     ███████╗██║ ╚████║   ██║  ██║██████╔╝",
        " ╚═════╝ ╚═╝     ╚══════╝╚═╝  ╚═══╝    ╚═╝  ╚═╝╚═════╝"
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