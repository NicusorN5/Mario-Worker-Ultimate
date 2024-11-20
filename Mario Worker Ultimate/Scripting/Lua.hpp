#pragma once
#include <sol\sol.hpp>
#include "../Libs.hpp"

class LuaInterface
{
public:
	LuaInterface();

	static LuaInterface& Singleton();

	LuaInterface(const LuaInterface&) = delete;
	LuaInterface(LuaInterface&&) = delete;

	LuaInterface& operator=(const LuaInterface&) = delete;
	LuaInterface& operator=(LuaInterface&&) = delete;
	
	sol::state& State;
};