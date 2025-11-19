#include "FigureRegistry.h"

FigureRegistry& FigureRegistry::getInstance() {
	static FigureRegistry instance;
	return instance;
}

void FigureRegistry::registerType(const std::string& name, CreatorFunc creator) {
	creators[name] = creator;
}

std::unique_ptr<Figure> FigureRegistry::create(const std::string& name, std::istream& in) {
	auto iterator = creators.find(name);

	if (iterator == creators.end())
	{
		throw std::invalid_argument("Unknown figure type");
	}

	return iterator->second(in);
}