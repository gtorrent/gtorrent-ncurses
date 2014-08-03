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
    init_pair(1, COLOR_RED, COLOR_BLACK);
	colors["Paused"]                  = 1;
    init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
	colors["Queued for checking"]     = 2;
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	colors["Downloading metadata..."] = 3;
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
	colors["Finished"]                = 4;
    init_pair(5, COLOR_CYAN, COLOR_BLACK);
	colors["Seeding"]                 = 5;
    init_pair(6, COLOR_GREEN, COLOR_BLACK);
	colors["Downloading"]             = 6;

	colors["Allocating..."]           = 0;
	colors["Resuming..."]             = 0;
	colors["Checking..."]             = 0;
}

void TorrentView::update()
{
    erase();

    std::vector<std::shared_ptr<gt::Torrent>> torrents = Application::getSingleton()->getCore()->getTorrents();

    if(selected >= torrents.size()) // if we're out of bound reset the cursor
        selected = 0;

    for(unsigned i = 0;i < torrents.size();++i)
    {
        unsigned c = colors[torrents[i]->getTextState()];
        attron(COLOR_PAIR(c));
        if(i == selected)
        {
            attron(A_REVERSE);
            this->printw(i, 0, "%s", (torrents[i]->getName()).c_str());
            attroff(A_REVERSE);
        }
        else
            this->printw(i, 0, "%s", (torrents[i]->getName()).c_str());
        attroff(COLOR_PAIR(c));
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

void TorrentView::processKey(int key) {
    if(key == KEY_DOWN)
        selectionDown();
    else if(key == KEY_UP)
        selectionUp();
}
