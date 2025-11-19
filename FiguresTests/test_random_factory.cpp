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

TEST_CASE("RandomFigureFactory values are within expected numeric range") {
    RandomFigureFactory factory;

    for (int i = 0; i < 200; i++) {
        auto fig = factory.create();

        double min = 1.0;
        double max = 10001.0;

        if (auto t = dynamic_cast<Triangle*>(fig.get())) {
            REQUIRE(t->getA() >= min);
            REQUIRE(t->getB() >= min);
            REQUIRE(t->getC() >= min);

            REQUIRE(t->getA() <= max);
            REQUIRE(t->getB() <= max);
            REQUIRE(t->getC() <= max);
        }
        if (auto r = dynamic_cast<Rectangle*>(fig.get())) {
            REQUIRE(r->getWidth() >= min);
            REQUIRE(r->getHeight() >= min);

            REQUIRE(r->getWidth() <= max);
            REQUIRE(r->getHeight() <= max);
        }
        if (auto c = dynamic_cast<Circle*>(fig.get())) {
            REQUIRE(c->getRadius() >= min);
            REQUIRE(c->getRadius() <= max);
        }
    }
}

TEST_CASE("RandomFigureFactory reproducibility with fixed seed") {
    srand(12345);

    RandomFigureFactory f1;
    std::vector<std::string> firstRun;

    for (int i = 0; i < 20; i++) {
        auto fig = f1.create();
        firstRun.push_back(fig->toString());
    }

    srand(12345);

    RandomFigureFactory f2;
    for (int i = 0; i < 20; i++) {
        auto fig = f2.create();
        REQUIRE(fig->toString() == firstRun[i]);
    }
}
