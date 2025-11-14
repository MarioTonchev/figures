#include "FigureFactorySelector.h"

std::unique_ptr<FigureFactory> FigureFactorySelector::createFactory(std::string& type, std::istream* in = nullptr) {
	if (type == "random")
	{
		return std::make_unique<RandomFigureFactory>();
	}
	else if (type == "stream")
	{
		if (!in)
		{
			throw std::invalid_argument("StreamFactory requires an input stream");
		}

		return std::make_unique<StreamFigureFactory>(*in);
	}
	else
	{
		throw std::invalid_argument("Factory type is not supported");
	}
}