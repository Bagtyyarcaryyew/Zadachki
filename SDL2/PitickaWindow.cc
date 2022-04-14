/*
 * PitickaWindow.cc
 *
 *  Created on: 3 апр. 2022 г.
 *      Author: HP
 */

#include <cmath>
#include "PitickaWindow.h"

PitickaWindow::PitickaWindow()
: Window( PITICKA_WINDOW_WIDTH, PITICKA_WINDOW_HEIGHT ),
_piticka(_renderer, "piticka.png"),
  _cloud(_renderer, "cloud.png"),
  _sun(_renderer, "sun.png"),
  _eagle(_renderer, "eagle.png"),
  _background(_renderer, "bg.png"),
  _mountains(_renderer, "mountains.png", 2.0)

{
	SDL_SetWindowTitle(_window.get(), "(o_o)");
	x = 65.0;
	y = 0.0;
	phase = 0.0;
	eagle_x = 50.0;
	eagle_y = 250.0;

}

void PitickaWindow::render()
{
	SDL_SetRenderDrawColor(_renderer.get(), 63, 192, 255, 255);
	//SDL_RenderClear(_renderer.get());
	_background.draw(0, 0);
	_sun.draw(50, 100);
	_mountains.draw(0, 190, width(), _mountains.height());

	unsigned i = 0;
	for (; i < 3; ++i)
		_cloud.draw(clouds[i]);

	_piticka.draw(x, y, (sin(phase) + cos(phase)) / 4 * 180 / 3.1415);
	_piticka.draw(x, y, (sin(phase) + cos(phase)) / 3 * 180 / 3.1415);
	_piticka.draw(x, y, (sin(phase) + cos(phase)) / 2 * 180 / 3.1415);

	_eagle.draw(eagle_x, eagle_y);
	for (; i < 6; ++i)
		_cloud.draw(clouds[i]);

}


void PitickaWindow::handle_keys(const Uint8 *keys)
{
	if (keys[SDL_SCANCODE_RIGHT]) eagle_x+= 4;
	if (keys[SDL_SCANCODE_LEFT] ) eagle_x-= 4;
	if (keys[SDL_SCANCODE_DOWN] ) eagle_y+= 4;
	if (keys[SDL_SCANCODE_UP]   ) eagle_y-= 4;


}

void PitickaWindow::update()
{
	if(eagle_x >= width())
		eagle_x = 10;
	auto pi = acos(-1.0);

	phase += pi / 90.0;
	x += 2;
	if (x >= width())
		x = -_piticka.width();
	y = height() / 2 * (1 + 0.3 * sin(phase)) - height() / 4;

	for (unsigned i = 0; i < 6; ++i) {
		clouds[i].x -= clouds[i].w / 32;
		if (clouds[i].x <= -clouds[i].w)
			clouds[i].x = width();
	}

	_mountains.update();
}
