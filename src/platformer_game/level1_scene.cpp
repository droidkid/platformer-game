#include "platformer_game/level1_scene.h"
#include "engine/game_engine_constants.h"

#include <algorithm>
using namespace std;

using namespace GameEngineConstants;

void Level1::init() {
	// Create All Game Objects
	assetLoader->loadPNGintoTexture("assets/PNG/Backgrounds/set1_background.png", &background1);
	assetLoader->loadPNGintoTexture("assets/PNG/Backgrounds/set1_tiles.png", &background2);
	assetLoader->loadPNGintoTexture("assets/PNG/Backgrounds/set1_hills.png", &background3);

	assetLoader->loadPNGintoTexture("assets/PNG/Other/fluidGreen.png", &ground);

	player = new PlayerGameObject(assetLoader);
	enemy = new EnemyGameObject(assetLoader);
	block2 = new BlockGameObject(assetLoader, 240, 180, 80);
	block1 = new BlockGameObject(assetLoader, 240-80, 210, 80);
	camera = new WorldCamera();

	collisionManager->addGameObject(player);
	collisionManager->addGameObject(enemy);
	collisionManager->addGameObject(block2);
	collisionManager->addGameObject(block1);
}

void Level1::draw(Canvas *canvas) {
	
	camera->setXY(max(0.0, player->getPhysics()->x - 150), 0);

	canvas->clearScreen();
	canvas->setCamera(camera);

	canvas->drawTexture(background1, { 0, 0, 600, 480 });
	canvas->drawTexture(background2, { 0, 0, 600, 480 });
	canvas->drawTexture(background3, { 0, 0, 600, 480 });
	canvas->drawTexture(background1, { 600, 0, 600, 480 });
	canvas->drawTexture(background2, { 600, 0, 600, 480 });
	canvas->drawTexture(background3, { 600, 0, 600, 480 });
	canvas->drawTexture(background1, { 1200, 0, 600, 480 });
	canvas->drawTexture(background2, { 1200, 0, 600, 480 });
	canvas->drawTexture(background3, { 1200, 0, 600, 480 });

	for (int i = 0; i < 600; i = i + 64) {
		canvas->drawTexture(ground, {i, 310, 64, 64});
	}

	for (int i = 900; i < 2400; i = i + 64) {
		canvas->drawTexture(ground, {i, 310, 64, 64});
	}

	for (int i = 0; i < 2400; i = i + 64) {
		canvas->drawTexture(ground, {i, 310 + 64, 64, 64});
	}
	for (int i = 0; i < 2400; i = i + 64) {
		canvas->drawTexture(ground, {i, 310 + 128, 64, 64});
	}

	player->draw(canvas);
	enemy->draw(canvas);
	block1->draw(canvas);
	block2->draw(canvas);

	canvas->renderScreen();
}

void Level1::update(Input *input) {

	player->update(input);
	enemy->update(input);

	collisionManager->handleCollisions();

}
