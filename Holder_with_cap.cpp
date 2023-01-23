#include "Holder_with_cap.hpp"
#include <vector>
#include <sstream>

    void Holder_with_Cap::balance(double temp) {
        temperature = temp;
        set_pressure(atmosphere_pressure + (cap.get_mass() * g / cap.get_area()));
        set_volume(sum_substance_amount * R * temperature / pressure);
    }

Holder_with_Cap::Holder_with_Cap(): Holder() {}
Holder_with_Cap::Holder_with_Cap(double vol, Cap cap) : Holder(vol), cap(cap) {}
    void Holder_with_Cap::set_volume(double new_volume) {
        volume = new_volume;
    }
    void Holder_with_Cap::set_pressure(double press) {
        pressure = press;
    }
    void Holder_with_Cap::work() {
    AddMoreGas:
        cout << "Enter a gas" << endl;
        Gas gas;
        gas.set_gas();
        add_gas(gas);
        cout << "Do you want to add a gas? (Y/N)" << endl;
        char e;
    Wrong2:
        cin >> e;
        if (e == 'Y') {
            goto AddMoreGas;
        }
        else if (e == 'N') {
            count_temperature();
        }
        else {
            cout << "Please choose one option" << endl;
            goto Wrong2;
        }
    }
    void Holder_with_Cap::count_temperature() {
    CountTemperaturesCap:
        cout << "Enter temperature of holder" << endl;
        double temp;
        cin >> temp;
        balance(temp);
        print_holder();
        cout << "Do you want to calculate for other temperatures? (Y/N)" << endl;
        char e;
    Wrong1:
        cin >> e;
        if (e == 'Y') {
            goto CountTemperaturesCap;
        }
        else if (e == 'N') {

        }
        else {
            cout << "Please choose one option" << endl;
            goto Wrong1;
        }
    }