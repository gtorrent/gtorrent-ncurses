#include <cursesw.h>
#include <cursesp.h>
// Parent window aka top-level window
extern NCursesWindow *parent;

// Titlebar
extern NCursesWindow *titlebar;

// Torrent list area
extern NCursesWindow *torrents;

// Torrent Statuses
extern NCursesWindow *status;

// Torrent labels
extern NCursesWindow *labels;

// Torrent Trackers
extern NCursesWindow *trackers;

// Info bar
extern NCursesWindow *infobar;

int initialize_layout();
