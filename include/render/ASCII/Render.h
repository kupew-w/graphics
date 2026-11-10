#include "geomtery/Line2D.h"
#include "geomtery/Triangle2D.h"
#include "objects/Color.h"
#include "render/IRender.h"
#include "render/ASCII/Pixel.h"
#include "render/IWindow.h"
#include <vector>

namespace gp {
namespace asc 
{

class Render : public IRender 
{
private:
    std::shared_ptr<IWindow> window;
    std::vector<std::vector<Pixel>> buffer;

    void resizeBuffer();

public:
    explicit Render(std::shared_ptr<IWindow> w) : window(w) { resizeBuffer(); }

    void clear() override;
    void display() override;

    void drawPixel(int x, int y, gp::Color c);
    void drawLine(gp::Line2D);
    void drawTriangle(gp::Triangle2D);
};

}}
