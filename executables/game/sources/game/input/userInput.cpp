#include "game/input/userInput.h"
#include "runGame/menus/keycodesInfos.h"
#include <cassert>

UserInput::UserInput():
	keysStates{false, false, false, false},
	escapeState{false},
	closeWindow{false},
	leftMouseButton{false},
	mousePosition{ -1, -1 }
{
	
}

void UserInput::updateMouse()
{
	while( SDL_PollEvent(&event) )
	{
		switch(event.type)
		{
			case SDL_QUIT:
				closeWindow = true;
				break;
			case SDL_KEYDOWN:
				updateEscapeKey(event.key.keysym.sym, true);
				break;
			case SDL_KEYUP:
				updateEscapeKey(event.key.keysym.sym, false);
				break;
			case SDL_MOUSEMOTION:
				mouseMoved(event.motion.x, event.motion.y);
				break;
			case SDL_MOUSEBUTTONDOWN:
				mouseButton(event.button.button, true);
				break;
			case SDL_MOUSEBUTTONUP:
				mouseButton(event.button.button, false);
				break;
		}
	}
}

void UserInput::updateEvents(const KeycodesInfos& keycodesInfos)
{
	while( SDL_PollEvent(&event) )
	{
		switch(event.type)
		{
			case SDL_QUIT:
				closeWindow = true;
				break;
			case SDL_KEYDOWN:
				updateKeyboard(event.key.keysym.sym, true, keycodesInfos);
				updateEscapeKey(event.key.keysym.sym, true);
				break;
			case SDL_KEYUP:
				updateKeyboard(event.key.keysym.sym, false, keycodesInfos);
				updateEscapeKey(event.key.keysym.sym, false);
				break;
			case SDL_MOUSEMOTION:
				mouseMoved(event.motion.x, event.motion.y);
				break;
			case SDL_MOUSEBUTTONDOWN:
				mouseButton(event.button.button, true);
				break;
			case SDL_MOUSEBUTTONUP:
				mouseButton(event.button.button, false);
				break;
		}
	}
}

void UserInput::updateKeyboard(SDL_Keycode& keycode, bool valueToSet, const KeycodesInfos& keycodesInfos)
{
	for( size_t i{0} ; i < KEY::INP_MAX ; ++i )
	{
		if( keycode == keycodesInfos.keycodes[i] )
		{
			keysStates[i] = valueToSet;
		}
	}
}

void UserInput::updateEscapeKey(SDL_Keycode keycode, bool valueToSet)
{
	if( keycode == SDLK_ESCAPE )
	{
		escapeState = valueToSet;
	}
}

bool UserInput::getKeyState(size_t index) const
{
	assert( index < keysStates.size() );
	return keysStates[index];
}

void UserInput::setKeyState(size_t index, bool newValue)
{
	assert( index < keysStates.size() );
	keysStates[index] = newValue;
}

void UserInput::mouseMoved(int x_mouse_position, int y_mouse_position)
{
	mousePosition = { x_mouse_position, y_mouse_position };
}

void UserInput::mouseButton(unsigned button, bool valueToSet)
{
	if( button == SDL_BUTTON_LEFT )
		leftMouseButton = valueToSet;
}

const Offset& UserInput::getMousePosition() const
{
	return mousePosition;
}

bool UserInput::getMouseLeftButton() const
{
	return leftMouseButton;
}

void UserInput::setMouseLeftButtonFalse()
{
	leftMouseButton = false;
}

bool UserInput::getWindowClose() const
{
	return closeWindow;
}

void UserInput::setWindowCloseFalse()
{
	closeWindow = false;
}

bool UserInput::getEscapeState() const
{
	return escapeState;
}

void UserInput::setEscapeKeyFalse()
{
	escapeState = false;
}