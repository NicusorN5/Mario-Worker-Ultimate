#include "Lua.hpp"

LuaInterface *_luaSingleton;

LuaInterface::LuaInterface()
{
	_luaSingleton = this;
}

LuaInterface& LuaInterface::Singleton()
{
	return *_luaSingleton;
}