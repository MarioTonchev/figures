#include "catch_amalgamated.hpp"
#include "Rectangle.h"
#include <numbers>

TEST_CASE("Rectangle perimeter is correct")
{
    Rectangle r(10, 20);
    REQUIRE(r.perimeter() == 60);
}

TEST_CASE("Rectangle with negative sides throws")
{
    REQUIRE_THROWS_AS(Rectangle(-10, 20), std::invalid_argument);
    REQUIRE_THROWS_AS(Rectangle(10, -20), std::invalid_argument);
}

TEST_CASE("Rectangle perimeter overflow throws")
{
    double big = std::numeric_limits<double>::max();
    REQUIRE_THROWS_AS(Rectangle(big, 1), std::overflow_error);
}

TEST_CASE("Rectangle toString is correct") {
    Rectangle r(10, 20);
    REQUIRE(r.toString() == "rectangle 10.00 20.00");
}

TEST_CASE("Rectangle clone is correct") {
    Rectangle r(10, 20);
    std::unique_ptr<Figure> c = r.clone();

    REQUIRE(c->perimeter() == r.perimeter());
    REQUIRE(c.get() != &r);
}