#include "layout/layout.hpp"
#include "gtorrent/Torrent.hpp"

int main(int argc, char *argv[]) {
    noecho();

    initialize_layout();
    parent._refresh();
    titlebar._refresh();

    getch();
    endwin();
    return 0;
}
