#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <string.h>
#include <locale.h>
#include <sys/ioctl.h>
#include <unistd.h>

#define leftPlayerUP        "w"
#define leftPlayerDOWN      "s"
#define rightPlayerUP       "o"
#define rightPlayerDOWN     "k"
#define startPauseButton    32
#define FILENAME            "/home/gfigueira/git/pong/prototypes/startup.screen"

int setupGame()
{
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);

    if(w.ws_row < 24 || w.ws_col < 80)
    {
        return(0);
    }
    else
    {
        return(1);
    }
}

int startGame()
{
    setlocale(LC_ALL, "");
    initscr();
    // cbreak(); // To disable the buffering of typed characters by the TTY
              // driver and get a character-at-a-time input
    // noecho(); // To suppress the automatic echoing of typed characters
    // printf("%i\n", LINES);
    // printf("%i\n", COLS);
    //
    //                  The screen (stdscr)
    //  (0,0)*----------------------------------* (0, COLUMNS-1)
    //       |                                  |
    //       |                                  |
    //       |    (y0,x0)                       |
    //       |      ---------------             |
    //       |      |             |             |
    //       |      |             |             |
    //       |      |     win     |nlines       |
    //       |      |             |             |
    //       |      |             |             |
    //       |      |             |             |
    //       |      ---------------             |
    //       |          ncols                   |
    //       |                                  |
    //       *----------------------------------*
    // (LINES-1, 0)                              (LINES-1, COLUMNS-1)

    int startY = (LINES - 24) / 2;
    int startX = (COLS - 80) /2;
    int nlines = 24;
    int ncols = 80;
    int i = 12;
    int j = 0;

    WINDOW * gameWin = newwin(nlines, ncols, startY, startX);

    wmove(gameWin, startY, startX);
    waddch(gameWin, 'o');
    wrefresh(gameWin);

    for(i=startY; i<nlines; i++)
    {
        for(j=startX; j<ncols; j++)
        {
            wmove(gameWin, i, startX + j);
            waddch(gameWin, '#');
            wrefresh(gameWin);
        }
    }

    wrefresh(gameWin);
    sleep(30);

    delwin(gameWin); // delete window
    return(0);
}

// show a text file in the screen and wait until user hits space
int showStartupScreen()
{
    int c;
    FILE *fp;

    fp = fopen(FILENAME, "r");
    if ( fp == NULL )
    {
        fprintf(stderr, "Cannot load startup screen");
        return(1);
    }
    else
    {
        int d;
        d = fgetc(fp);
        while (d != EOF)
        {
            printf("%c", d);
            d = fgetc(fp);
        }
        fclose(fp);
        system("/bin/stty raw");
        while(c != startPauseButton)
        {
            c = getchar();
        }
        system("/bin/stty cooked");
        startGame();
    }
}

int main( int argc, char **argv )
{
    if(setupGame())
    {
        showStartupScreen();
        endwin();
    }
    else
    {
        printf("Terminal size too small\n");
    }
}
