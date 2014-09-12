#include "TrackerView.hpp"
#include "Application.hpp"
#include <memory>

TrackerView::TrackerView(int nlines, int ncols, int begin_y, int begin_x)
    : NCursesPanel(nlines, ncols, begin_y, begin_x)
{
  this->border(' ', ACS_VLINE, ACS_HLINE, ' ', ' ', ACS_RTEE, ' ', ACS_VLINE);
  this->printw(1, 0, "Trackers");
}

void TrackerView::update()
{
  trackers = Application::getSingleton()->getCore()->getTrackers();
  int row = 0;
  for(auto it = trackers->begin(); it != trackers->end(); it++) {
    printw(row+2, 2, "%s", it->first.c_str());
    row++;
  }
}

TrackerView::~TrackerView() {}
