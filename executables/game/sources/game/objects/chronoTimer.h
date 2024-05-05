#ifndef GAME_CHRONO_TIMER_H
#define GAME_CHRONO_TIMER_H

#include "text/sdl2ttf_font.h"
#include "time/accurateTime.h"
#include "texturing/texturesCombo.h"
#include <string>

struct Essentials;

class ChronoTimer
{
private:
	const sdl2::Font arial;
	AccurateTimeDelay chrono;
	unsigned elapsedMinutes;
	unsigned elapsedSeconds;
	TextureCombo chronoGraphicalText;
	bool doesTextNeedChange;

public:
	explicit ChronoTimer(Essentials& essentials);
	~ChronoTimer() = default;
	ChronoTimer( const ChronoTimer& ) = delete;
	ChronoTimer& operator= ( const ChronoTimer& ) = delete;
	
	std::string getText() const;
	void changeGraphicalTextIfNeeded(Essentials& essentials);
	void drawText(Essentials& essentials) const;
	void mesureElapsedTime();
};

#endif //GAME_CHRONO_TIMER_H