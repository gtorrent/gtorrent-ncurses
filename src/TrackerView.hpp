#pragma once

#include <cursesw.h>
#include <cursesp.h>
#include <vector>
#include "gtorrent/Torrent.hpp"
#include "gtorrent/Core.hpp"

class TrackerView : public NCursesPanel {
    public:
        TrackerView(int nlines, int ncols, int begin_y, int begin_x);
        ~TrackerView();
        void update();
  std::map<std::string, std::vector<std::shared_ptr<gt::Torrent>>> *trackers;
};
