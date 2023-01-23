#pragma once

#define CAP_INCLUDED 1

class Cap {
protected:
    double mass = -1;
    double area = -1;
public:
    Cap(double mass, double area);

    Cap();

    double get_mass() const;
    double get_area() const;
    void set_area(double new_area);
};