#include "layout.hpp"
int termwidth, termheight;

PANE parent;
PANE titlebar;
PANE status;
PANE torrents;
PANE infobar;

int initialize_layout() {
    // Parent
    parent = initscr();
    termwidth = parent.columns;
    termheight = parent.rows;

    // Titlebar
    titlebar = PANE(3, termwidth, 0, 0);
    titlebar._border(' ', ' ', ' ', '+', ' ', ' ', '+', '+');
    titlebar._mvprintw(1, (termwidth-8)/2, "gTorrent");
    parent.addchild(&titlebar);


    return 0;
}
