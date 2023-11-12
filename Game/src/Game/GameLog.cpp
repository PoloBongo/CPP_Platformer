#include "Game/GameLog.h"
#include <iostream>

void GameLog::log(const std::string& _message) {
	std::cout << std::string("Log : ") << _message << std::endl;
}
void GameLog::debug(const std::string& _message) {
	std::cout << std::string("Debug : ") << _message << std::endl;
}
void GameLog::error(const std::string& _message) {
	std::cerr << std::string("Error : ") << _message << std::endl;
}