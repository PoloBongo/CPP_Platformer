#include "Commands/CommandsPlayer.h"

MoveToRightCommand::MoveToRightCommand(InputPlayer* _inputPlayer) {
	this->inputPlayer = _inputPlayer;
}
void MoveToRightCommand::Execute(sf::Time _delta) {
	Command::Execute(_delta);

	inputPlayer->MoveRight(_delta);
}

JumpCommand::JumpCommand(InputPlayer* _inputPlayer) {
	this->inputPlayer = _inputPlayer;
}
void JumpCommand::Execute(sf::Time _delta) {
	Command::Execute(_delta);
	inputPlayer->Jump(_delta);
}

MoveToLeftCommand::MoveToLeftCommand(InputPlayer* _inputPlayer) {
	this->inputPlayer = _inputPlayer;
}

void MoveToLeftCommand::Execute(sf::Time _delta) {
	Command::Execute(_delta);

	inputPlayer->MoveLeft(_delta);
}

MoveToRightBulletCommand::MoveToRightBulletCommand(InputPlayer* _inputPlayer) {

	this->inputPlayer = _inputPlayer;
}

void MoveToRightBulletCommand::Execute(sf::Time _delta) {
	Command::Execute(_delta);
	inputPlayer->MoveRightBullet();
}

GamePause::GamePause(InputPlayer* _inputPlayer) {
	this->inputPlayer = _inputPlayer;
}



void GamePause::Execute() {
	inputPlayer->GamePauseMenu();
}