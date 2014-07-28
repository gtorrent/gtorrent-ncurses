#include "panes/panes.hpp"
#include "gtorrent/Torrent.hpp"

int main(int argc, char *argv[]) {
    noecho();
    initscr();

    printw("Hello World!");
    refresh();
    getch();
    endwin();
    return 0;
}
