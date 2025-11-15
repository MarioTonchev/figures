#include "RandomFigureFactory.h"

std::unique_ptr<Figure> RandomFigureFactory::create() {
	int type = rand() % 3;

	switch (type)
	{
		case 0:
		{
			double a = 1 + rand() % 20;
			double b = 1 + rand() % 20;
			double c = 1 + rand() % 20;

			//we do this to fix triangle inequality if there is any
			while (!(a + b > c && a + c > b && b + c > a))
			{
				a = 1 + rand() % 20;
				b = 1 + rand() % 20;
				c = 1 + rand() % 20;
			}

			return std::make_unique<Triangle>(a, b, c);
		}
		case 1:
		{
			double w = 1 + rand() % 20;
			double h = 1 + rand() % 20;
			return std::make_unique<Rectangle>(w, h);
		}
		case 2:
		{
			double r = 1 + rand() % 20;
			return std::make_unique<Circle>(r);

			break;
	}
	}

	return nullptr;
}