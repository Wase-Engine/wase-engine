#include "button.h"

#include "../../../core/managers/resource_manager.h"
#include "../../../core/renderer.h"
#include "../../../core/input.h"

#include <SDL_ttf.h>

namespace wase
{
    Button::Button(const char* t_Text, const char* t_Font, const Size& t_ButtonSize, const TextAlignment& t_TextAlignment, const SDL_Color& t_TextColor, const SDL_Color& t_ButtonColor)
        : m_Text(t_Text), m_Font(t_Font), m_ButtonSize(t_ButtonSize), m_TextAlignment(t_TextAlignment)
    {
        m_TextCurrentColor = t_TextColor;
        m_TextColors.color = t_TextColor;
        m_ButtonCurrentColor = t_ButtonColor;
        m_ButtonColors.color = t_ButtonColor;

        updateText();
    }

    void Button::start()
    {
        m_Transform = owner->getComponent<Transform>();
        m_BoxCollider = owner->addComponent<BoxCollider2D>(m_ButtonSize.w, m_ButtonSize.h);
        m_Camera = &m_Transform->owner->entityManager->camera;

        m_Rect.w = m_ButtonSize.w;
        m_Rect.h = m_ButtonSize.h;

        m_Rectangle = Draw::rectangle(m_Rect, m_ButtonCurrentColor.r, m_ButtonCurrentColor.g, m_ButtonCurrentColor.b, m_ButtonCurrentColor.a, false);
    }

    void Button::update(float dt)
    {
        if (owner->parent && !m_ParentTransform)
            m_ParentTransform = owner->parent->getComponent<Transform>();

        if (!owner->parent)
            m_ParentTransform = nullptr;

        m_Rectangle->rect.x = !m_ParentTransform ? (int)(m_Transform->position.x - m_Camera->position.x) : (int)(m_Transform->position.x + m_ParentTransform->position.x - m_Camera->position.x);
        m_Rectangle->rect.y = !m_ParentTransform ? (int)(m_Transform->position.y - m_Camera->position.y) : (int)(m_Transform->position.y + m_ParentTransform->position.y - m_Camera->position.y);

        m_TextPosition.x = int(m_Rectangle->rect.x + m_TextOffset.x);
        m_TextPosition.y = int(m_Rectangle->rect.y + m_TextOffset.y);

        buttonEffects();
    }

    void Button::render()
    {
        SDL_RenderCopy(Renderer::getRenderer(), m_Texture, NULL, &m_TextPosition);
    }

    void Button::buttonEffects()
    {
        if (!onMouseHold(SDL_BUTTON_LEFT))
        {
            m_ButtonCurrentColor = m_ButtonColors.color;
            m_TextCurrentColor = m_TextColors.color;
        }

        if (m_ButtonHoverEffect)
        {
            if (onMouseHover())
            {
                m_ButtonCurrentColor = m_ButtonColors.hoverColor;
                m_TextCurrentColor = m_TextColors.hoverColor;
            }
        }

        if (m_ButtonPressEffect)
        {
            if (onMouseHold(SDL_BUTTON_LEFT))
            {
                m_ButtonCurrentColor = m_ButtonColors.pressColor;
                m_TextCurrentColor = m_TextColors.pressColor;
            }
        }

        m_Rectangle->r = m_ButtonCurrentColor.r;
        m_Rectangle->g = m_ButtonCurrentColor.g;
        m_Rectangle->b = m_ButtonCurrentColor.b;
        m_Rectangle->a = m_ButtonCurrentColor.a;

        SDL_SetTextureColorMod(m_Texture, m_TextCurrentColor.r, m_TextCurrentColor.g, m_TextCurrentColor.b);
        SDL_SetTextureAlphaMod(m_Texture, m_TextCurrentColor.a);
    }

    void Button::setText(const char* text)
    {
        this->m_Text = text;

        updateText();
    }

    void Button::setTextAlignment(const TextAlignment& textAlignment)
    {
        this->m_TextAlignment = textAlignment;

        updateText();
    }

    void Button::setFont(const char* font)
    {
        this->m_Font = font;

        updateText();
    }

    void Button::setTextColor(const SDL_Color& color)
    {
        m_TextColors.color = color;
    }

