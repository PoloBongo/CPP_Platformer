#pragma once
#include <string>

class GameLog
{
public:
	static void log(const std::string& _message);
	static void debug(const std::string& _message);
	static void error(const std::string& _message);
};
