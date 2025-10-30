#include "field.h"
#include <iostream>

int main() {
    Electric_Field E1(1e3, 2e3, 3e3);
    Magnetic_Field B1(5, 10, 15);

    E1.printMagnitude();
    B1.printMagnitude();

    E1.calculateField(2e-6, 0.5);
    B1.calculateField(3.0, 0.1);

    Electric_Field E2(100, 200, 300);
    Electric_Field E3 = E1 + E2;

    Magnetic_Field B2(2, 4, 6);
    Magnetic_Field B3 = B1 + B2;

    std::cout << E3 << std::endl;
    std::cout << B3 << std::endl;

		return 0;
}
