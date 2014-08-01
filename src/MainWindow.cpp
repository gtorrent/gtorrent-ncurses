#include "MainWindow.hpp"
#include "Application.hpp"
#include <chrono>

MainWindow::MainWindow()
    : NCursesPanel()
{
    curs_set(0);
    start_color();
    nodelay(true);// getch is not blocking

    titlebar = new NCursesPanel(2, this->cols(), 0, 0);
    titlebar->border(' ', ' ', ' ',ACS_HLINE, ' ', ' ',ACS_HLINE,ACS_HLINE);
    titlebar->attron(COLOR_PAIR(1));
    titlebar->printw(0, (titlebar->cols()-8)/2, "gTorrent");
    titlebar->attroff(COLOR_PAIR(1));
    titlebar->addch(1, 19, ACS_TTEE);

    infobar = new NCursesPanel(2, this->cols(), this->lines() - 2, 0);
    infobar->border(' ', ' ', ACS_HLINE, ' ', ACS_HLINE, ACS_HLINE, ' ', ' ');
    //infobar->addch(0, 19, ACS_BTEE);

    torrents = new TorrentView(this->lines()-4, this->cols()-20, 2, 20);

    status = new StatusView(7, 20, 2, 0);
    status->border(' ', ACS_VLINE, ' ', ' ', ' ', ACS_VLINE, ' ', ACS_VLINE);
    status->attron(A_BOLD);
    status->printw(0, 0, "Status");
    status->attroff(A_BOLD);

    refresh();

    loop();
}

MainWindow::~MainWindow()
{
    delete titlebar;
    delete infobar;
    delete torrents;

    endwin();
    Application::getSingleton()->getCore()->shutdown();
}

void MainWindow::tick()
{
    torrents->update();
    status->update();
}

void MainWindow::loop()
{
    using namespace std::chrono;
    static steady_clock::time_point t = steady_clock::now();
    while(true) {
        int chr = getch();
        if((duration_cast<milliseconds>(steady_clock::now() - t)).count() >= 200)
        {
            tick();
            t = steady_clock::now();
        }
        torrents->processKey(chr);
        if(chr == 'q') {
            break;
        }
    }
}
