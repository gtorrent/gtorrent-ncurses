#include "TorrentView.hpp"
#include "gtorrent/Torrent.hpp"
#include "Application.hpp"
#include <vector>
#include <memory>
#include <iostream> //FIXME: debug

TorrentView::TorrentView(int nlines, int ncols, int begin_y, int begin_x)
    : NCursesPanel(nlines, ncols, begin_y, begin_x),
    selected(0)
{
}

void TorrentView::update()
{
    erase();

    std::vector<std::shared_ptr<gt::Torrent>> torrents = Application::getSingleton()->getCore()->getTorrents();

    if(selected >= torrents.size()) // if we're out of bound reset the cursor
        selected = 0;

    for(unsigned i = 0;i < torrents.size();++i)
    {
        if(i == selected)
        {
            attron(A_REVERSE);
            this->printw(i, 0, (torrents[i]->getHandle().name()).c_str());
            attroff(A_REVERSE);
        }
        else
            this->printw(i, 0, (torrents[i]->getHandle().name()).c_str());
    }
    refresh();
}

void TorrentView::selectionDown()
{
    std::vector<std::shared_ptr<gt::Torrent>> t = Application::getSingleton()->getCore()->getTorrents();
    if(selected < t.size())
        ++selected;
}

void TorrentView::selectionUp()
{
    if(selected > 0)
        ++selected;
}
