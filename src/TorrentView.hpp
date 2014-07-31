#pragma once

#include <cursesw.h>
#include <cursesp.h>

class TorrentView : public NCursesPanel
{
    public:
        TorrentView(int nlines, int ncols, int begin_y, int begin_x);
        void update();
};
