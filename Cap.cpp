#include "Cap.hpp"


Cap::Cap(double mass, double area): mass(mass), area(area) {}

Cap::Cap() = default;

double Cap::get_mass() const {
    return mass;
}
double Cap::get_area() const {
    return area;
}
void Cap::set_area(double new_area) {
    area = new_area;
}