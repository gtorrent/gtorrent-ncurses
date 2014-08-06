#pragma once

#include <cursesw.h>
#include <cursesp.h>
#include <map>
#include <string>
#include "gtorrent/Torrent.hpp"

class TorrentView : public NCursesPanel
{
    public:
        TorrentView(int nlines, int ncols, int begin_y, int begin_x);
        void update();
        void selectionDown();
        void selectionUp();
        void processKey(int key);

    private:
        unsigned selected;
        std::shared_ptr<gt::Torrent> t_selected;
        std::map<std::string, int> colors; // Associates a state with a color pair
};
