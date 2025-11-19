#define CATCH_CONFIG_RUNNER
#include "catch_amalgamated.hpp"
#include "RegisterFigures.h"

int main(int argc, char* argv[])
{
    registerAllFigures();
    return Catch::Session().run(argc, argv);
}