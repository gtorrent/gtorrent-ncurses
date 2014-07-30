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
    rows = r;
    columns = c;
    y = oy;
    x = ox;
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
    children.push_back(new PANE(rows, columns, y, x));
    return 1;
}

int PANE::addchild(int r, int c, int oy, int ox) {
    children.push_back(new PANE(r, c, oy, ox));
    return 1;
}

int PANE::addchild(int r, int c, int oy, int ox, PANE* child) {
    // TODO: Implement a function to resize windows
    child->rows = r;
    child->columns = c;
    child->y = oy;
    child->x = ox;
    children.push_back(child);
    children.back()->parent = this;
    return 1;
}

std::vector<PANE*> PANE::_children() {
    return children;
}

/* WINDOW* PANE::_window() {
    return window;
} */


// Function wrappers
int PANE::_addstr(const char * str) {
    return waddstr(*this, str);
}

int PANE::_addch(const chtype ch) {
    return waddch(*this, ch);
}

int PANE::_mvaddch(int y, int x, const chtype ch) {
    return mvwaddch(*this, y, x, ch);
}

int PANE::_printw(const char *fmt, ...) { // TODO: Fix this
    va_list args;
    va_start(args, fmt);
    vwprintw(*this, fmt, args);
    va_end(args);
    return 1;
}

int PANE::_mvprintw(int y, int x, const char *fmt, ...) { // TODO: Fix this
    va_list args;
    va_start(args, *fmt);
    wmove(*this, y, x);
    vwprintw(*this, fmt, args);
    va_end(args);
    return 1;
}

int PANE::_refresh() { // TODO: Fix the PANE creation functions so that this isn't redundant
    wrefresh(*this);
    for(int i = 0; i < children.size(); i++) {
        children[i]->_refresh();
    }
    return 1;
}

int PANE::_border(chtype ls, chtype rs, chtype ts, chtype bs, chtype tl, chtype tr, chtype bl, chtype br) {
    return wborder(*this, ls, rs, ts, bs, tl, tr, bl, br);
}

int PANE::_border(chtype all) {
    return wborder(*this, all, all, all, all, all, all, all, all);
}

int PANE::_attron(attr_t attrs) {
    return wattron(*this, attrs);
}

int PANE::_attroff(attr_t attrs) {
    return wattroff(*this, attrs);
}
