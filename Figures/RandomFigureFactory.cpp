#include "RandomFigureFactory.h"

std::unique_ptr<Figure> RandomFigureFactory::create() {
	int type = rand() % 3;

	switch (type)
	{
	case 0:
		double a = 1 + rand() % 20;
		double b = 1 + rand() % 20;
		double c = 1 + rand() % 20;
		return  std::make_unique<Triangle>(a, b, c);

		break;
	case 1:
		double w = 1 + rand() % 20;
		double h = 1 + rand() % 20;
		return std::make_unique<Rectangle>(w, h);

		break;
	case 2:
		double r = 1 + rand() % 20;
		return std::make_unique<Circle>(r);

		break;
	}

	return nullptr;
}