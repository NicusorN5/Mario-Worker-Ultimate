#pragma once
#include <exception>
#include <filesystem>

class GameResourceLoadException : std::exception
{
	std::string _file;
public:
	GameResourceLoadException(const std::filesystem::path& file) : _file(file.string()) {};
	char const* what() const override;
};

