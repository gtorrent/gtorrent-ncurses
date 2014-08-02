#include <gtorrent/Core.hpp>
#include <gtorrent/Settings.hpp>

void setDefaults(&gt::Settings s)
{
	s.setDefaultOption("ncurses.PausedForeGroundColor"      , "#F08080");
	s.setDefaultOption("ncurses.PausedBackGroundColor"      , "#800000");
	s.setDefaultOption("ncurses.QueuedForeGroundColor"      , "#00BFFF");
	s.setDefaultOption("ncurses.QueuedBackGroundColor"      , "#FFFFFF");
	s.setDefaultOption("ncurses.SeedingForeGroundColor"     , "#1E90FF");
	s.setDefaultOption("ncurses.SeedingBackGroundColor"     , "#ADD8E6");
	s.setDefaultOption("ncurses.MetadataForeGroundColor"    , "#228B22");
	s.setDefaultOption("ncurses.MetadataBackGroundColor"    , "#7FFFD4");
	s.setDefaultOption("ncurses.FinishedForeGroundColor"    , "#ADD8E6");
	s.setDefaultOption("ncurses.FinishedBackGroundColor"    , "#483D8B");
	s.setDefaultOption("ncurses.ResumingForeGroundColor"    , "#6495ED");
	s.setDefaultOption("ncurses.ResumingBackGroundColor"    , "#FAF0E6");
	s.setDefaultOption("ncurses.CheckingForeGroundColor"    , "#DAA520");
	s.setDefaultOption("ncurses.CheckingBackGroundColor"    , "#FFFACD");
	s.setDefaultOption("ncurses.AllocatingForeGroundColor"  , "#FF7F50");
	s.setDefaultOption("ncurses.AllocatingBackGroundColor"  , "#FAFAD2");
	s.setDefaultOption("ncurses.DownloadingForeGroundColor" , "#228B43");
	s.setDefaultOption("ncurses.DownloadingBackGroundColor" , "#FFFFFF");
}
