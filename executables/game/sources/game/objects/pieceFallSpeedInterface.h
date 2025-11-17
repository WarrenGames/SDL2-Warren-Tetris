#ifndef GAME_PIECE_FALL_SPEED_INTERFACE_H
#define GAME_PIECE_FALL_SPEED_INTERFACE_H

#include "text/sdl2ttf_font.h"
#include "texturing/texturesCombo.h"

struct Essentials;
struct TimeOptions;

class SpeedInterface
{
private:
	sdl2::Font font;
	double speed;
	bool hasSpeedChanged;
	TextureCombo speedText;

public:
	explicit SpeedInterface(Essentials& essentials, const TimeOptions& timeOptions);
	~SpeedInterface() = default;
	SpeedInterface( const SpeedInterface& ) = delete;
	SpeedInterface& operator= ( const SpeedInterface& ) = delete;
	SpeedInterface( SpeedInterface&& ) = default;
	SpeedInterface& operator= ( SpeedInterface&& ) = default;
	
	void setChangement();
	void resetText(Essentials& essentials, const TimeOptions& timeOptions);
	void drawSpeedText(Essentials& essentials) const;
};

#endif //GAME_PIECE_FALL_SPEED_INTERFACE_H