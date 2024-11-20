#include "LUAEnemy.hpp"
#include "../Scripting/Lua.hpp"

LUAEnemy::LUAEnemy(const std::filesystem::path& script, int x, int y) :
    IEnemy("LUAEnemyEntity", x, y, 0)
{
    auto _script = LuaInterface::Singleton().State.safe_script_file(script.string());
}

bool LUAEnemy::WhenHit(DamageByPlayer damage, IEnemy* replaceInitialEnemy)
{
    return false;
}

void LUAEnemy::Update(float dt)
{
}

void LUAEnemy::Draw(float dt)
{
}
