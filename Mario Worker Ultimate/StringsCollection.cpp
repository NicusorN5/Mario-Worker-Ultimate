#include "StringsCollection.hpp"

StringsCollection::StringsCollection() : 
	_data(nullptr), 
	_num(0) 
{};

StringsCollection::StringsCollection(std::initializer_list<const char*> lst) :
	_num(lst.size())
{
	_data = new char* [_num];
	for(size_t i = 0 ; i < _num; i++)
	{
		_data[i] = const_cast<char*>(* (lst.begin() + i));
		_map.insert({ _data[i],i });
	}
}

StringsCollection::StringsCollection(StringsCollection &lst):
	_num(lst._num),
	_data(new char*[lst._num]),
	_map(lst._map)
{
	size_t size = sizeof(char*) * _num;
	memcpy_s(_data, size, lst._data, size);
}

const char* StringsCollection::operator[](size_t i)
{
	return _data[i];
}

int StringsCollection::operator[](const std::string& str)
{
	return _map[str];
}

size_t StringsCollection::Size()
{
	return this->_num;
}

StringsCollection::~StringsCollection()
{
	delete[] _data;
}
