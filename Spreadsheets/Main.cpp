#include <iostream>

#include "SpreadsheetCell.h"

int main() {
	SpreadsheetCell cell{25};
	std::cout << cell.GetValue() << std::endl;

	cell.SetString("235.45");
	std::cout << cell.GetString() << std::endl;
}
