#include "FigureOperations.h"

void printFigures(const std::vector<std::unique_ptr<Figure>>& figures, std::ostream& out)
{
	if (figures.empty()) {
		std::cout << "No figures loaded" << std::endl;
		return;
	}

	for (int i = 0; i < figures.size(); i++) {
		out << figures[i]->toString() << "\n";
	}
}

void cloneFigure(std::vector<std::unique_ptr<Figure>>& figures) {
	std::cout << "Enter index of figure to clone: ";
	int idx;
	std::cin >> idx;

	if (idx < 0 || idx >= figures.size()) {
		throw std::out_of_range("Index is out of bounds");
	}

	figures.push_back(figures[idx]->clone());

	std::cout << "Figure cloned and added at the end" << std::endl;
}

void deleteFigure(std::vector<std::unique_ptr<Figure>>& figures)
{
	std::cout << "Enter index of figure to delete: ";
	int idx;
	std::cin >> idx;

	if (idx < 0 || idx >= figures.size()) {
		throw std::out_of_range("Index is out of bounds");
	}

	figures.erase(figures.begin() + idx);

	std::cout << "Figure deleted" << std::endl;
}