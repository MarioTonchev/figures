#include "FigureFactorySelector.h"

FigureFactory* FigureFactorySelector::createFactory(std::string& type, std::istream* in = nullptr) {
	if (type == "random")
	{
		return new RandomFigureFactory();
	}
	else if (type == "stream")
	{
		if (!in)
		{
			throw std::invalid_argument("StreamFactory requires an input stream");
		}

		return new StreamFigureFactory(*in);
	}
	else
	{
		throw std::invalid_argument("Factory type is not supported");
	}
}