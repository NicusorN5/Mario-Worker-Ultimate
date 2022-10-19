#include "IButton.hpp"
#include "TransparentFont.hpp"


class Checkbox
{
	Texture2D _checkedTxd;
	Texture2D _uncheckedTxd;

	TransparentFont& _font;
	std::string _text;

	Vector2 _pos;

	bool _checked;
public:
	Checkbox(Checkbox&) = delete;
	Checkbox(Texture2D _cTxd, Texture2D _ucTxd, TransparentFont& f, const std::string& text, bool defState, Vector2 txtpos);

	bool GetState();

	void Draw(float dt);
	void Update(MouseState* ms, float dt);

	std::function<bool()> OnStateChange = nullptr;
};