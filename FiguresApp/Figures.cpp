#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include "FigureFactorySelector.h"
#include "FigureOperations.h"
#include "RegisterFigures.h"

using namespace std;

int main()
{
	srand(time(NULL));
	registerAllFigures();

	unique_ptr<FigureFactory> factory;
	unique_ptr<ifstream> stream = nullptr;

	try
	{
		cout << "Please choose your desired input method (random, console, file)" << endl;
		string input;
		cin >> input;

		if (input == "file")
		{
			cout << "Enter file name: ";
			string file;
			cin >> file;
			cin.ignore();

			stream = make_unique<ifstream>(file);

			if (!stream->is_open()) {
				throw runtime_error("Failed to open file");
			}

			factory = FigureFactorySelector::createFactory(input, stream.get());
		}
		else
		{
			factory = FigureFactorySelector::createFactory(input);
		}

		cout << "Enter how many figures you want to read" << endl;
		int n;
		cin >> n;
		cin.ignore();

		vector<unique_ptr<Figure>> figures;

		for (size_t i = 0; i < n; i++)
		{
			figures.push_back(factory->create());
		}

		while (true)
		{
			cout << endl << "--- MENU ---" << endl;
			cout << "1. List figures" << endl;
			cout << "2. Clone a figure" << endl;
			cout << "3. Delete a figure" << endl;
			cout << "4. Save figures to file" << endl;
			cout << "5. Exit" << endl;
			cout << "Choose option: " << endl;

			int choice;
			cin >> choice;

			if (choice == 1)
			{
				printFigures(figures, cout);
			}
			else if (choice == 2)
			{
				cloneFigure(figures);
			}
			else if (choice == 3)
			{
				deleteFigure(figures);
			}
			else if (choice == 4)
			{
				cout << "Enter output file name: " << endl;
				string file;
				cin >> file;

				ofstream out(file);

				if (!out.is_open())
				{
					throw runtime_error("Failed to open file");
				}

				printFigures(figures, out);

				out.close();
			}
			else if (choice == 5)
			{
				return 0;
			}
			else
			{
				throw invalid_argument("Invalid choice");
			}
		}
	}
	catch (const invalid_argument& e) {
		cout << e.what();
		return 1;
	}
	catch (const overflow_error& e) {
		cout << e.what();
		return 1;
	}
	catch (const runtime_error& e) {
		cout << e.what();
		return 1;
	}
	catch (const exception& e)
	{
		cout << e.what();
		return 1;
	}
}