#include "RandomFigureFactory.h"

Figure* RandomFigureFactory::create() {
	int type = rand() % 3;

	switch (type)
	{
	case 0:
		double a = 1 + rand() % 20;
		double b = 1 + rand() % 20;
		double c = 1 + rand() % 20;
		return new Triangle(a, b, c);

		break;
	case 1:
		double w = 1 + rand() % 20;
		double h = 1 + rand() % 20;
		return new Rectangle(w, h);

		break;
	case 2:
		double r = 1 + rand() % 20;
		return new Circle(r);

		break;
	}

	return nullptr;
}