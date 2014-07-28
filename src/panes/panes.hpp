#include <ncurses.h>
#include <vector>

class PANE : WINDOW {
    private:
        std::vector<PANE*> children;
        PANE* parent;
    public:
        PANE();
        PANE(int w, int h, int ox, int oy);
        PANE(int w, int h, int ox, int oy, PANE* parent);
        ~PANE();

        int width, height, x, y;


};
