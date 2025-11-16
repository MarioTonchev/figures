#include "catch_amalgamated.hpp"
#include "RandomFigureFactory.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"

TEST_CASE("RandomFigureFactory always returns a valid Figure subtype") {
    RandomFigureFactory factory;

    for (int i = 0; i < 100; i++) {
        auto fig = factory.create();

        bool isValid =
            dynamic_cast<Triangle*>(fig.get()) != nullptr ||
            dynamic_cast<Rectangle*>(fig.get()) != nullptr ||
            dynamic_cast<Circle*>(fig.get()) != nullptr;

        REQUIRE(isValid);
    }
}

TEST_CASE("RandomFigureFactory generates all figure types") {
    RandomFigureFactory factory;

    int triangles = 0, rectangles = 0, circles = 0;

    const int n = 600;

    for (int i = 0; i < n; i++) {
        auto f = factory.create();

        if (dynamic_cast<Triangle*>(f.get()))
        {
            triangles++;
        }
        if (dynamic_cast<Rectangle*>(f.get()))
        {
            rectangles++;
        }
        if (dynamic_cast<Circle*>(f.get()))
        {
            circles++;
        }
    }

    REQUIRE(triangles > 50);
    REQUIRE(rectangles > 50);
    REQUIRE(circles > 50);
}