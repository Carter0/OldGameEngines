/*
 * Breakout.cpp
 *
 *  Created on: Feb 2, 2020
 *  Author: Carter Weinberg
 */

#include "Breakout.hpp"

void Breakout::createBasicLevel(unsigned int level) {
	balls.clear();
	balls.push_back(Ball());
	powerUps.clear();
	hasLost = false;
	hasWon = false;

	ResourceManager::getInstance().loadLevel(bricks, level);

	if (walls.size() == 0) {
		const int xStart = 200;
		const int yStart = 100;
		const int brickW = 120;
		const int wallThickness = 10;

		//Top wall
		walls.push_back(Brick(BoundingBox(xStart - wallThickness - 1, yStart - wallThickness - 1, 8 * brickW + wallThickness * 2 + 1, wallThickness),SDL_Color { 255, 255, 255, 255 }, -1));
		//Left Wall
		walls.push_back(Brick(BoundingBox(xStart - wallThickness - 1, yStart - 1,wallThickness, 500),SDL_Color { 255, 255, 255, 255 }, -1));
		//Right Wall
		walls.push_back(Brick(BoundingBox(8 * brickW + xStart, yStart - 1, wallThickness, 500), SDL_Color { 255, 255, 255, 255 }, -1));
	}
}

Breakout::Breakout() {
	balls.push_back(Ball());
	playerPaddle = PlayerPaddle();
	level = 1;
	createBasicLevel(level);
}

void Breakout::setLevel(unsigned int newlevel) {
	level = newlevel;
}

unsigned int Breakout::getLevel() {
	return level;
}

void Breakout::setFont(const std::string &resPath) {
	font = ResourceManager::getInstance().loadFont(resPath);
	if (font == nullptr) {
		std::cout << "TTF_OpenFont" << " error: " << SDL_GetError() << std::endl;
	}
}

void Breakout::start(){
    AudioManager::getInstance().playMusic(music);
}

void Breakout::update() {
	// Update PowerUps
	std::vector<PowerUp>::iterator pIter;
	for (pIter = powerUps.begin();  pIter != powerUps.end();) {
		pIter->update();
		pIter->collision(playerPaddle);
		if (pIter->isOffScreen() || pIter->isConsumed()) {
			pIter = powerUps.erase(pIter);
		} else {
			pIter++;
		}
	}

	// Update bricks
	std::vector<Brick>::iterator iter;
	for (iter = bricks.begin(); iter != bricks.end();) {
		for (Ball& ball: balls) {
			iter->collision(ball);
			iter->update();
		}
		if (iter->isDestroyed()) {
			// Do we generate a power up?
			float chance = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			if (chance <= powerUpChance) {
				BoundingBox b = iter->getPosition();
				powerUps.push_back(PowerUp(b.x,b.y));
				powerUpChance = powerUpBase;
			} else {
				powerUpChance += powerUpIncrease;
			}
			iter = bricks.erase(iter);
			score += 247;
		} else {
			++iter;
		}
	}
	for (auto w : walls) {
		for (Ball& ball: balls) {
			w.collision(ball);
		}
		w.update();
	}

	for (Ball& ball: balls) {
		playerPaddle.collision(ball);
	}
	playerPaddle.update();

	std::vector<Ball>::iterator bIter;
	for (bIter = balls.begin();  bIter != balls.end();) {
		bIter->update();
		if (bIter->isballOffScreen()) {
			bIter = balls.erase(bIter);
		} else {
			bIter++;
		}
	}
	if (balls.empty()) {
		playerPaddle.loseLife();
		balls.push_back(Ball());
	}

	if (playerPaddle.getLives() == 0) {
		hasLost = true;
	}

	if (bricks.size() == 0) {
		hasWon = true;
	}
}

