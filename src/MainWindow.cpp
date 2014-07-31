#include "MainWindow.hpp"

MainWindow::MainWindow()
    : NCursesPanel()
{
    curs_set(0);
    start_color();

    init_pair(1, COLOR_MAGENTA, COLOR_BLACK);

    titlebar = new NCursesPanel(2, this->cols(), 0, 0);
    titlebar->border(' ', ' ', ' ',ACS_HLINE, ' ', ' ',ACS_HLINE,ACS_HLINE);
    titlebar->attron(COLOR_PAIR(1));
    titlebar->printw(0, (titlebar->cols()-8)/2, "gTorrent");
    titlebar->attroff(COLOR_PAIR(1));
    //titlebar->addch(1, 19, ACS_TTEE);

    infobar = new NCursesPanel(2, this->cols(), this->lines() - 2, 0);
    infobar->border(' ', ' ', ACS_HLINE, ' ', ACS_HLINE, ACS_HLINE, ' ', ' ');
    //infobar->addch(0, 19, ACS_BTEE);

    torrents = new NCursesPanel(this->lines()-4, this->cols(), 2, 0);
    torrents->printw(0,0,"lorem ipsup sit dolem amet");

    refresh();
}

MainWindow::~MainWindow()
{
    delete titlebar;
    delete infobar;
    delete torrents;
}
