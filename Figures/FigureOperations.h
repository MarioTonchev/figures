#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include "Figure.h"

void printFigures(const std::vector<std::unique_ptr<Figure>>& figures, std::ostream& out);

void cloneFigure(std::vector<std::unique_ptr<Figure>>& figures);

void deleteFigure(std::vector<std::unique_ptr<Figure>>& figures);