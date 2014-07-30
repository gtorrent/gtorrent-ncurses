#include "panes/panes.hpp"
#include "gtorrent/Torrent.hpp"

int main(int argc, char *argv[]) {
    noecho();
    PANE w_main = initscr();

    w_main.addchild(w_main.rows/2, w_main.columns, w_main.rows/2, 0);
    w_main._children().back()->_printw("World!");
    w_main._printw("Hello");
    w_main._refresh();
    getch();
    endwin();
    return 0;
}
