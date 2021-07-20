#pragma once

#include "label.h"
#include "../../../core/draw.h"

enum TextAlignment
{
    TOP_LEFT,
    TOP_CENTER,
    TOP_RIGHT,
    MIDDLE_LEFT,
    MIDDLE_CENTER,
    MIDDLE_RIGHT,
    BOTTOM_LEFT,
    BOTTOM_CENTER,
    BOTTOM_RIGHT
};

struct MouseStateColors
{
    SDL_Color color, hoverColor, pressColor;
};

class Button : public Component
{
public:
	Button(const std::string& text, const Size& buttonSize, const char* font, TextAlignment textAlignment, const SDL_Color& textColor, const SDL_Color& buttonColor);
	void start() override;
	void update(float dt) override;
	void render() override;
	void setText(const std::string& text);
    void setTextAlignment(const TextAlignment &textAlignment);
	void setFont(const char* font);
	void setTextColor(const SDL_Color& color);
    void setTextHoverColor(const SDL_Color& color);
    void setTextPressColor(const SDL_Color& color);
	Size getTextSize();

	void setButtonPressEffect(const bool buttonPressEffect);
    void setButtonColor(const SDL_Color& color);
    void setButtonHoverColor(const SDL_Color& color);
    void setButtonPressColor(const SDL_Color& color);

    bool onMouseEnter();
	bool onMouseExit();
    bool onMouseHold(const int button);
    bool onMouseHover();
    bool onMouseDown(const int button);
	bool onMouseUp(const int button);

private:
	Camera* camera = nullptr;
	Transform* transform = nullptr;
	Transform* parentTransform = nullptr;

	std::string text;
	const char* font = nullptr;
	SDL_Rect textPosition;
    Vector2 textOffset;
    Size buttonSize;
	SDL_Texture* texture = nullptr;

    bool buttonPressEffect = false;
    SDL_Color textCurrentColor;
    MouseStateColors textColors;

    SDL_Color buttonCurrentColor;
    MouseStateColors buttonColors;

    TextAlignment textAlignment;

    SDL_Rect rect;
    Rectangle *rectangle;

    bool mouseHover, entered, exited;

private:
	void updateText();
    void checkMouseHover();
};