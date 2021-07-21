#include "button.h"

#include "../../../core/managers/resource_manager.h"
#include "../../../core/renderer.h"
#include "../../../core/input.h"

#include <SDL_ttf.h>

Button::Button(const char* text, const Size &buttonSize, const char *font, TextAlignment textAlignment, const SDL_Color &textColor, const SDL_Color &buttonColor)
{
    this->text = text;
    this->buttonSize = buttonSize;
    this->font = font;
    this->textAlignment = textAlignment;
    textCurrentColor = textColor;
    textColors.color = textColor;
    buttonCurrentColor = buttonColor;
    buttonColors.color = buttonColor;

    updateText();
}

void Button::start()
{
    transform = owner->getComponent<Transform>();
    boxCollider = owner->addComponent<BoxCollider2D>(buttonSize.w, buttonSize.h);
    camera = &transform->owner->entityManager->camera;

    rect.w = buttonSize.w;
    rect.h = buttonSize.h;

    rectangle = Draw::rectangle(rect, buttonCurrentColor.r, buttonCurrentColor.g, buttonCurrentColor.b, buttonCurrentColor.a, false);
}

void Button::update(float dt)
{
    if (owner->parent && !parentTransform)
        parentTransform = owner->parent->getComponent<Transform>();

    if (!owner->parent)
        parentTransform = nullptr;

    rectangle->rect.x = !parentTransform ? (int)(transform->position.x - camera->position.x) : (int)(transform->position.x + parentTransform->position.x - camera->position.x);
    rectangle->rect.y = !parentTransform ? (int)(transform->position.y - camera->position.y) : (int)(transform->position.y + parentTransform->position.y - camera->position.y);

    textPosition.x = rectangle->rect.x + textOffset.x;
    textPosition.y = rectangle->rect.y + textOffset.y;
    
    buttonEffects();
}

void Button::render()
{
    SDL_RenderCopy(Renderer::getRenderer(), texture, NULL, &textPosition);
}

void Button::buttonEffects()
{
    if (!onMouseHold(SDL_BUTTON_LEFT))
    {
        buttonCurrentColor = buttonColors.color;
        textCurrentColor = textColors.color;
    }

    if (buttonHoverEffect)
    {
        if (onMouseHover())
        {
            buttonCurrentColor = buttonColors.hoverColor;
            textCurrentColor = textColors.hoverColor;
        }
    }

    if (buttonPressEffect)
    {
        if (onMouseHold(SDL_BUTTON_LEFT))
        {
            buttonCurrentColor = buttonColors.pressColor;
            textCurrentColor = textColors.pressColor;
        }
    }

    rectangle->r = buttonCurrentColor.r;
    rectangle->g = buttonCurrentColor.g;
    rectangle->b = buttonCurrentColor.b;
    rectangle->a = buttonCurrentColor.a;

    SDL_SetTextureColorMod(texture, textCurrentColor.r, textCurrentColor.g, textCurrentColor.b);
    SDL_SetTextureAlphaMod(texture, textCurrentColor.a);
}

void Button::setText(const char* text)
{
    this->text = text;

    updateText();
}

void Button::setTextAlignment(const TextAlignment &textAlignment)
{
    this->textAlignment = textAlignment;

    updateText();
}

void Button::setFont(const char *font)
{
    this->font = font;

    updateText();
}

void Button::setTextColor(const SDL_Color &color)
{
    textColors.color = color;
}

void Button::setTextHoverColor(const SDL_Color &color)
{
    textColors.hoverColor = color;
}

void Button::setTextPressColor(const SDL_Color &color)
{
    textColors.pressColor = color;
}

Size Button::getTextSize()
{
    Size size;

    TTF_SizeText(ResourceManager::getFont(font), text, &size.w, &size.h);

    return size;
}

void Button::setButtonPressEffect(const bool buttonPressEffect)
{
    this->buttonPressEffect = buttonPressEffect;
}

void Button::setButtonHoverEffect(const bool buttonHoverEffect)
{
    this->buttonHoverEffect = buttonHoverEffect;
}

void Button::setButtonColor(const SDL_Color &color)
{
    buttonColors.color = color;
}

void Button::setButtonHoverColor(const SDL_Color &color)
{
    buttonColors.hoverColor = color;
}

void Button::setButtonPressColor(const SDL_Color &color)
{
    buttonColors.pressColor = color;
}

bool Button::onMouseEnter()
{
    return boxCollider->onMouseEnter();
}

bool Button::onMouseExit()
{
    return boxCollider->onMouseExit();
}

bool Button::onMouseHold(const int button)
{
    return boxCollider->onMouseHold(button);
}

bool Button::onMouseHover()
{
    return boxCollider->isHovering();
}

bool Button::onMouseDown(const int button)
{
    return boxCollider->onMouseDown(button);
}

bool Button::onMouseUp(const int button)
{
    return boxCollider->onMouseUp(button);
}

void Button::updateText()
{
    switch (textAlignment)
    {
    case TextAlignment::TOP_LEFT:
        textOffset.x = 0;
        textOffset.y = 0;
        break;
    case TextAlignment::TOP_CENTER:
        textOffset.x = (buttonSize.w / 2) - (getTextSize().w / 2);
        textOffset.y = 0;
        break;
    case TextAlignment::TOP_RIGHT:
        textOffset.x = buttonSize.w - getTextSize().w;
        textOffset.y = 0;
        break;
    case TextAlignment::MIDDLE_LEFT:
        textOffset.x = 0;
        textOffset.y = (buttonSize.h / 2) - (getTextSize().h / 2);
        break;
    case TextAlignment::MIDDLE_CENTER:
        textOffset.x = (buttonSize.w / 2) - (getTextSize().w / 2);
        textOffset.y = (buttonSize.h / 2) - (getTextSize().h / 2);
        break;
    case TextAlignment::MIDDLE_RIGHT:
        textOffset.x = buttonSize.w - getTextSize().w;
        textOffset.y = (buttonSize.h / 2) - (getTextSize().h / 2);
        break;
    case TextAlignment::BOTTOM_LEFT:
        textOffset.x = 0;
        textOffset.y = buttonSize.h - getTextSize().h;
        break;
    case TextAlignment::BOTTOM_CENTER:
        textOffset.x = (buttonSize.w / 2) - (getTextSize().w / 2);
        textOffset.y = buttonSize.h - getTextSize().h;
        break;
    case TextAlignment::BOTTOM_RIGHT:
        textOffset.x = buttonSize.w - getTextSize().w;
        textOffset.y = buttonSize.h - getTextSize().h;
        break;
    }

    SDL_Surface *surface = TTF_RenderText_Blended(ResourceManager::getFont(font), text, textCurrentColor);

    texture = SDL_CreateTextureFromSurface(Renderer::getRenderer(), surface);

    SDL_FreeSurface(surface);

    SDL_QueryTexture(texture, nullptr, nullptr, &textPosition.w, &textPosition.h);
}