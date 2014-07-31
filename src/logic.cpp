#include "logic.hpp"
#include "gtorrent/Core.hpp"


int main_loop() {
    initialize_layout();

    shared_ptr<gt::Core> gt_core(new gt::Core);

    if(gt_core->isRunning()) {
    }

    gt_core->shutdown();
    return 1;
}



