#include "RegisterFigures.h"
#include "FigureRegistry.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"

void registerAllFigures() {
    auto& reg = FigureRegistry::getInstance();

    reg.registerType("triangle",
        [](std::istream& in) {
            double a, b, c;
            in >> a >> b >> c;
            return std::make_unique<Triangle>(a, b, c);
        });

    reg.registerType("rectangle",
        [](std::istream& in) {
            double w, h;
            in >> w >> h;
            return std::make_unique<Rectangle>(w, h);
        });

    reg.registerType("circle",
        [](std::istream& in) {
            double r;
            in >> r;
            return std::make_unique<Circle>(r);
        });
}