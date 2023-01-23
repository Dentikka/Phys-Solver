#include "Gas.hpp"
#include <string>
#include <sstream>
#include <iostream>
#include <utility>

using std::endl, std::cin, std::cout, std::istringstream;


Gas::Gas() = default;
Gas::Gas(string  name) : name(std::move(name)) {}
void Gas::set_temperature(double temp) {
    temperature = temp;
}
double Gas::get_temperature() const {
    return temperature;
}
double Gas::get_substance_amount() const {
    return substance_amount;
}
double Gas::get_freedom_degrees() const {
    return freedom_degrees;
}
double Gas::get_mass() const {
    return mass;
}
double Gas::get_molar_mass() const {
    return molar_mass;
}
void Gas::print_gas() const {
    cout << "Gas:" << endl;
    cout << " ---------------------------------------------------------------------------------------------------- "
        << endl;
    cout << "| mass (m";
    if (mass != -1) {
        cout << " = " << mass << " g";
    }
    cout << ") | molar mass (M";
    if (molar_mass != -1) {
        cout << " = " << molar_mass << " g/mole";
    }
    cout << ") | freedom degrees (i";
    if (freedom_degrees != -1) {
        cout << " = " << freedom_degrees;
    }
    cout << ") | substance amount (nu";
    if (substance_amount != -1) {
        cout << " = " << substance_amount << " mole";
    }
    cout << ") | temperature (T";
    if (temperature != -1) {
        cout << " = " << temperature << " K";
    }
    cout << ") |" << endl;
    cout << " ---------------------------------------------------------------------------------------------------- "
        << endl;
}
bool Gas::is_allowed() const {
    if ((mass != -1) and (molar_mass != -1) and (substance_amount != -1) and (mass / molar_mass != substance_amount)) {
        return false;
    }
    else {
        return true;
    }
}
void Gas::calculate() {
    if ((mass != -1) and (substance_amount != -1)) {
        molar_mass = mass / substance_amount;
    }
    else if ((mass != -1) and (molar_mass != -1)) {
        substance_amount = mass / molar_mass;
    }
    else if ((molar_mass != -1) and (substance_amount != -1)) {
        mass = molar_mass * substance_amount;
    }
}

template <typename T>
void Gas::set_parameter(T& parameter) {
    if (parameter == -1) {
        cout << "Enter the parameter in correct measure: " << endl;
        cout << "[m] = g, [M] = g/mole, [i] = 1, [nu] = mole, [T] = K" << endl;
        T x;
        string garbage;
    Error4:
        cin >> garbage;
        for (char cur_c : garbage) {
            if (!((cur_c >= 48) and (cur_c <= 57)) and (cur_c != 46)) {
                cout << "Wrong value. Please, enter a figure" << endl;
                goto Error4;
            }
        }
        istringstream(garbage) >> x;
        if (x <= 0) {
            cout << "Wrong value, please, enter another one (> 0)" << endl;
            goto Error4;
        }
        else if (!is_allowed()) {
            cout << "This parameter conflicts with other parameters!" << endl;
        }
        parameter = x;
        calculate();
    }
    else {
        cout << "This parameter has been already set with value " << parameter << ". Do you want to reset gas? (Y/N)" << endl;
        char c;
    Error:
        cin >> c;
        if (c == 'Y') {
            clear_gas();
            set_gas();
        }
        else if (c == 'N') {
            cout << "Parameter will not be set" << endl;
        }
        else {
            cout << "Please choose one option" << endl;
            goto Error;
        }
    }
}

void Gas::set_gas() {
    print_gas();
    cout << "Choose a parameter to set" << endl;
    string a;
Error3:
    cin >> a;
    if (a == "m") {
        set_parameter(mass);
    }
    else if (a == "M") {
        set_parameter(molar_mass);
    }
    else if (a == "i") {
        set_parameter(freedom_degrees);
    }
    else if (a == "nu") {
        set_parameter(substance_amount);
    }
    else if (a == "T") {
        set_parameter(temperature);
    }
    else {
        cout << "Please choose one option" << endl;
        goto Error3;
    }
    cout << "Do you want to enter another parameter? (Y/N)" << endl;
    char c;
Error2:
    cin >> c;
    if (c == 'Y') {
        set_gas();
    }
    else if (c == 'N') {
        cout << "Your ";
        print_gas();
    }
    else if (c != 'N') {
        cout << "Please choose one option" << endl;
        goto Error2;
    }
}
void Gas::clear_gas() {
    freedom_degrees = -1;
    molar_mass = -1;
    mass = -1;
    substance_amount = -1;
    temperature = -1;
}