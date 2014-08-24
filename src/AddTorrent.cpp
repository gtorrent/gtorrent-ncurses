#include "Application.hpp"
#include "AddTorrent.hpp"

AddTorrentView::AddTorrentView(int nlines, int ncols, int begin_y, int begin_x)
  : NCursesPanel(nlines, ncols, begin_y, begin_x) {
  box();
  printw(1, 1, "Add Torrent");
  printw(3, 3, "Path: ");
  hide();
}

AddTorrentView::~AddTorrentView() {}

void AddTorrentView::processKey(int key) {
  if(key == 'a') {
    prompt();
  }
}
void AddTorrentView::clean() {
  clear();
  box();
  printw(1, 1, "Add Torrent");
  printw(3, 3, "Path: ");
  hide();
}

void AddTorrentView::prompt() {
  char chr;
  int p_x, p_y;
  show();
  keypad(false);
  if(getenv("ESCDELAY") == NULL) {
    set_escdelay(25);
  }
  while(1) {
    chr = getch();
    if((chr == 127 || chr == 8) && path.length() != 0) {
      path = path.substr(0, path.length()-1);
      getyx(p_y, p_x);
      addch(p_y, p_x-1, ' ');
      move(p_y, p_x-1);
    } else if ((chr == 127 || chr == 8) && path.length() == 0) {
    } else if (chr == '\n' && path.length() != 0) {
      clean();
      refresh();
      Application::getSingleton()->getCore()->addTorrent(path, NULL);
      path = "";
      keypad(false);
      break;
    } else if (chr == 27) {
      clean();
      refresh();
      path = "";
      keypad(false);
      break;
    } else {
      path += chr;
      addch(chr);
    }
  }
}



