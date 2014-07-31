#include "layout.hpp"
int termwidth, termheight;

NCursesWindow *parent;
NCursesWindow *titlebar;
NCursesWindow *status;
NCursesWindow *labels;
NCursesWindow *trackers;
NCursesWindow *torrents;
NCursesWindow *infobar;

int initialize_layout() {
    // Parent
    parent = new NCursesWindow(initscr());
    noecho();
    start_color();

    // Titlebar
    titlebar = new NCursesWindow(derwin(parent, 2, parent->cols(), 0, 0);

    return 1;
}
