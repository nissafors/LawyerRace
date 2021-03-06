/*
    Lawyer Race - A game about escaping the law
    Copyright (C) 2012 Samuel Andersson

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include "Text.hpp"
#include <iostream>
#include <sstream>
#include "Log.hpp"

std::map<int, TTF_Font*> Text::standard_font;
std::list<Text*> Text::s_textList;

Text::Text()
{
    m_color.r = 0;
    m_color.g = 0;
    m_color.b = 0;
}


Text::Text(const int _number, const int _fontSize, const int _xPos, const int _yPos, int r, int g, int b)
    : m_fontSize(_fontSize)
{
    m_visible = true;
    m_xPos = static_cast<float>(_xPos);
    m_yPos = static_cast<float>(_yPos);

    m_color.r = r;
    m_color.g = g;
    m_color.b = b;

    std::string text = numberToText(_number);

    m_surf = TTF_RenderText_Blended(standard_font[_fontSize], text.c_str(), m_color);
    m_height = m_surf->h;
    m_width = m_surf->w;
}


Text::Text(std::string _text, const int _fontSize, const int _xPos, const int _yPos, int r, int g, int b)
    : m_fontSize(_fontSize)
{
    m_visible = true;
    m_xPos = static_cast<float>(_xPos);
    m_yPos = static_cast<float>(_yPos);

    m_color.r = r;
    m_color.g = g;
    m_color.b = b;

    if ((m_surf = TTF_RenderText_Blended(standard_font[_fontSize], _text.c_str(), m_color)) == NULL)
        LOG_ERROR << "Couldn't render text \"" << _text << "\".\n"; //TODO: ERRORHANDLING
    m_height = m_surf->h;
    m_width = m_surf->w;
}

Text::~Text()
{
}

void Text::draw(SDL_Surface* _destSurf) {
    if(!m_visible) return;

    SDL_Rect destRect;
    destRect.x = (Sint16)(m_xPos);
    destRect.y = (Sint16)(m_yPos);

    SDL_BlitSurface(m_surf, NULL, _destSurf, &destRect);
}

void Text::updateText(const int _number) {
    std::string text = numberToText(_number);
    updateText(text);
}

void Text::updateText(const std::string _newText) {
    m_surf = TTF_RenderText_Blended(standard_font[m_fontSize], _newText.c_str(), m_color);
    m_height = m_surf->h;
    m_width = m_surf->w;
}

//Position text
void Text::setXPos(const float _xPos) {
    m_xPos = _xPos;
}
void Text::setYPos(const float _yPos) {
    m_yPos = _yPos;
}

const std::string Text::numberToText(int _number)
{
    std::stringstream ss;
    ss << _number;
    return ss.str();
}

void Text::setColor(int r, int g, int b) {
    m_color.r = r;
    m_color.g = g;
    m_color.b = b;
}

