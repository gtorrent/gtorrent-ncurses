#include "TorrentView.hpp"
#include "gtorrent/Torrent.hpp"
#include "Application.hpp"
#include <vector>
#include <memory>
#include <iostream> //FIXME: debug

TorrentView::TorrentView(int nlines, int ncols, int begin_y, int begin_x)
    : NCursesPanel(nlines, ncols, begin_y, begin_x)
{
}

void TorrentView::update()
{
    erase();

    std::vector<std::shared_ptr<gt::Torrent>> torrents = Application::getSingleton()->getCore()->getTorrents();
    for(unsigned i = 0;i < torrents.size();++i)
        this->printw(i, 0, (torrents[i]->getHandle().name()).c_str());
    refresh();
}
