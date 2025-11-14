#include "StreamFigureFactory.h"

StreamFigureFactory::StreamFigureFactory(std::istream& in) : in(in) {}

std::unique_ptr<Figure> StreamFigureFactory::create() {
	std::string line;

    if (!std::getline(in, line)) {
        throw std::runtime_error("Cannot read more lines from stream");
    }

    return converter.createFigureFrom(line);
}