void Breakout::render(std::shared_ptr<SDL_Renderer> renderer) {
	playerPaddle.render(renderer.get());

	for (auto ball : balls)
		ball.render(renderer.get());

	/*
	 * I do not like the text rendering below for a few reasons.
	 * 1. I only really need to reallocate data about the score and the text when certain
	 * events in the game happen, like a player breaks a brick or a ball goes off screen. Right now
	 * I am doing it every frame, which is wasteful as well.
	 * 2. I also think some of this code can be moved to other places.
	 *
	 *  - Carter, Feb 5th
	 */

	char livesBuffer[50];
	if (!(hasLost || hasWon)) {
		sprintf(livesBuffer, "%s %d", LocaleManager::getInstance().getText(LIVES).c_str(), playerPaddle.getLives());
	} else if (hasWon && level == MAXLEVEL) {
		sprintf(livesBuffer, "%s", LocaleManager::getInstance().getText(YOU_WIN).c_str());
	} else {
		sprintf(livesBuffer, "%s", LocaleManager::getInstance().getText(GAME_OVER).c_str()); //TODO: game over text crashes the game?
	}

	char scoreBuffer[15];
	sprintf(scoreBuffer, "%s %d", LocaleManager::getInstance().getText(SCORE).c_str(), score);

	//The SDL surface needed for our lives and scor text
	SDL_Color color = { 255, 255, 255, 255 };
	std::shared_ptr < SDL_Surface > livesSurface = create_shared(
			TTF_RenderUTF8_Blended(font.get(), livesBuffer, color));
	std::shared_ptr < SDL_Surface > scoreSurface = create_shared(
			TTF_RenderUTF8_Blended(font.get(), scoreBuffer, color));
	if (livesSurface == nullptr || scoreSurface == nullptr) {
		std::cout << "TTF_RenderText" << " error: " << SDL_GetError()
				<< std::endl;
	}

	//The SDL texture that contains our lives and score text
	std::shared_ptr < SDL_Texture > livesTexture = create_shared(
			SDL_CreateTextureFromSurface(renderer.get(), livesSurface.get()));
	std::shared_ptr < SDL_Texture > scoreTexture = create_shared(
			SDL_CreateTextureFromSurface(renderer.get(), scoreSurface.get()));
	if (livesTexture == nullptr || scoreTexture == nullptr) {
		std::cout << "CreateTexture" << " error: " << SDL_GetError()
				<< std::endl;
	}

	//Get information about how long our text is going to be.
	int wLives, hLives, wScore, hScore;
	SDL_QueryTexture(livesTexture.get(), NULL, NULL, &wLives, &hLives);
	SDL_QueryTexture(scoreTexture.get(), NULL, NULL, &wScore, &hScore);
	int x1 = 200;
	//int y1 = hLives;
	int x2 = 1200 - wScore; //Set the score to be the right of the screen.
	//int y2 = hScore;
	SDL_Rect livesRect = { x1, 25, wLives, hLives };
	SDL_Rect scoreRect = { x2, 25, wScore, hScore };

	for (auto b : bricks)
		b.render(renderer.get());
	for (auto w : walls)
		w.render(renderer.get());
	for (auto p : powerUps)
		p.render(renderer.get());

	//Render everything on the screen.
	SDL_RenderCopy(renderer.get(), livesTexture.get(), NULL, &livesRect);
	SDL_RenderCopy(renderer.get(), scoreTexture.get(), NULL, &scoreRect);

}

void Breakout::keyInput(const std::string &direction, const bool isDown) {
	if (isDown) {
		if (direction == "left") {
			playerPaddle.setVelocity(1, false);
		} else if (direction == "right") {
			playerPaddle.setVelocity(-1, true);
		}
	} else {
		playerPaddle.setVelocity(0, true);
	}
}

int Breakout::getEndCondition() {
	if (!(hasLost || hasWon)) {
		return 0;
	} else if (hasWon) {
		return 1;
	} else {
		return 2;
	}
}

void Breakout::triball() {
	std::vector<Ball> newBalls;
	for (Ball& ball : balls) {
		newBalls.push_back(ball.split());
		newBalls.push_back(ball.split());
	}
	balls.insert(balls.end(), newBalls.begin(), newBalls.end());
}
