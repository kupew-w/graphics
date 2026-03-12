#pragma once

#include <string>
#include <cstdint>

namespace pl 
{

struct Color
{
    uint8_t r, g, b, a;
};

class IRender
{
public:
    virtual void dot(float x, float y, Color color) = 0;
    virtual void line(float x1, float y1, float x2, float y2, Color color) = 0;
    virtual void circle(float x, float y, float radius, Color color) = 0;
    virtual void rectangle(float x1, float y1, float x2, float y2, Color color) = 0;
    virtual void text(float x, float y, std::string, Color color) = 0;

    virtual int width() const = 0;
    virtual int height() const = 0;

    virtual void processEvent() = 0;
    virtual void clear() = 0;
    virtual void display() = 0;
    virtual bool isOpen() const = 0;

    IRender() = default;
    IRender(IRender&&) = default;
    IRender& operator=(IRender&&) = default;

    IRender(const IRender&) = delete;
    IRender& operator=(const IRender&) = delete;

    virtual ~IRender() = default;
};

}
