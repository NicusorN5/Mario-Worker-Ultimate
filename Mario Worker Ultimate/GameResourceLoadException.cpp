#include "GameResourceLoadException.hpp"

char const* GameResourceLoadException::what() const
{
    return this->_file;
}
