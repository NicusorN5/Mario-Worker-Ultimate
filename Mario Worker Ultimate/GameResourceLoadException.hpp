#pragma once
#include <exception>

class GameResourceLoadException : std::exception
{
	const char* _file;
public:
	GameResourceLoadException(const char* file) : _file(file) {};
	char const* what() const override;
};

