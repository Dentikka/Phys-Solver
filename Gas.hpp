#pragma once

#include <string>

using std::string;

const double R = 8.314;
const double g = 9.81/1000;
double atmosphere_pressure = 101325;


class Gas {
protected:
    string name = "Unknown";
    int freedom_degrees = -1;
    double molar_mass = -1;
    double mass = -1;
    double substance_amount = -1;
    double temperature = -1;
public:
    Gas();
    Gas(string  name);
    void set_temperature(double temp);
    double get_temperature() const;
    double get_substance_amount() const;
    double get_freedom_degrees() const;
    double get_mass() const;
    double get_molar_mass() const;
    void print_gas() const;
    bool is_allowed() const;
    void calculate();

    template <typename T>
    void set_parameter(T& parameter);

    void set_gas();
    void clear_gas();
};