#pragma once

#include "FigureFactory.h"

class RandomFigureFactory : public FigureFactory {
public:
	Figure* create() override;
};