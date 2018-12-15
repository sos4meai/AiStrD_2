#include <iostream>
#include <iomanip>
#include "List.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	List listA, listB;
	listA.input_list(); listB.input_list();
	system("cls");
	listA.print_to_console(); listB.print_to_console();
	size_t result = listA.find_first(&listB);
	if (result!=listA.get_size()) std::cout << "Первое вхождение: " << result << '\n';
	else std::cout << "Не входит\n";
	listA.clear(); listB.clear();
	system("pause");
	return 0;
}
