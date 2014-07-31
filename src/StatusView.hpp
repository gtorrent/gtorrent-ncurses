#pragma once

#include <cursesw.h>
#include <cursesp.h>
#include <vector>

class StatusList {
    public:
        std::vector<std::shared_pointer<gt::Torrent>> t_downloading;
        std::vector<std::shared_pointer<gt::Torrent>> t_seeding;
        std::vector<std::shared_pointer<gt::Torrent>> t_completed;
        std::vector<std::shared_pointer<gt::Torrent>> t_checking;
        std::vector<std::shared_pointer<gt::Torrent>> t_stopped;

        StatusList();
        ~StatusList();
};


class StatusView : public NCursesPanel {
    private:

    public:
        StatusView(int nlines, int ncols, int begin_y, int begin_x);
        void update();
};

