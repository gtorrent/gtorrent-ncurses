#pragma once

#include <cursesw.h>
#include <cursesp.h>
#include <vector>
#include "gtorrent/Torrent.hpp"
#include "gtorrent/Core.hpp"

class StatusView : public NCursesPanel {
    private:
        unsigned getStatusCount(const libtorrent::torrent_status::state_t &status);
        unsigned getPausedCount();

    public:
        StatusView(int nlines, int ncols, int begin_y, int begin_x);
        ~StatusView();
        void update();
};

