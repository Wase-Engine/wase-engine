#pragma once

#include "../../component.h"
#include "../transform.h"
#include "../colliders/box_collider_2d.h"
#include "../../../core/draw.h"
#include "../../../core/size.h"

namespace wase
{
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
        Button(const char* t_Text, const char* t_Font, const Size& t_ButtonSize, const TextAlignment& t_TextAlignment, const SDL_Color& t_TextColor, const SDL_Color& t_ButtonColor);

        void start() override;
        void update(float dt) override;
        void render() override;

        void setText(const char* text);
        void setTextAlignment(const TextAlignment& textAlignment);
        void setFont(const char* font);
        void setTextColor(const SDL_Color& color);
        void setTextHoverColor(const SDL_Color& color);
        void setTextPressColor(const SDL_Color& color);
        Size getTextSize();

        void setButtonPressEffect(const bool buttonPressEffect);
        void setButtonHoverEffect(const bool buttonHoverEffect);
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
        Camera* m_Camera = nullptr;
        Transform* m_Transform = nullptr;
        Transform* m_ParentTransform = nullptr;
        BoxCollider2D* m_BoxCollider = nullptr;

        const char* m_Text;
        const char* m_Font = nullptr;
        SDL_Rect m_TextPosition;
        Vector2 m_TextOffset;
        Size m_ButtonSize;
        SDL_Texture* m_Texture = nullptr;

        bool m_ButtonPressEffect = false;
        bool m_ButtonHoverEffect = false;
        SDL_Color m_TextCurrentColor;
        MouseStateColors m_TextColors;

        SDL_Color m_ButtonCurrentColor;
        MouseStateColors m_ButtonColors;

        TextAlignment m_TextAlignment;

        SDL_Rect m_Rect;
        Rectangle* m_Rectangle = nullptr;

    private:
        void buttonEffects();
        void updateText();
    };
}