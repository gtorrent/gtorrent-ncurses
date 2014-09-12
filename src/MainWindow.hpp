#pragma once

#include <cursesw.h>
#include <cursesp.h>
#include "TrackerView.hpp"
#include "TorrentView.hpp"
#include "StatusView.hpp"
#include "AddTorrent.hpp"

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
    StatusView *status;
    AddTorrentView *addtorrent;
  TrackerView *trackers;
};