    void Button::setTextHoverColor(const SDL_Color& color)
    {
        m_TextColors.hoverColor = color;
    }

    void Button::setTextPressColor(const SDL_Color& color)
    {
        m_TextColors.pressColor = color;
    }

    Size Button::getTextSize()
    {
        Size size;

        TTF_SizeText(ResourceManager::getFont(m_Font), m_Text, &size.w, &size.h);

        return size;
    }

    void Button::setButtonPressEffect(const bool buttonPressEffect)
    {
        this->m_ButtonPressEffect = buttonPressEffect;
    }

    void Button::setButtonHoverEffect(const bool m_ButtonHoverEffect)
    {
        this->m_ButtonHoverEffect = m_ButtonHoverEffect;
    }

    void Button::setButtonColor(const SDL_Color& color)
    {
        m_ButtonColors.color = color;
    }

    void Button::setButtonHoverColor(const SDL_Color& color)
    {
        m_ButtonColors.hoverColor = color;
    }

    void Button::setButtonPressColor(const SDL_Color& color)
    {
        m_ButtonColors.pressColor = color;
    }

    bool Button::onMouseEnter()
    {
        return m_BoxCollider->onMouseEnter();
    }

    bool Button::onMouseExit()
    {
        return m_BoxCollider->onMouseExit();
    }

    bool Button::onMouseHold(const int button)
    {
        return m_BoxCollider->onMouseHold(button);
    }

    bool Button::onMouseHover()
    {
        return m_BoxCollider->isHovering();
    }

    bool Button::onMouseDown(const int button)
    {
        return m_BoxCollider->onMouseDown(button);
    }

    bool Button::onMouseUp(const int button)
    {
        return m_BoxCollider->onMouseUp(button);
    }

    void Button::updateText()
    {
        switch (m_TextAlignment)
        {
        case TextAlignment::TOP_LEFT:
            m_TextOffset.x = 0;
            m_TextOffset.y = 0;
            break;
        case TextAlignment::TOP_CENTER:
            m_TextOffset.x = (float)((m_ButtonSize.w / 2) - (getTextSize().w / 2));
            m_TextOffset.y = 0;
            break;
        case TextAlignment::TOP_RIGHT:
            m_TextOffset.x = (float)(m_ButtonSize.w - getTextSize().w);
            m_TextOffset.y = 0;
            break;
        case TextAlignment::MIDDLE_LEFT:
            m_TextOffset.x = 0;
            m_TextOffset.y = (float)((m_ButtonSize.h / 2) - (getTextSize().h / 2));
            break;
        case TextAlignment::MIDDLE_CENTER:
            m_TextOffset.x = (float)((m_ButtonSize.w / 2) - (getTextSize().w / 2));
            m_TextOffset.y = (float)((m_ButtonSize.h / 2) - (getTextSize().h / 2));
            break;
        case TextAlignment::MIDDLE_RIGHT:
            m_TextOffset.x = (float)(m_ButtonSize.w - getTextSize().w);
            m_TextOffset.y = (float)((m_ButtonSize.h / 2) - (getTextSize().h / 2));
            break;
        case TextAlignment::BOTTOM_LEFT:
            m_TextOffset.x = 0;
            m_TextOffset.y = (float)(m_ButtonSize.h - getTextSize().h);
            break;
        case TextAlignment::BOTTOM_CENTER:
            m_TextOffset.x = (float)((m_ButtonSize.w / 2) - (getTextSize().w / 2));
            m_TextOffset.y = (float)(m_ButtonSize.h - getTextSize().h);
            break;
        case TextAlignment::BOTTOM_RIGHT:
            m_TextOffset.x = (float)(m_ButtonSize.w - getTextSize().w);
            m_TextOffset.y = (float)(m_ButtonSize.h - getTextSize().h);
            break;
        }

        SDL_Surface* surface = TTF_RenderText_Blended(ResourceManager::getFont(m_Font), m_Text, m_TextCurrentColor);

        m_Texture = SDL_CreateTextureFromSurface(Renderer::getRenderer(), surface);

        SDL_FreeSurface(surface);

        SDL_QueryTexture(m_Texture, nullptr, nullptr, &m_TextPosition.w, &m_TextPosition.h);
    }
}