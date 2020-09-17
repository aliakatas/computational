#include <iostream>

int main() {
	std::cout << "\n  This is a dummy project to act as parent to the library.\n";

	std::cout << "  To review and test the functions, please run the appropriate test projects. \n";
	std::cout << " --------------------------------------------------- \n";
	std::cout << "       Build info --> \n";
	std::cout << "              Date :: " << __DATE__ << "\n";
	std::cout << "              Time :: " << __TIME__ << "\n";
	std::cout << "  Compiler Version :: " << _MSC_VER << "\n";
	std::cout << " Language Standard :: " << _MSVC_LANG << "\n";
	std::cout << " --------------------------------------------------- \n";

	std::cout << "  Finished.\n";
}

