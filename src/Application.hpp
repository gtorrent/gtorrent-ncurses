#pragma once

#include <ncurses.h>
//#include "Version.hpp"
#define GTORRENT_VERSION "FIXME"
#include <memory>
#include <gtorrent/Log.hpp>
#include <gtorrent/Core.hpp>
#include "MainWindow.hpp"

class Application
{
private:
	static std::shared_ptr<Application> m_app;

	// Private Member Functions & Variables
	std::shared_ptr<gt::Core> m_core;
	std::shared_ptr<MainWindow> m_gui;

public:
	static std::shared_ptr<Application> getSingleton();

	// Getters
	std::shared_ptr<gt::Core> &getCore();

	// Public Member Functions & Variables
	int run(int argc, char **argv);
};
