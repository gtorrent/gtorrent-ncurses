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
    curs_set(0);
    start_color();

    // Some colors
    init_pair(1, COLOR_MAGENTA, COLOR_BLACK);

    // Titlebar
    titlebar = new NCursesPanel(2, parent->cols(), 0, 0);
    titlebar->border(' ', ' ', ' ',ACS_HLINE, ' ', ' ',ACS_HLINE,ACS_HLINE);
    titlebar->attron(COLOR_PAIR(1));
    titlebar->printw(0, (titlebar->cols()-8)/2, "gTorrent");
    titlebar->attroff(COLOR_PAIR(1));
    titlebar->addch(1, 19, ACS_TTEE);

    // Status
    status = new NCursesPanel(6, 20, 2, 0);
    status->border(' ', ACS_VLINE, ' ', ' ', ' ', ACS_VLINE, ' ', ACS_VLINE);
    status->attron(A_BOLD);
    status->printw(0, 0, "Status");
    status->attroff(A_BOLD);
    status->printw(1, 2, "Downloading");
    status->printw(2, 2, "Seeding");
    status->printw(3, 2, "Active");
    status->printw(4, 2, "Inactive");
    status->printw(5, 2, "Complete");

    // Labels
    labels = new NCursesPanel((parent->lines()-9)/2, 20, 8, 0);
    labels->border(' ', ACS_VLINE, ACS_HLINE, ' ', ACS_HLINE, ACS_RTEE, ' ', ACS_VLINE);
    labels->attron(A_BOLD);
    labels->printw(1, 0, "Labels");
    labels->attroff(A_BOLD);

    // Trackers
    trackers = new NCursesPanel((parent->lines()-9)/2, 20, (parent->lines()-9)/2 + 8, 0);
    trackers->border(' ', ACS_VLINE, ACS_HLINE, ' ', ACS_HLINE, ACS_RTEE, ' ', ACS_VLINE);
    trackers->attron(A_BOLD);
    trackers->printw(1, 0, "Trackers");
    trackers->attroff(A_BOLD);

    // Infobar
    infobar = new NCursesPanel(2, parent->cols(), parent->lines() - 2, 0);
    infobar->border(' ', ' ', ACS_HLINE, ' ', ACS_HLINE, ACS_HLINE, ' ', ' ');
    infobar->addch(0, 19, ACS_BTEE);


    parent->refresh();
    return 1;
}
