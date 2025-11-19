#pragma once

#include <memory>
#include <iostream>
#include <unordered_map>
#include <functional>
#include <string>
#include "Figure.h"

class FigureRegistry {
public:
	using CreatorFunc = std::function<std::unique_ptr<Figure>(std::istream&)>;

private:
	std::unordered_map<std::string, CreatorFunc> creators;
	FigureRegistry() = default;

public:
	static FigureRegistry& getInstance();

	void registerType(const std::string& name, CreatorFunc creator);

	std::unique_ptr<Figure> create(const std::string& name, std::istream& in);
};