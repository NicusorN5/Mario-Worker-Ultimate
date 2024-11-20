#include "IButton.hpp"
#include "SpriteFont.hpp"


class Checkbox
{
	Texture2D _checkedTxd;
	Texture2D _uncheckedTxd;

	SpriteFont* _font;
	std::string _text;

	Vector2 _pos;
	Vector2 _scale;
	Vector2 _boxS;
	float _spacing;
public:
	Checkbox() = default;
	Checkbox(Texture2D _cTxd, Texture2D _ucTxd, SpriteFont* f, const std::string& text, bool defState, Vector2 txtpos, Vector2 boxScale, Vector2 scale, float spacing);

	bool Checked;

	void Draw(float dt);
	void Update(MouseState* ms, float dt);

	std::function<void(bool)> OnStateChange = nullptr;
};