#include "StatusView.hpp"
#include "Application.hpp"
#include <memory>

unsigned StatusView::getStatusCount(const libtorrent::torrent_status::state_t &status)
{
    unsigned i = 0;
    std::vector<std::shared_ptr<gt::Torrent>> torrents = Application::getSingleton()->getCore()->getTorrents();
    for(auto t : torrents)
        if(t->getState() == status)
            ++i;
    return i;
}

unsigned StatusView::getPausedCount()
{
    unsigned i = 0;
    std::vector<std::shared_ptr<gt::Torrent>> torrents = Application::getSingleton()->getCore()->getTorrents();
    for(auto t : torrents)
        if(t->getHandle().status().paused)
            ++i;
    return i;
}

StatusView::StatusView(int nlines, int ncols, int begin_y, int begin_x)
    : NCursesPanel(nlines, ncols, begin_y, begin_x)
{
    update();
}

void StatusView::update()
{
    printw(1, 2, "All (%zu)", Application::getSingleton()->getCore()->getTorrents().size());
    printw(2, 2, "Downloading (%u)", getStatusCount(libtorrent::torrent_status::state_t::downloading));
    printw(3, 2, "Seeding (%u)", getStatusCount(libtorrent::torrent_status::state_t::seeding));
    printw(4, 2, "Checking (%u)", getStatusCount(libtorrent::torrent_status::state_t::checking_files));
    printw(5, 2, "Completed (%u)", getStatusCount(libtorrent::torrent_status::state_t::finished));
    printw(6, 2, "Paused (%u)", getPausedCount());
    refresh();
}

StatusView::~StatusView() {}
