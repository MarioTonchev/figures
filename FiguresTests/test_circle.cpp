#include "catch_amalgamated.hpp"
#include "Circle.h"
#include <numbers>

TEST_CASE("Circle perimeter is correct")
{
    Circle c(10);
    REQUIRE(c.perimeter() == 2 * std::numbers::pi * 10);
}

TEST_CASE("Circle with negative radius throws")
{
    REQUIRE_THROWS_AS(Circle(-10), std::invalid_argument);
}

TEST_CASE("Circle perimeter overflow throws")
{
    double big = std::numeric_limits<double>::max();
    REQUIRE_THROWS_AS(Circle(big), std::overflow_error);
}

TEST_CASE("Circle toString is correct") {
    Circle c(10);
    REQUIRE(c.toString() == "circle 10.00");
}

TEST_CASE("Circle clone is correct") {
    Circle c1(10);
    std::unique_ptr<Figure> c2 = c1.clone();

    REQUIRE(c2->perimeter() == c1.perimeter());
    REQUIRE(c2.get() != &c1);
}