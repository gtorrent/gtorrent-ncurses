#include <cursesw.h>
#include <cursesp.h>
// Parent window aka top-level window
extern NCursesPanel *parent;

// Titlebar
extern NCursesPanel *titlebar;

// Torrent list area
extern NCursesPanel *torrents;

// Torrent Statuses
extern NCursesPanel *status;

// Torrent labels
extern NCursesPanel *labels;

// Torrent Trackers
extern NCursesPanel *trackers;

// Info bar
extern NCursesPanel *infobar;

int initialize_layout();
