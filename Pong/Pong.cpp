﻿#include "Bat.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

int main() {
	// create a video mode object
	VideoMode vm(1920, 1080);

	// create and open a window for the game
	RenderWindow window(vm, "Pong", Style::Fullscreen);

	int score = 0;
	int lives = 3;

	// create a bat at the bottom cneter of the screen
	Bat bat(1920 / 2, 1080 - 20);

	// create a ball

	//create a Text object called "hud"
	Text hud;

	// retro style font
	Font font;
	font.loadFromFile("fonts/font.ttf");

	// set the font to the hud
	hud.setFont(font);

	// font size adjustment
	hud.setCharacterSize(75);

	// font color selection
	hud.setFillColor(Color::White);
	hud.setPosition(20, 20);

	// timing clock
	Clock clock;

	while (window.isOpen()) {
		/*
			handle the player input
		*/

		Event event;

		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				// quit the game when the window is closed
				window.close();
			}
		}

		// handle the player quitting
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			window.close();
		}

		// handle the pressing and releasing of the arrow keys
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			bat.moveLeft();
		} else {
			bat.stopLeft();
		}

		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			bat.moveRight();
		} else {
			bat.stopRight();
		}

		/*
			update the bat, the ball and the hud
		*/

		// update the delta time
		Time deltaTime = clock.restart();
		bat.update(deltaTime);

		// update the hud text
		std::stringstream ss;
		ss << "Score:" << score << " Lives:" << lives;
		hud.setString(ss.str());

		/*
			draw the bat, the bal and the hud
		*/

		window.clear();
		window.draw(hud);
		window.draw(bat.getShape());
		window.display();
	}

	return 0;
}