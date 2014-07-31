#pragma once

#include <cursesw.h>
#include <cursesp.h>

class MainWindow : public NCursesPanel
{
    public:
    MainWindow();
    ~MainWindow();

    private:
    NCursesPanel *titlebar;
};
