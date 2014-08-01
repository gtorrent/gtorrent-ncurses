#pragma once

#include <cursesw.h>
#include <cursesp.h>
#include <vector>
#include "gtorrent/Torrent.hpp"
#include "gtorrent/Core.hpp"

class StatusList {
    public:
        std::vector<std::shared_ptr<gt::Torrent>> t_downloading;
        std::vector<std::shared_ptr<gt::Torrent>> t_seeding;
        std::vector<std::shared_ptr<gt::Torrent>> t_completed;
        std::vector<std::shared_ptr<gt::Torrent>> t_checking;
        std::vector<std::shared_ptr<gt::Torrent>> t_stopped;

        void update();

        StatusList();
        ~StatusList();
};


class StatusView : public NCursesPanel {
    private:
        StatusList statlist;

    public:
        StatusView(int nlines, int ncols, int begin_y, int begin_x);
        ~StatusView();
        void update();
};

