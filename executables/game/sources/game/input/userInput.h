#ifndef USER_INPUT_H
#define USER_INPUT_H

#include "game/input/inputsConsts.h"
#include "customTypes/positionTypes.h"
#include "SDL.h"
#include <array>

struct KeycodesInfos;

class UserInput
{
private:
	std::array<bool, KEY::INP_MAX> keysStates;
	bool escapeState;
	bool closeWindow;
	bool leftMouseButton;
	Offset mousePosition;
	SDL_Event event;
	
public:
	explicit UserInput();
	~UserInput() = default;
	UserInput( const UserInput& Copy ) = delete;
	UserInput& operator= ( const UserInput& Copy ) = delete;
	
	void updateMouse();
	void updateEvents(const KeycodesInfos& keycodesInfos);
	void updateKeyboard(SDL_Keycode& keycode, bool valueToSet, const KeycodesInfos& keycodesInfos);
	void updateEscapeKey(SDL_Keycode keycode, bool valueToSet);
	bool getKeyState(std::size_t index) const;
	void setKeyState(std::size_t index, bool newValue);
	
	void mouseMoved(int x_mouse_position, int y_mouse_position);
	void mouseButton(unsigned button, bool valueToSet);
	const Offset& getMousePosition() const;
	bool getMouseLeftButton() const;
	void setMouseLeftButtonFalse();
	
	bool getWindowClose() const;
	void setWindowCloseFalse();
	bool getEscapeState() const;
	void setEscapeKeyFalse();
};

#endif //USER_INPUT_H