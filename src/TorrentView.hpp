#pragma once

#include <cursesw.h>
#include <cursesp.h>
#include <map>
#include <string>

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
	    std::map<std::string, int> colors; // Associates a state with a color pair
};
