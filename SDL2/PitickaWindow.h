/*
 * PitickaWindow.h
 *
 *  Created on: 3 апр. 2022 г.
 *      Author: HP
 */

#ifndef PITICKAWINDOW_H_
#define PITICKAWINDOW_H_

#include "Window.h"
#include "Texture.h"
#include "LayerTexture.h"

class PitickaWindow final: public Window
{
private:
	Texture _piticka;
	Texture _cloud;
	Texture _eagle;
	Texture _sun;
	Texture _background;
	LayerTexture _mountains;

	double x, y, phase;
	double eagle_x, eagle_y;

	static constexpr int PITICKA_WINDOW_WIDTH = 800;
	static constexpr int PITICKA_WINDOW_HEIGHT = 600;

    SDL_FRect clouds[6] {
		{ 128.0, 200.0, 128.0,  64.0 },
		{ 356.0, 430.0, 192.0,  70.0 },
		{ 500.0, 340.0, 160.0,  90.0 },
		{  50.0,  20.0, 384.0, 192.0 },
		{ 320.0, 179.0, 380.0, 200.0 },
		{ 220.0, 230.0, 500.0, 320.0 },

	};


public:
	PitickaWindow();
	virtual ~PitickaWindow() = default;

	virtual void render() override;
	virtual void handle_keys(const Uint8 *keys) override;
	virtual void update() override;
};

#endif /* PITICKAWINDOW_H_ */
