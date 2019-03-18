#include "App.h"
#include <iostream>
using namespace std;
#include <string>

int main()
{
	std::cout << "Luke icin 1'e, Yoda icin 2'ye basiniz.....";
	int choose;
	cin >> choose;

	App app("Default Window", 830, 600,choose);
	app.run();

	return 0;
}