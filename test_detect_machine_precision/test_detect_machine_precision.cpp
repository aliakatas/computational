#include "detect_machine_precision.h"
#include <iostream>

int main() {
	std::cout << "\n  Testing \"detect_machine_precision\" -->\n";
	std::cout << "   Float :: " << get_machine_precision_float() << "\n";
	std::cout << "  Double :: " << get_machine_precision_double() << "\n";
	std::cout << "  <-- Done. \n";
}
