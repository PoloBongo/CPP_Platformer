#pragma once

#include "Game/GameConfig.h"
#include "Game/GameStats.h"
#include "Game/GameState.h"
#include "Game/GameLog.h"


class Game
{
public:
	Game();

	void run();
	GameConfig* getConfig() const { return config; }
	GameLog* getLog() const { return log; }
	GameState* getState() const { return state; }
	GameStats* getStats() const { return stats; }

	~Game();

private:
	GameConfig* config = nullptr;
	GameLog* log = nullptr;
	GameState* state = nullptr;
	GameStats* stats = nullptr;
};

