#include "Holder.hpp"
#include <vector>
#include <sstream>

using std::vector;

void Holder::merge() {
    if(!is_empty()) {
        double sum_freedom_degrees = 0;
        sum_substance_amount = 0;
        sum_mass = 0;
        double temp = 0;
        for (const auto& cur: gases) {
            temp += cur.get_temperature() * cur.get_freedom_degrees();
            sum_freedom_degrees += cur.get_freedom_degrees();
            sum_substance_amount += cur.get_substance_amount();
            sum_mass += cur.get_mass();
        }
        temperature = temp / sum_freedom_degrees;
        pressure = sum_substance_amount * temperature / volume;
        mean_freedom_degrees = sum_freedom_degrees / gases.size();
        for (auto& cur: gases) {
            cur.set_temperature(temperature);
        }
    }
}

Holder::Holder() = default;
Holder::Holder(double volume, vector<Gas> gases): volume(volume), gases(std::move(gases)) {
    merge();
}
Holder::Holder(double volume): volume(volume) {}
bool Holder::is_empty() {
    return gases.empty();
}
void Holder::add_gas(const Gas& gas) {
    gases.push_back(gas);
    merge();
}
void Holder::print_holder() const {
    cout << "Holder: " << endl;
    cout << " ---------------------------------------------------------------------------------------------------- "
            << endl;
    cout << "| mass (m";
    if (sum_mass != -1) {
        cout << " = " << sum_mass << " g";
    }
    cout << ") | mean_freedom degrees (i";
    if (mean_freedom_degrees != -1) {
        cout << " = " << mean_freedom_degrees;
    }
    cout << ") | substance amount (nu";
    if (sum_substance_amount != -1) {
        cout << " = " << sum_substance_amount << " mole";
    }
    cout << ") | temperature (T";
    if (temperature != -1) {
        cout << " = " << temperature << " K";
    }
    cout << ") | volume (V = " << volume << "m^3) |" << endl;
    cout << " ---------------------------------------------------------------------------------------------------- "
            << endl;
}
double Holder::get_volume() const {
    return volume;
}
double Holder::get_pressure() const {
    return pressure;
}
double Holder::get_temperature() const {
    return temperature;
}
auto Holder::get_gases() const {
    return gases;
}
double Holder::get_sum_substance_amount() const {
    return sum_substance_amount;
}
double Holder::get_mean_freedom_degrees() const {
    return mean_freedom_degrees;
}
void Holder::set_temperature(double temp) {
    temperature = temp;
    for (auto & cur: gases) {
        cur.set_temperature(temp);
    }
}
