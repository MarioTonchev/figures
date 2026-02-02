#include "RandomFigureFactory.h"

static double randomDouble(double min, double max) {
	double fractionalPart = (double)rand() / RAND_MAX;

	return min + fractionalPart * (max - min);
}

std::unique_ptr<Figure> RandomFigureFactory::create() {
	int type = rand() % 3;

	const double min = 1.0;
	const double max = 10000.0;

	std::stringstream ss;

	switch (type)
	{
		case 0:
		{
			double a = randomDouble(min, max);
			double b = randomDouble(min, max);

			double lower = std::fabs(a - b) + 0.0001;   
			double upper = a + b - 0.0001;              

			if (lower < min) lower = min + 0.0001;
			if (upper > max) upper = max - 0.0001;

			if (lower >= upper)
			{
				a = randomDouble(min, max);
				b = randomDouble(min, max);

				lower = std::fabs(a - b) + 0.0001;
				upper = a + b - 0.0001;

				if (lower < min) lower = min + 0.0001;
				if (upper > max) upper = max - 0.0001;
			}

			double c = randomDouble(lower, upper);

			ss << a << " " << b << " " << c;
			return FigureRegistry::getInstance().create("triangle", ss);
		}
		case 1:
		{
			double w = randomDouble(min, max);
			double h = randomDouble(min, max);

			ss << w << " " << h;
			return FigureRegistry::getInstance().create("rectangle", ss);
		}
		case 2:
		{
			double r = randomDouble(min, max);

			ss << r;
			return FigureRegistry::getInstance().create("circle", ss);
		}
	}

	return nullptr;
}