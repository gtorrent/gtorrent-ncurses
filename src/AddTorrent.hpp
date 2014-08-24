#pragma once

#include <cursesw.h>
#include <cursesp.h>
#include "gtorrent/Core.hpp"
#include "gtorrent/Torrent.hpp"
#include "strings.h"

class AddTorrentView : public NCursesPanel {
private:
  std::string path;
public:
  AddTorrentView(int nlines, int ncols, int begin_y, int begin_x);
  ~AddTorrentView();

  void processKey(int key);
  void prompt();

  void clean();

  
};
