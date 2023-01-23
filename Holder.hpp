#pragma once

#include "Gas.hpp"

#define HOLDER_INCLUDED 1

#include <vector>
#include <iostream>


using std::cin, std::cout, std::endl, std::string, std::vector;


class Holder {
protected:
    double volume = -1;
    double pressure = -1;
    double temperature = -1;
    vector<Gas> gases;
    double sum_mass = 0;
    double sum_substance_amount = 0;
    double mean_freedom_degrees = 0;
    void merge();
public:
    Holder();
    explicit Holder(double volume, vector<Gas> gases);
    explicit Holder(double volume);
    bool is_empty();
    void add_gas(const Gas& gas);
    void print_holder() const;
    double get_volume() const;
    double get_pressure() const;
    double get_temperature() const;
    auto get_gases() const;
    double get_sum_substance_amount() const;
    double get_mean_freedom_degrees() const;
    void set_temperature(double temp);
};