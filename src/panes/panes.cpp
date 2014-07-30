#include "panes.hpp"
// Constructors
PANE::PANE() {
    window = newwin(0,0,0,0);
    getmaxyx(window, rows, columns);
    x = 0;
    y = 0;
}

PANE::PANE(int r, int c, int oy, int ox) {
    window = newwin(r, c, oy, ox);
    getmaxyx(window, rows, columns);
    y = oy;
    x = ox;
}

PANE::PANE(int r, int c, int oy, int ox, PANE* mparent) {
    window = derwin(*mparent, r, c, oy, ox);
    getmaxyx(window, rows, columns);
    y = oy;
    x = ox;
    parent = mparent;
}

PANE::PANE(int r, int c, int oy, int ox, WINDOW* mparent) {
    window = derwin(mparent, r, c, oy, ox);
    getmaxyx(window, rows, columns);
    y = oy;
    x = ox;
    parent = new PANE(rows, columns, y, x);;
}

PANE::PANE(WINDOW* win) {
    window = win;
    getmaxyx(win, rows, columns);
    getbegyx(win, y, x);
}

PANE::~PANE() {
}

// Unique functions
int PANE::addchild(PANE* child) {
    children.push_back(child);
    child->parent = this;
    return 1;
}

// BUGGY!!!
int PANE::addchild(WINDOW* child) {
    children.push_back(new PANE(child));
    children.back()->parent = this;
    return 1;
}

int PANE::addchild() {
    children.push_back(new PANE(rows, columns, y, x, this));
    return 1;
}

int PANE::addchild(int r, int c, int oy, int ox) {
    children.push_back(new PANE(r, c, oy, ox, this));
    return 1;
}

std::vector<PANE*> PANE::_children() {
    return children;
}


// Function wrappers
int PANE::_addstr(const char * str) {
    return waddstr(*this, str);
}

int PANE::_addchar(const chtype ch) {
    return waddch(*this, ch);
}

int PANE::_printw(const char *fmt, ...) {
    va_list args;
    va_start(args, *fmt);
    return wprintw(*this, fmt, args);
    va_end(args);
}

int PANE::_refresh() {
    return wrefresh(*this);
}

int PANE::_border(chtype ls, chtype rs, chtype ts, chtype bs, chtype tl, chtype tr, chtype bl, chtype br) {
    return wborder(*this, ls, rs, ts, bs, tl, tr, bl, br);
}

int PANE::_border(chtype all) {
    return wborder(*this, all, all, all, all, all, all, all, all);
}
