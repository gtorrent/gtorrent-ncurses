#include "logic.hpp"
#include "gtorrent/Core.hpp"


int main_loop() {
    initialize_layout();

    shared_ptr<gt::Core> gt_core(new gt::Core);

    if(gt_core->isRunning()) {
        infobar->printw(1, 0, "Running");
        infobar->refresh();
    }

    while(1) {
        char chr = getch();
        parent->refresh();
        if(chr == 'q') {
            break;
        }
    }

    gt_core->shutdown();

    endwin();
    return 1;
}



