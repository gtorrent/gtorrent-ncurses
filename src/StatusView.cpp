#include "StatusView.hpp"
#include "gtorrent/Torrent.hpp"
#include "Application.hpp"
#include <memory>
#include <iostream> //FIXME: debug

StatusList::StatusList() {
    std::vector<std::shared_ptr<gt::Torrent>> torrents = Application::getSingleton()->getCore()->getTorrents();
    for(unsigned i = 0; i < torrents.size(); i++) {
        if(torrents[i]->getState() == downloading) {
            t_downloading.push_back(torrents[i]);
        }
    }
}

StatusView::StatusView(int nlines, int ncols, int begin_y, int begin_x)
    : NCursesPanel(nlines, ncols, begin_y, begin_x)
{
}

void StatusView::update()
{
    erase();

    std::vector<std::shared_ptr<gt::Torrent>> torrents = Application::getSingleton()->getCore()->getTorrents();
    for(unsigned i = 0;i < torrents.size();++i)
        this->printw(i, 0, (torrents[i]->getHandle().name()).c_str());
    refresh();
}
