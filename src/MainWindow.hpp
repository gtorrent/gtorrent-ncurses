#pragma once

#include <cursesw.h>
#include <cursesp.h>
#include "TorrentView.hpp"

class MainWindow : public NCursesPanel
{
    public:
    MainWindow();
    ~MainWindow();
    void loop();
    void tick();

    private:
    NCursesPanel *titlebar;
    NCursesPanel *infobar;
    TorrentView *torrents;
};
