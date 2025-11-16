#include "catch_amalgamated.hpp"
#include "StringToFigure.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"

TEST_CASE("StringToFigure parses valid triangle") {
    StringToFigure converter;
    std::unique_ptr<Figure> f = converter.createFigureFrom("triangle 11 20 30");

    REQUIRE(f->toString() == "triangle 11.00 20.00 30.00");
    REQUIRE(typeid(*f) == typeid(Triangle));
}

TEST_CASE("StringToFigure parses valid rectangle") {
    StringToFigure converter;
    std::unique_ptr<Figure> f = converter.createFigureFrom("rectangle 10 20");

    REQUIRE(f->toString() == "rectangle 10.00 20.00");
    REQUIRE(typeid(*f) == typeid(Rectangle));
}

TEST_CASE("StringToFigure parses valid circle") {
    StringToFigure converter;
    std::unique_ptr<Figure> f = converter.createFigureFrom("circle 7.75");

    REQUIRE(f->toString() == "circle 7.75");
    REQUIRE(typeid(*f) == typeid(Circle));
}

TEST_CASE("StringToFigure rejects empty string") {
    StringToFigure converter;
    REQUIRE_THROWS_AS(converter.createFigureFrom(""), std::invalid_argument);
}

TEST_CASE("StringToFigure detects missing parameters") {
    StringToFigure converter;
    REQUIRE_THROWS_AS(converter.createFigureFrom("triangle 10 20"), std::invalid_argument);
    REQUIRE_THROWS_AS(converter.createFigureFrom("rectangle 10"), std::invalid_argument);
    REQUIRE_THROWS_AS(converter.createFigureFrom("circle"), std::invalid_argument);
}

TEST_CASE("StringToFigure rejects non-numeric parameters") {
    StringToFigure converter;
    REQUIRE_THROWS_AS(converter.createFigureFrom("triangle 10 abc 30"), std::invalid_argument);
    REQUIRE_THROWS_AS(converter.createFigureFrom("rectangle x y"), std::invalid_argument);
    REQUIRE_THROWS_AS(converter.createFigureFrom("circle hello"), std::invalid_argument);
}

TEST_CASE("StringToFigure rejects negative values") {
    StringToFigure converter;
    REQUIRE_THROWS_AS(converter.createFigureFrom("triangle -10 20 30"), std::invalid_argument);
    REQUIRE_THROWS_AS(converter.createFigureFrom("rectangle -5 12"), std::invalid_argument);
    REQUIRE_THROWS_AS(converter.createFigureFrom("circle -3"), std::invalid_argument);
}

TEST_CASE("StringToFigure rejects unknown figure type") {
    StringToFigure converter;
    REQUIRE_THROWS_AS(converter.createFigureFrom("unknown 10 20 30"), std::invalid_argument);
}