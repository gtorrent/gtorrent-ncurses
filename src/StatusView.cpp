#include "StatusView.hpp"
#include "Application.hpp"
#include <memory>
#include <iostream> //FIXME: debug

StatusList::StatusList() {
    update();
}

void StatusList::update() {
    std::vector<std::shared_ptr<gt::Torrent>> torrents = Application::getSingleton()->getCore()->getTorrents();
    for(unsigned i = 0; i < torrents.size(); i++) {
        if(torrents[i]->getState() == libtorrent::torrent_status::state_t::downloading) {
            t_downloading.push_back(torrents[i]);
        } else if (torrents[i]->getState() == libtorrent::torrent_status::state_t::checking_files) {
            t_checking.push_back(torrents[i]);
        } else if (torrents[i]->getState() == libtorrent::torrent_status::state_t::finished) {
            t_completed.push_back(torrents[i]);
        } else if (torrents[i]->getState() == libtorrent::torrent_status::state_t::seeding) {
            t_seeding.push_back(torrents[i]);
        } else {
            t_stopped.push_back(torrents[i]);
        }
    }
}

StatusList::~StatusList() {}

StatusView::StatusView(int nlines, int ncols, int begin_y, int begin_x)
    : NCursesPanel(nlines, ncols, begin_y, begin_x)
{
    update();
}

void StatusView::update()
{
    statlist.update();
    printw(1, 2, "All (%d)", Application::getSingleton()->getCore()->getTorrents().size());
    printw(2, 2, "Downloading (%d)", statlist.t_downloading.size());
    printw(3, 2, "Seeding (%d)", statlist.t_seeding.size());
    printw(4, 2, "Checking (%d)", statlist.t_checking.size());
    printw(5, 2, "Completed (%d)", statlist.t_completed.size());
    printw(6, 2, "Stopped (%d)", statlist.t_stopped.size());
    refresh();
}

StatusView::~StatusView() {}
