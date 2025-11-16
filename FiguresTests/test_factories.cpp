#include "catch_amalgamated.hpp"
#include "StreamFigureFactory.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"

TEST_CASE("StreamFigureFactory reads a single triangle correctly") {
    std::string input = "triangle 11 20 30\n";
    std::istringstream iss(input);

    StreamFigureFactory factory(iss);
    auto f= factory.create();

    REQUIRE(f->toString() == "triangle 11.00 20.00 30.00");
    REQUIRE(typeid(*f) == typeid(Triangle));
}

TEST_CASE("StreamFigureFactory reads multiple figures correcly") {
    std::string input =
        "circle 5\n"
        "rectangle 3 7\n"
        "triangle 3 4 5\n";

    std::istringstream iss(input);
    StreamFigureFactory factory(iss);

    auto f1 = factory.create();
    auto f2 = factory.create();
    auto f3 = factory.create();

    REQUIRE(f1->toString() == "circle 5.00");
    REQUIRE(f2->toString() == "rectangle 3.00 7.00");
    REQUIRE(f3->toString() == "triangle 3.00 4.00 5.00");
}

TEST_CASE("StreamFigureFactory throws on empty stream") {
    std::string input = "";
    std::istringstream iss(input);

    StreamFigureFactory factory(iss);
    REQUIRE_THROWS_AS(factory.create(), std::runtime_error);
}

TEST_CASE("StreamFigureFactory throws on invalid input") {
    std::string input = "triangle 10 20\n";
    std::istringstream iss(input);

    StreamFigureFactory factory(iss);
    REQUIRE_THROWS_AS(factory.create(), std::invalid_argument);
}

TEST_CASE("StreamFigureFactory continues after parsing error") {
    std::string input =
        "invalid 10 20 30\n"
        "circle 5\n";

    std::istringstream iss(input);
    StreamFigureFactory factory(iss);

    REQUIRE_THROWS_AS(factory.create(), std::invalid_argument);

    std::unique_ptr<Figure> f = factory.create();
    REQUIRE(f->toString() == "circle 5.00");
}