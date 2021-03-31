Hackweek 20
===========

    Create a Pong clone in C using curses.h
    (dual player, no sound, basic menus)

    Keywords: c, curses, pong

Task list / Project management
==============================

  - [x] [plan] make a rough list of tasks and categories
  - [x] [plan] make a rough plan with the 5 most important tasks
  - [x] [study] read o'reilly's c pocket reference (23/142 pgs)
  - [x] [admin] create and checkout github page -> https://github.com/guxtavo/pong
  - [x] [admin] move this doc to the git checkout
  - [x] [doc] watch and take notes: thttps://www.youtube.com/watch?v=bPCMDr7iDlU
  - [x] [doc] reverse engineer a pong game, write notes about the workings
  - [x] [plan] draw prototype startup screen -> prototypes/startup.screen
  - [x] [plan] draw prototype game screen -> prototypes/game.screen
  - [x] [code] [setup] setup key bindings
  - [x] [code] basic startGame() - printf and exit 0
  - [x] [code] fix warnings shown by the compiler
  - [x] [code] showStartupScreen() is functional
  - [x] [code] [setup] check the terminal size
  - [x] [code] [setup] only allow to run in a terminal with the proper size
  - [x] [code] [curses] initialize the window in setupGame()
  - [x] [study] [curses] http://www.cs.ukzn.ac.za/~hughm/os/notes/ncurses.html
  - [x] [study] [curses] how to create a new window
  - [x] [study] [curses] how to reset the screen -> endwin()
  - [x] [admin] write stats.sh to enumerate undone tasks and total tasks
  - [x] [study] find out how to pass the pointer of gameWin to gameLoop()
  - [x] [study] [curses] move cursor to a position and write a char
  - [x] [code] adapt code I found online, make the ball move forward
  - [ ] [code] draw a border around the window
  - [ ] [code] set the boundaries on where the ball can bounce - colision
  - [ ] [code] make the ball bounce at gameStart
  - [ ] [code] [main] compensate lateral movement since # char is taller
  - [ ] [code] [main] determine logic for win/loss
  - [ ] [code] [bug] do not show the last carrier return in showStartupScreen
  - [ ] [code] [bug] do no show typed characters during getchar()
  - [ ] [code] [bug] redraw the screen if the tty changed size
  - [ ] [code] [extra] different ways of hitting the ball->diff traj.

Reverse engineer documentation
==============================

    * the user run the program
        -> startup screen is shown -> showTitleScreen( void )
            -> there are controls for the left and right player
               (up/down)
            -> game can be started with "space"

    * the user starts a game by pressing "space"
        -> the game screen is drawn
            -> rectangular border which has inside:
                -> a score for each player in the top
                -> a pad for each player (left and right)
                -> a ball
        -> the game starts
            -> the ball starts moving at a constant speed
            -> the ball starts bouncing from the left player to the
               right side
            -> the ball bounces in the upper and bottom borders
            -> the ball bounces on the pad of each player no matter
               which part it touches
            -> the players tabs move up/down at a certain speed
            -> point is given to right player when the ball touches the
               left border
            -> point is given to left player when the ball touches the
               right border
            -> the game ends when a player reaches the score of "10"

Screen prototype notes
======================

    * Ball can go over the score board
    * Player tabs are 4 vertical pipes
