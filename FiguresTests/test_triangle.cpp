#include "catch_amalgamated.hpp"
#include "Triangle.h"
#include <numbers>

TEST_CASE("Triangle perimeter is correct")
{
    Triangle t(11, 20, 30);
    REQUIRE(t.perimeter() == 61);
}

TEST_CASE("Triangle with negative sides throws")
{
    REQUIRE_THROWS_AS(Triangle(-10, 20, 30), std::invalid_argument);

    REQUIRE_THROWS_AS(Triangle(10, -20, 30), std::invalid_argument);

    REQUIRE_THROWS_AS(Triangle(10, 20, -30), std::invalid_argument);
}

TEST_CASE("Triangle violating inequality throws")
{
    REQUIRE_THROWS_AS(Triangle(1, 2, 100), std::invalid_argument);

    REQUIRE_THROWS_AS(Triangle(1, 100, 2), std::invalid_argument);

    REQUIRE_THROWS_AS(Triangle(100, 2, 1), std::invalid_argument);
}

TEST_CASE("Triangle perimeter overflow throws")
{
    double maxDouble = std::numeric_limits<double>::max();

    REQUIRE_THROWS_AS(Triangle(maxDouble, maxDouble, maxDouble), std::overflow_error);
}

TEST_CASE("Triangle toString is correct") {
    Triangle t(11, 20, 30);
    REQUIRE(t.toString() == "triangle 11.00 20.00 30.00");
}

TEST_CASE("Triangle clone is correct") {
    Triangle t(11, 20, 30);
    std::unique_ptr<Figure> c = t.clone();

    REQUIRE(c->perimeter() == t.perimeter());
    REQUIRE(c.get() != &t);
}