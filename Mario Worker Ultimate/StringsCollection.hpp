#pragma once
#include <initializer_list>
#include <memory>
#include <unordered_map>

// std::vector<const std::string&> is not allowed, using this as a replacement:

class StringsCollection
{
	char** _data;
	size_t _num;
	std::unordered_map<std::string, int> _map;
public:
	StringsCollection();
	StringsCollection(std::initializer_list<const char*> lst);
	explicit StringsCollection(StringsCollection& lst);

	const char* operator[](size_t i);

	int operator[](const std::string& str);
	size_t Size();

	~StringsCollection();
};

