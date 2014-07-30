#include <ncurses.h>
#include <vector>
#include <strings.h>
#include <cstdarg>


class PANE {
    private:
        // Private Variables
        WINDOW*              window;
        std::vector<PANE*> children;
        PANE*                parent;
    public:
        // Public variables
        int rows, columns, x, y;

        // Conversions
        PANE(WINDOW* win);
        operator WINDOW* () { return window; };
        operator WINDOW () { return *window; };

        // Unique functions
        int addchild(PANE* child);
        int addchild(WINDOW* child);
        int addchild();
        int addchild(int r, int c, int oy, int ox);
        std::vector<PANE*> _children();

        // Function wrappers
        int _addstr(const char * str);
        int _addchar(const chtype ch);
        int _printw(const char *fmt, ...);
        int _refresh();
        int _border(chtype ls, chtype rs, chtype ts, chtype bs, chtype tl, chtype tr, chtype bl, chtype br);
        int _border(chtype all);

        // Constructors and destructor
        PANE();
        PANE(int r, int c, int oy, int ox);
        PANE(int r, int c, int oy, int ox, WINDOW* mparent);
        PANE(int r, int c, int oy, int ox, PANE* mparent);
        PANE(PANE* mparent);
        ~PANE();
};

