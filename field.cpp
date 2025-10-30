#include "field.h"

//Base Class
Field::Field() {
    value = new double[3]{0.0, 0.0, 0.0};
}
Field::Field(double x, double y, double z) {
    value = new double[3]{x, y, z};
}
Field::Field(const Field &other) {
    value = new double[3];
    for (int i = 0; i < 3; ++i)
        value[i] = other.value[i];
}
Field::~Field() {
    delete[] value;
}
void Field::printMagnitude() const {
    std::cout << "(" << value[0] << ", " << value[1] << ", " << value[2] << ")" << std::endl;
}
void Field::setComponents(double x, double y, double z) {
    value[0] = x; value[1] = y; value[2] = z;
}
double Field::getX() const { return value[0]; }
double Field::getY() const { return value[1]; }
double Field::getZ() const { return value[2]; }

//Electric Field
Electric_Field::Electric_Field() : Field(), calculatedE(0.0) {}
Electric_Field::Electric_Field(double x, double y, double z)
    : Field(x, y, z), calculatedE(0.0) {}
Electric_Field::Electric_Field(const Electric_Field &other)
    : Field(other), calculatedE(other.calculatedE) {}

void Electric_Field::calculateField(double Q, double r) {
    calculatedE = Q / (4 * M_PI * pow(r, 2) * EPSILON_0);
    std::cout << "Calculated Electric Field: " << calculatedE << " N/C" << std::endl;
}
Electric_Field operator+(const Electric_Field &a, const Electric_Field &b) {
    return Electric_Field(a.getX() + b.getX(),
                          a.getY() + b.getY(),
                          a.getZ() + b.getZ());
}
std::ostream &operator<<(std::ostream &os, const Electric_Field &e) {
    os << "Electric Field Components: ("
       << e.getX() << ", " << e.getY() << ", " << e.getZ() << ")";
    return os;
}

//Magnetic Field
Magnetic_Field::Magnetic_Field() : Field(), calculatedB(0.0) {}
Magnetic_Field::Magnetic_Field(double x, double y, double z)
    : Field(x, y, z), calculatedB(0.0) {}
Magnetic_Field::Magnetic_Field(const Magnetic_Field &other)
    : Field(other), calculatedB(other.calculatedB) {}

void Magnetic_Field::calculateField(double I, double r) {
    calculatedB = (MU_0 * I) / (2 * M_PI * r);
    std::cout << "Calculated Magnetic Field: " << calculatedB << " T" << std::endl;
}
Magnetic_Field operator+(const Magnetic_Field &a, const Magnetic_Field &b) {
    return Magnetic_Field(a.getX() + b.getX(),
                          a.getY() + b.getY(),
                          a.getZ() + b.getZ());
}
std::ostream &operator<<(std::ostream &os, const Magnetic_Field &b) {
    os << "Magnetic Field Components: ("
       << b.getX() << ", " << b.getY() << ", " << b.getZ() << ")";
    return os;
}

