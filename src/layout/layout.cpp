#include "layout.hpp"
int termwidth, termheight;

PANE parent;
PANE titlebar;
PANE status;
PANE labels;
PANE trackers;
PANE torrents;
PANE infobar;

int initialize_layout() {
    // Parent
    parent = initscr();
    noecho();
    curs_set(0);
    termwidth = parent.columns;
    termheight = parent.rows;

    // Some color pairs
    start_color();
    init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(2, COLOR_BLACK, COLOR_MAGENTA);

    // Titlebar
    titlebar = PANE(2, termwidth, 0, 0);
    titlebar._border(' ', ' ', ' ', ACS_HLINE, ' ', ' ', ACS_HLINE, ACS_HLINE);
    titlebar._mvaddch(1, termwidth*0.3-1, ACS_TTEE);
    titlebar._attron(COLOR_PAIR(1));
    titlebar._mvprintw(0, (termwidth-8)/2, "gTorrent");
    parent.addchild(&titlebar);

    // Torrent Statuses
    status = PANE(6, termwidth*0.3, 2, 0);
    status._border(' ', ACS_VLINE, ' ', ' ', ' ', ACS_VLINE, ' ', ACS_VLINE);
    status._mvprintw(0, 0, "Status");
    status._mvprintw(1, 2, "Downloading");
    status._mvprintw(2, 2, "Seeding");
    status._mvprintw(3, 2, "Active");
    status._mvprintw(4, 2, "Inactive");
    status._mvprintw(5, 2, "Checking");
    parent.addchild(&status);

    // Torrent Labels
    labels = PANE((termheight-9)/2, termwidth*0.3, 8, 0);
    labels._border(' ', ACS_VLINE, ACS_HLINE, ' ', ACS_HLINE, ACS_RTEE, ' ', ACS_VLINE);
    labels._mvprintw(1, 0, "Labels");
    parent.addchild(&labels);

    // Torrent trackers
    trackers = PANE((termheight-9)/2, termwidth*0.3, (termheight-9)/2+8, 0);
    trackers._border(' ', ACS_VLINE, ACS_HLINE, ' ', ACS_HLINE, ACS_RTEE, ' ', ACS_VLINE);
    trackers._mvprintw(1, 0, "Trackers");
    parent.addchild(&trackers);

    // Infobar
    infobar = PANE(2, termwidth, termheight-2, 0);
    infobar._border(' ', ' ', ACS_HLINE, ' ', ACS_HLINE, ACS_HLINE, ' ', ' ');
    infobar._mvaddch(0, termwidth*0.3-1, ACS_BTEE);
    parent.addchild(&infobar);

    // Torrents
    torrents = PANE(termheight-4, termwidth-(termwidth*0.3), 2, termwidth*0.3);
    parent.addchild(&torrents);

    return 0;
}
