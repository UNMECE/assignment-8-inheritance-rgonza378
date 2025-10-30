#ifndef FIELD_H
#define FIELD_H

#include <iostream>
#include <cmath>

const double EPSILON_0 = 8.854e-12;   // permittivity of free space
const double MU_0 = 4 * M_PI * 1e-7;  // permeability of free space

//Base Class
class Field {
protected:
    double *value;

public:
    Field();                                  // default constructor
    Field(double x, double y, double z);      // vector constructor
    Field(const Field &other);                // copy constructor
    virtual ~Field();                         // destructor

    virtual void printMagnitude() const;      // print components

    void setComponents(double x, double y, double z);
    double getX() const;
    double getY() const;
    double getZ() const;
};

//Derived Electric Field
class Electric_Field : public Field {
private:
    double calculatedE;

public:
    Electric_Field();
    Electric_Field(double x, double y, double z);
    Electric_Field(const Electric_Field &other);

    void calculateField(double Q, double r);

    friend Electric_Field operator+(const Electric_Field &a, const Electric_Field &b);
    friend std::ostream &operator<<(std::ostream &os, const Electric_Field &e);
};

//Derived Magnetic Field
class Magnetic_Field : public Field {
private:
    double calculatedB;

public:
    Magnetic_Field();
    Magnetic_Field(double x, double y, double z);
    Magnetic_Field(const Magnetic_Field &other);

    void calculateField(double I, double r);

    friend Magnetic_Field operator+(const Magnetic_Field &a, const Magnetic_Field &b);
    friend std::ostream &operator<<(std::ostream &os, const Magnetic_Field &b);
};

#endif

