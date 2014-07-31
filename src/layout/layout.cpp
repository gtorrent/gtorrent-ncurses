#include "layout.hpp"
int termwidth, termheight;

NCursesPanel *parent;
NCursesPanel *titlebar;
NCursesPanel *status;
NCursesPanel *labels;
NCursesPanel *trackers;
NCursesPanel *torrents;
NCursesPanel *infobar;

int initialize_layout() {
    // Parent
    parent = new NCursesPanel();

    // Titlebar
    titlebar = new NCursesPanel(2, parent->cols(), 0, 0);
    titlebar->box(' ', ACS_HLINE);


    parent->refresh();
    return 1;
}
