#include "StatusView.hpp"
#include "Application.hpp"
#include <memory>
#include <iostream> //FIXME: debug

StatusView::StatusView(int nlines, int ncols, int begin_y, int begin_x)
    : NCursesPanel(nlines, ncols, begin_y, begin_x)
{
}

void StatusView::update()
{
    printw(1, 2, "All (%zu)", Application::getSingleton()->getCore()->getTorrents().size());
    printw(2, 2, "Downloading (%zu)", Application::getSingleton()->getCore()->getStatuses()->downloading.size());
    printw(3, 2, "Seeding (%zu)", Application::getSingleton()->getCore()->getStatuses()->seeding.size());
    printw(4, 2, "Checking (%zu)", Application::getSingleton()->getCore()->getStatuses()->checking.size());
    printw(5, 2, "Finished (%zu)", Application::getSingleton()->getCore()->getStatuses()->finished.size());
    printw(6, 2, "Stopped (%zu)", Application::getSingleton()->getCore()->getStatuses()->stopped.size());
    refresh();
}

StatusView::~StatusView() {}
