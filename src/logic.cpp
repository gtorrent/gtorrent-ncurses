#include "logic.hpp"
#include "gtorrent/Core.hpp"


int main_loop() {
    MainWindow parent;

    shared_ptr<gt::Core> gt_core(new gt::Core);

    while(1) {
        char chr = getch();
        parent.refresh();
        if(chr == 'q') {
            break;
        }
    }

    gt_core->shutdown();

    endwin();
    return 1;
}



