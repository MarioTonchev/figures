#include "RandomFigureFactory.h"

static double randomDouble(double min, double max) {
	double fractionalPart = (double)rand() / RAND_MAX;

	return min + fractionalPart * (max - min);
}

std::unique_ptr<Figure> RandomFigureFactory::create() {
	int type = rand() % 3;

	const double min = 1.0;
	const double max = 10000.0;


	switch (type)
	{
		case 0:
		{
			double a = randomDouble(min, max);
			double b = randomDouble(min, max);
			double c = randomDouble(min, max);

			while (!(a + b > c && a + c > b && b + c > a))
			{
				a = randomDouble(min, max);
				b = randomDouble(min, max);
				c = randomDouble(min, max);
			}

			return std::make_unique<Triangle>(a, b, c);
		}
		case 1:
		{
			double w = randomDouble(min, max);
			double h = randomDouble(min, max);
			return std::make_unique<Rectangle>(w, h);
		}
		case 2:
		{
			double r = randomDouble(min, max);
			return std::make_unique<Circle>(r);

			break;
	}
	}

	return nullptr;
}