#include "logic.hpp"
#include "gtorrent/Core.hpp"


int main_loop() {
    initialize_layout();
    parent._refresh();

    shared_ptr<gt::Core> gt_core(new gt::Core);

    if(gt_core->isRunning()) {
        infobar._mvprintw(1, 0, "Running");
        parent._refresh();
    }

    parent._refresh();

    while(getch() != 'q') {
        parent._refresh();
    }

    endwin();
    gt_core->shutdown();
    return 1;
}



